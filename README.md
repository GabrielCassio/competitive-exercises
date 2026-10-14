# competitive-exercises

## Configuração base do C++ no Windows, Arch Linux e Docker

O fluxo recomendado é executar o toolchain dentro do Docker. Consulte
[`.vscode/README.md`](.vscode/README.md) para as instruções completas de
Docker, Dev Containers e execução direta no host:

- Arch Linux: instalação com `pacman`.
- Windows: instalação do MSYS2 UCRT64 e configuração do `PATH`.
- Docker: imagens baseadas em Debian/GCC com C++23, CMake e GDB.

Abra a raiz do repositório no VS Code:

```bash
code .
```

O diretório `.vscode` fornece:

- `C++: compilar arquivo ativo`: compila o arquivo aberto com C++23, warnings e símbolos de debug.
- `Debug arquivo C++ ativo`: compila e inicia o arquivo aberto no GDB.
- `CMake: configurar`, `CMake: compilar` e `CMake: testar`: configuram e executam o projeto de testes.

Para o fluxo com CMake pela linha de comando dentro do container:

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build --parallel
ctest --test-dir build --output-on-failure
```
