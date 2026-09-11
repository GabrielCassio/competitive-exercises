# O que são c-strings?

C-strings ou null-terminated são blocos contínuos de caracteres (array de caracteres) que possuem um zero-byte adicionado no final para indicar o seu fim.


# String literals

Texto entre aspas duplas. Elas suportam Unicode

char english[] = "A book holds a house of gold.";
char16_t chinese[] = u"\u4e66\u4e2d\u81ea\u6709\u9ec4\u91d1\u5c4b"