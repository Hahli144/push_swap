# push_swap - Sorting data with minimal moves.

The aim of this project was to sort data on a stack, with a limited set of instructions, with as few moves as possible.
To make this happen, several different algorithms needed to be tested to choose the most appropriate solutions for optimal sorting.

## How to use:
Compile the project

  ```
make
  ```
  
The result is two binary files, checker and push_swap.

### Checker
  ```
./checker [-v] [args ...]
  ``` 
Checker takes integers as an argument.

The optional ```-v``` flag enables debug mode, which prints both stacks after each operation.

On execution, checker will wait for instructions on the standard input. Valid instructions are:
```
sa - swap the first 2 elements at the top of stack a

sb - swap the first 2 elements at the top of stack b

ss - sa and sb at the same time

pa - take the first element at the top of b and put it at the top of a

pb - take the first element at the top of a and put it at the top of b

ra - shift up all elements of stack a by 1

rb - shift up all elements of stack b by 1

rr - ra and rb at the same time

rra - shift down all elements of stack a by 1

rrb - shift down all elements of stack b by 1

rrr - rra and rrb at the same time
```
