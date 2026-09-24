# Como compilar e testar uma nova questão no container

Este guia explica o passo a passo para adicionar uma nova questão de entrevista ao repositório e compilá-la dentro do container Docker com GTest.

## Estrutura esperada

Cada questão vive em sua própria subpasta dentro de `Interviews/`. Os nomes dos arquivos `.cpp` são livres — não precisam ser exatamente `case.cpp`/`test_case.cpp`:

```
Interviews/
└── nome_da_questao/
    ├── nome_da_questao.hpp     # declaração das funções (opcional, mas recomendado)
    ├── nome_da_questao.cpp     # implementação
    └── nome_da_questao_test.cpp # testes com GTest
```

O `CMakeLists.txt` varre todos os arquivos `.cpp` de cada subpasta de `Interviews/` e separa automaticamente pelo **nome do arquivo**:

- Qualquer `.cpp` cujo nome contenha a palavra `test` (ex.: `test_case.cpp`, `case_test.cpp`, `nome_da_questao_test.cpp`) é tratado como **arquivo de teste**.
- Todo o restante é tratado como **arquivo de implementação**.

Um executável de teste (`nome_da_questao_tests`) só é criado se a pasta tiver **pelo menos um** arquivo de teste. Arquivos de implementação são opcionais — uma pasta pode ter só o arquivo de teste, sem `.cpp` de implementação separado, se a lógica estiver toda no próprio teste ou num header-only. Pastas sem nenhum arquivo com "test" no nome são ignoradas silenciosamente (não geram executável nem erro).

> ⚠️ Cuidado: a detecção usa `MATCHES "test"` no nome do arquivo, então qualquer `.cpp` que contenha a subsequência "test" — mesmo que não seja um arquivo de teste de verdade (ex.: `latest_version.cpp`) — seria capturado como teste. Evite esse tipo de nome nos arquivos de implementação.

## 1. Subir o container (primeira vez)

Na raiz do repositório:

```bash
docker build -f Dockerfile.tdd -t tdd-prep .
docker run -it --rm -v "$(pwd)":/app tdd-prep
```

O `-v "$(pwd)":/app` monta o repositório local dentro do container, então qualquer arquivo criado ou editado localmente aparece instantaneamente lá dentro (e vice-versa).

## 2. Criar uma nova questão

Dentro do container (ou localmente, já que o volume é compartilhado):

```bash
mkdir -p Interviews/nova_questao
touch Interviews/nova_questao/nova_questao.hpp
touch Interviews/nova_questao/nova_questao.cpp
touch Interviews/nova_questao/nova_questao_test.cpp
```

Preencha os arquivos com a assinatura da função, a implementação e os testes. Os nomes são livres — o importante é que o arquivo de teste tenha "test" em algum lugar do nome.

## 3. Reconfigurar o CMake

Como o `CMakeLists.txt` usa `file(GLOB ...)` para descobrir as subpastas automaticamente, é necessário rodar o `cmake` de configuração novamente sempre que uma **pasta nova** for criada (não é preciso reconfigurar se você só editar um arquivo já existente):

```bash
cmake -B build
```

## 4. Compilar

```bash
cmake --build build
```

Isso compila **todos** os executáveis de teste (um por subpasta). Para compilar apenas o alvo da questão nova (mais rápido):

```bash
cmake --build build --target nova_questao_tests
```

## 5. Rodar os testes

Rodar tudo de uma vez:

```bash
cd build
ctest --output-on-failure
```

Rodar apenas a questão nova:

```bash
ctest -R nova_questao --output-on-failure
```

Ou executar o binário diretamente (mostra a saída padrão do GTest, útil durante live coding):

```bash
./nova_questao_tests
```

## Fluxo resumido (copiar e colar)

```bash
# 1. cria a pasta e os arquivos
mkdir -p Interviews/nova_questao
touch Interviews/nova_questao/{nova_questao.hpp,nova_questao.cpp,nova_questao_test.cpp}

# 2. edita os arquivos com o enunciado da questão

# 3. reconfigura e compila
cmake -B build && cmake --build build --target nova_questao_tests

# 4. roda os testes
./build/nova_questao_tests
```

## Erros comuns

| Sintoma | Causa provável |
|---|---|
| `CMake Error: does not appear to contain CMakeLists.txt` | Build rodado fora da raiz do repo, ou `CMakeLists.txt` não copiado/montado no container |
| Pasta nova não aparece como alvo de teste | Esqueceu de rodar `cmake -B build` de novo após criar a pasta |
| `undefined reference` ao linkar | `case.cpp` não implementa alguma função declarada em `case.hpp`, ou nome do arquivo não bate com o esperado (`case.cpp`/`test_case.cpp`) |
| `#include "case.hpp"` não encontrado no teste | Header fora da subpasta da questão, ou nome do arquivo diferente de `case.hpp` |