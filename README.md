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

## 3 arguments or less
1. The largest integer is found, and rotated to the bottom of the stack.  
  This can always be done with a single move, either ```ra``` or ```rra```. The largest digit is now sorted. 
2. The digits above are either in the correct place, or need to be swapped with ```sa```.

The stack is now sorted.

## 5 arguments or less
1. The largest integer is found, rotated to the top with either ```ra``` or ```rra```, then pushed to stack b.
2. The smallest integer is found, rotated to the top with either ```ra``` or ```rra```, then pushed to stack b.
3. Stack a is sorted with the "3 arguments or less" algorithm.
4. Both digits are pushed from stack b to stack a.
5. Stack a is rotated once with ```ra``` to push the largest integer to the bottom.

The stack is now sorted.

## 100 arguments or less

1. Integers are divided into 5 groups by size.  
  Group 1 containing the smallest integers and group 5 containing the largest integers.
2. Integers from the first group are pushed into stack b.
    d
