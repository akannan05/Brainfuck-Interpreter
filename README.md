# Brainfuck Interpreter

This is a Brainfuck Interpreter written in C++

## Background

```
++++++++                Set Cell #0 to 8
[
    >++++               Add 4 to Cell #1 (loop cntr)
    [
        >++             Add 2 to Cell #2
        >+++            Add 3 to Cell #3
        >+++            Add 3 to Cell #4
        >+              Add 1 to Cell #5
        <<<<-           Decrement Cell #1 by 1
    ]                   Loop until Cell #1 is 0 (4 iterations)
    >+                  Add 1 to Cell #2
    >+                  Add 1 to Cell #3
    >-                  Subtract 1 from Cell #4
    >>+                 Add 1 to Cell #6
    [<]                 Move back to first 0 Cell (Cell #1)

    <-                  Decrement the Loop Counter 
]                       Loop for 8 iterations
               
>>.                     Cell #2 has value 72, corresponding to 'H' in ASCII 
>---.                   Subtract 3 from Cell #3, to get 101 which is 'e'
+++++++..+++.           While in Cell #3, also print 'llo'
>>.                     At Cell #5, get 32, which is space
<-.                     Subtract 1 from Cell #4 to get 'W'             
<.                      Output 'o' from Cell #3
+++.------.--------.    Output 'rl' and 'd' from Cell #3
>>+.                    Add 1 to Cell #5 to get '!'
>++.                    Output '\n' from Cell #6
```

Code taken from Brainfuck Wikipedia page. Main Takeaways:
- we can use [] to create loops, but we have to manage iterations and counters in the
  initial cells
- important to remember ASCII codes corresponding to byte numbers

## Installation


