*Este proyecto ha sido creado como parte del currículo de 42 por durisosa.*
![License](https://img.shields.io/badge/license-MIT-blue)
![Version](https://img.shields.io/badge/version-1.0.0-green)   
![GitHub stars](https://img.shields.io/github/stars/dmsosa/REPO?style=social)

# Contributions from each member

Update for June 29th, as passing the s_pushswap struct to each function was too much work, it was removed and the struct s_stack is now added more members. All of this was necessary to count the total number of moves and store other data.

# Description.

//how to parse the args? or me the most straightforward and simple solution is
//to take the args, split if necessary, if not, just traverse each arg and convert to nbr with atol
//if there is a syntax error, throw error.



# Instructions

1. Clone the repo with `git clone`;
2. This project has no Makefile, so only compiling the main will make you able to test it.
3. Copy this command to compile the mandatory part `gcc -Wall -Wextra -Werror -Wl,--wrap=malloc -g get_next_line.c get_next_line_utils.c main.c -o a.out`
4. Copy this command to compile the bonus `gcc -Wall -Wextra -Werror -Wl,--wrap=malloc -g get_next_line_bonus.c get_next_line_utils_bonus.c main.c -o a.out`
5. Execute the binary ./a.out

# Resources

The Manual ('man' command) of the Unix operating system, Google and Stack Overflow questions were used as the main sources of information.

Other support materials have been the GitHub repositories of other cursus students.

Students that inspired me a lot:

[youssef-be](https://github.com/youssef-benchaaboun)
[jdecorte-be](https://github.com/jdecorte-be)
[mcombeau](https://github.com/mcombeau)
[suspectedoceano](https://github.com/suspectedoceano)


## IA Usage:

I used the IA as a support to speed up the following tasks: 

a. Add shields to the README.md.
b. Filter best Stack Overflow answers to my questions
c. Summary information available on the internet
d. Investigating which smaller skills were needed to successfully understand this topic.

## FAQs

As a suggestion, use this valgrind full command to help you during troubleshooting leaks in your program:
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./executable

### Bonus part

Bonus: The bonus consists of compiling a separate main for the checker program. Unlike push_swap, it doesn't print the list of operations. Instead, it reads instructions from standard input and executes them. This allows us to pipe the output of push_swap directly into checker, which will replay the operations and verify whether the stack is correctly sorted.


### Testing

I want to run a test command that is able to compile my mains and run different tests
But why to do that if other people already made a good test, if my solution parses then it should be able to receive simple input from those tests, or to be used as a usable tool, right?

### Why this code pass the stacks by reference from the main function to every other called function?

Because after contemplating possible pros and cons, it was clear enough to work with the address of the stacks themselves rather than their values.

| pros                                                                                                                                                                   | cons                                                                                                                                      |
|------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------|
| Performance: Passing a pointer avoids copying large data structures, as only the fixed-size address (typically 8 bytes on modern architectures) is faster to transfer. | Memory Safety Hazards: Pointers can be NULL or invalid, leading to segmentation faults if not carefully validated before dereferencing    |
| Modification of Original Data: The called function can directly modify the original variable in memory                                                                 | Debugging Complexity: It is harder to track state changes because the variable's value can be altered by any function holding its pointer |
|                                                                                                                                                                        |                                                                                                                                           |

Tables made with [tables generator](https://tablesgenerator.com/markdown_tables#)

### Why you have chosen the algorithms you did?

We had the following options:

Algoritmo simple (O(n
2
)):
Implementa al menos un algoritmo base perteneciente a la clase de complejidad
O(n
2
). Por ejemplo:
• Adaptación del orden por inserción
• Adaptación del orden por selección
• Adaptación del orden burbuja
• Métodos simples de extracción del mínimo/máximo
2. Algoritmo intermedio (O(n
√
n)):
Implementa al menos un algoritmo perteneciente a la clase de complejidad O(n
√
n).
Por ejemplo:
• Orden basado en chunks (dividiendo en √
n chunks)
• Métodos de partición basados en bloques
• Adaptaciones del orden por buckets con √
n buckets
• Estrategias de orden basadas en rangos
3. Algoritmo complejo (O(n log n)):
Implementa al menos un algoritmo perteneciente a la clase de complejidad O(n log n).
Por ejemplo:
• Adaptación del orden radix (LSD o MSD)
• Adaptación del orden por fusión utilizando dos stacks
• Adaptación del orden rápido con partición por stacks
• Adaptación del orden por montículos
• Algoritmos de árbol binario indexado