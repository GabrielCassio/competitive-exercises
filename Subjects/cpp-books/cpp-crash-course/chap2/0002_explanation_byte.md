# Trabalhando com bytes

A priore o tipo std::byte do header <cstddef> vindo de C não permite operações tipo adição, subtração, multipliacação e divisão. O livro contrapõe a estrutura com tipo char, talvez haja como trabalhar com ambos.

### O tipo size_t

O referente tipo armazena o tamanho da estrutura em bytes (2 a 200 dependendo da implementação).
O operador unário sizeof retorna um size_t. Ex.: sizeof(float) -> retorna o tamanho reservado para um float.

