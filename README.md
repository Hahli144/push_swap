# push_swap - Sorting data with minimal moves.

The aim of this project was to sort data on a stack, with a limited set of instructions, with as few moves as possible.
To make this happen, several different algorithms needed to be tested to choose the most appropriate solutions for optimal sorting.

With <= 3 digits, amount of moves is <= 2.  
With <= 5 digits, amount of moves is <= 11  
With <= 100 digits, amount of moves < 900, average around ~750.  
With <= 500 digits, amount of moves is < 8000, average around ~7300.  
# Checker
  ```
./checker [-v] [args ...]
  ``` 
Checker takes integers as arguments. On execution, checker will wait for instructions on the standard input. When reading is stopped, checker will print "OK" if the instructions result in a sorted array, and "KO" if not.

The optional ```-v``` flag enables debug mode, which prints both stacks after each operation.

 Valid instructions for checker are:
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
Anything else will result in an error, stopping the program.

# Push_swap
  ```
./push_swap [-v] [args ...]
  ``` 
Push_swap takes integers as arguments. On execution, push_swap will sort the given integers into ascending order, using valid moves, and print each move on the standard output.

The optional ```-v``` flag enables debug mode, which allows the process to be examined step by step. Push_swap will pause after each stack move, and continue step by step when any input is read.

## How does it work?

Different methods were used depending on the amount of arguments.
