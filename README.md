# Brainfuck Interpreter
Just a Simple Brainfuck Interpreter written in C++ in an evening with help from some sources. You've probably seen a few of these.

### The Language
What even is Brainfuck and why am i cursing so much ?

Well unfortunately.. The thing is, Brainfuck is actually the name of the Language. Therefore, its kind of impossible not to swear to some extent. Anyways **what even is brainfuck ?**

Brainfuck is actually a Turing Complete Programming Language. What that means is that It can "calculate anything". Being able to "calculate anything" does not necessarily mean you will get access to many of the features you've gotten used to over the years of your programming career, this is because the language only provides you **8** symbols to work with. 

You can maybe think of it as like assembly. Assembly doesn't have If statements, or Loops like any other language (like C, Java, Python etc) but you can simulate If statements and Loops using the instructions that Assembly language (Specficially the one you're using) has.
But even the most basic of Assembly Languages often have a lot more instructions than just **8** and those instructions often require parameters to work.

Brainfuck on the other hand, only has **8** possible instructions. And those instructions don't require any sort of parameters or values to be given to them.

#### Memory in Brainfuck
The "memory" in Brainfuck works like a Tape of Cells. Each Cell has its own address that starts from 0 and goes to Infinity.
```0 = First Cell of Memory
1 = Second Cell of Memory
.
.
.
.
.
N = (N + 1) Cell of Memory
```
Each Cell holds 1 Byte of Data (Minimum value is 0, and Maximum value is 255)

Attempting to Increment by 1 when the value is 255 will reset the value to 0.
Similarly, Decrementing by 1 when the value is 0 will shift the value to 255.

#### Symbols
```
> : Shift Memory Position to the Next (Right) Cell.
< : Shift Memory Position to the Prev (Left) Cell (Less than 0 will result in an Error).

+ : Increment The Value in the Current Memory Address.
- : Decrement The Value in the Current Memory Address.

. : Output - Print The Value in Current Memory Address as an ASCII Character (72 = H)
, : Input - Store the Character Code of the Input given in the Console.

[ : Comparison - If The Value in Current Memory Address is 0, then we will execute the instructions within. Else Skip Over.
] : Comparison and Looping - If the Current Value is Non-Zero ( x > 0 ), then we will loop to the corresponding "[" else we will continue.
```

Those are the 8 Instructions which Brainfuck has. And you can actually write actual programs using this.

People have written a lot of brainfuck interpreters, this is just one of them. But some people have written Brainfuck Interpreters using Brainfuck, and thats a form of Masochism I hope I'm never attracted to.
