**Get Next Line Project**

![image](https://github.com/user-attachments/assets/eb902d01-43bf-4353-a44a-503de83d3562)

Project developed at the 42 São Paulo school.
This project consists of programming a function that returns a line read from a file descriptor and makes you learn a very interesting new concept in C programming: static variables.

Bonus part:
Files marked with "_bonus" denote an updated version in which it is possible to handle more than one descriptor file.

To compile the program with:
```
cc -Wall -Wextra -Werror -D BUFFER_SIZE=your_chosen_buffer_size <files>.c
Example:
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
Example bonus:
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c main.c
```
Run the compiled program:
```
./your_executable_file
Example:
./a.out
```
______

Este projeto consiste em programar uma função que retorna uma linha lida de um descritor de arquivo e faz com que se aprenda um novo conceito muito interessante na programação em C: as variáveis estáticas.

Parte do bônus:
Os ficheiros marcados com "_bonus" denotam uma versão atualizada na qual é possível lidar com mais de um arquivo descritor.

Para compilar o programa:
```
cc -Wall -Wextra -Werror -D BUFFER_SIZE=<tamanho do buffer> <files>.c
Exemplo:
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
Exemplo bônus:
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c main.c
```
Execute o programa compilado:
```
./seu arquivo executável
Exemplo:
./a.out
```
