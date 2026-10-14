# Configuração do VS Code

Esta pasta contém as configurações para desenvolver e executar os exercícios
C++ no Visual Studio Code usando GCC, GDB e CMake. Os comandos são procurados
no `PATH`, portanto a mesma configuração funciona no Windows e no Arch Linux.

## Pré-requisitos

### Arch Linux

Instale o toolchain e as ferramentas com `pacman`:

```bash
sudo pacman -Syu --needed base-devel gcc gdb cmake
```

O pacote `base-devel` fornece ferramentas auxiliares de compilação; `gcc`
instala o `g++`, e `gdb` e `cmake` são usados para depuração e compilação do
projeto.

### Windows

Instale o [MSYS2](https://www.msys2.org/) e abra o terminal **MSYS2 UCRT64**.
Nesse terminal, instale o toolchain:

```bash
pacman -Syu
pacman -S --needed \
  mingw-w64-ucrt-x86_64-gcc \
  mingw-w64-ucrt-x86_64-gdb \
  mingw-w64-ucrt-x86_64-cmake
```

Adicione `C:\msys64\ucrt64\bin` ao `PATH` do Windows e reinicie o VS Code.
Assim, `g++`, `gdb`, `cmake` e `ctest` poderão ser encontrados pelas tarefas.

Também é necessário instalar as extensões recomendadas quando o VS Code
solicitar:

- `ms-vscode.cpptools`
- `ms-vscode.cmake-tools`

Abra a raiz do repositório no VS Code:

```text
code .
```

## Arquivos

### `settings.json`

Define as configurações específicas deste workspace:

- Usa `g++` encontrado no `PATH` como compilador padrão.
- Define C++23 como padrão da linguagem.
- Configura o IntelliSense para GCC (`gcc-x64`) em Linux e Windows.
- Usa a extensão CMake Tools como provedora de configuração do C/C++.
- Define `build/` como diretório de compilação do CMake.
- Configura o CMake para o modo `Debug` e habilita a geração de
  `compile_commands.json`.
- Trata arquivos `.tcc` como arquivos C++.
- Oculta as pastas `build/` e os executáveis com extensão `.out` no Explorer.

### `tasks.json`

Registra tarefas que podem ser executadas pelo menu **Terminal > Executar
Tarefa** ou pela Paleta de Comandos. Os comandos `g++`, `cmake` e `ctest` são
usados sem caminhos absolutos para funcionarem nos dois sistemas.

#### `C++: compilar arquivo ativo`

Compila o arquivo C++ atualmente aberto com C++23, warnings
(`-Wall`, `-Wextra` e `-pedantic`) e símbolos de debug (`-g`). O executável é
criado no mesmo diretório do arquivo-fonte. No Windows, o GCC acrescenta a
extensão `.exe` automaticamente.

Essa é a tarefa de compilação padrão do workspace e usa o problem matcher
`$gcc` para exibir erros e warnings no painel **Problemas**.

#### `CMake: configurar`

Configura o projeto no diretório `build/` em modo `Debug` e habilita
`compile_commands.json`.

#### `CMake: compilar`

Executa `CMake: configurar` primeiro e depois compila o diretório `build/` em
paralelo.

#### `CMake: testar`

Executa `CMake: compilar` primeiro e roda o CTest com
`--output-on-failure`, exibindo a saída dos testes que falharem.

### `launch.json`

Define as configurações de depuração disponíveis na aba **Executar e
Depurar**. Ambas usam o GDB encontrado no `PATH`.

#### `Debug arquivo C++ ativo`

Depura o arquivo C++ aberto no momento. Antes de iniciar o GDB, executa a tarefa
`C++: compilar arquivo ativo`. No Windows, a configuração usa automaticamente o
arquivo executável com extensão `.exe`.

O diretório de trabalho (`cwd`) é o diretório do arquivo-fonte, e o
pretty-printing do GDB é habilitado para facilitar a inspeção de estruturas da
biblioteca padrão.

#### `Debug tests CMake`

Depura o alvo selecionado pelo CMake Tools. O executável é obtido por
`${command:cmake.launchTargetPath}` e o diretório de trabalho é a raiz do
workspace.

Use esta opção para depurar testes ou outros alvos configurados pelo
`CMakeLists.txt`.

### `extensions.json`

Lista as extensões recomendadas para este repositório:

- `ms-vscode.cpptools`: suporte a C++, IntelliSense, compilação e depuração.
- `ms-vscode.cmake-tools`: configuração, compilação e seleção de alvos CMake.

## Fluxos comuns

### Compilar e depurar um arquivo isolado

1. Abra um arquivo `.cpp`.
2. Pressione `F5` ou selecione **Executar e Depurar**.
3. Escolha `Debug arquivo C++ ativo`.

O VS Code executará automaticamente a tarefa de compilação antes de iniciar a
depuração.

### Compilar e testar com CMake

Execute a tarefa `CMake: testar`. Ela configura o projeto, compila os alvos e
executa os testes.

O mesmo fluxo pode ser executado no terminal, tanto no Arch Linux quanto no
MSYS2 UCRT64:

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build --parallel
ctest --test-dir build --output-on-failure
```
