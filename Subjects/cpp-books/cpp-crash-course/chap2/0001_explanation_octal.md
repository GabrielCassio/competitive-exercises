## Uma breve explicação sobre octais em c++

C++ assim como C herdam a tradição dúbia do prefixo octal da linguagem B. Ou seja, ao declarar inteiros eliminar zeros no início é tarefa obrigatória, caso contrário:  

``` Plaintext
int mit_zip_code = 02139; // Won't compile
```

O caso acima não irá compilar pela combinação de prefixo octal e existência do algarismo 9 que foje do range da base octal.