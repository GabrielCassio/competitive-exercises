# competitive-exercises

## Configuração base do C++ no Windows e Arch Linux

Os arquivos de configuração do VS Code funcionam nos dois sistemas usando
`g++`, `gdb`, `cmake` e `ctest` encontrados no `PATH`. Consulte
[`.vscode/README.md`](.vscode/README.md) para as instruções de instalação:

- Arch Linux: instalação com `pacman`.
- Windows: instalação do MSYS2 UCRT64 e configuração do `PATH`.

Abra a raiz do repositório no VS Code:

```bash
code .
```

O diretório `.vscode` fornece:

- `C++: compilar arquivo ativo`: compila o arquivo aberto com C++23, warnings e símbolos de debug.
- `Debug arquivo C++ ativo`: compila e inicia o arquivo aberto no GDB.
- `CMake: configurar`, `CMake: compilar` e `CMake: testar`: configuram e executam o projeto de testes.

Para o fluxo com CMake pela linha de comando:

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build --parallel
ctest --test-dir build --output-on-failure
```
