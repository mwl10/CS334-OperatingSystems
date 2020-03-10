# CS334-OperatingSystems Course Labs and Assignments

## Threading Lab

In this lab you will get practice with locks, condition variables, and the pthread library by writing two multi-threaded programs.

  For problem 1 we model a subway station using threads, by writing synchronization functions that guarantee an orderly     loading of trains. Each passenger and each train is controlled by a thread.
  
   For problem 2 we have been hired by Mother Nature to help her out with the chemical reaction to form water, which she doesn’t seem to be able to get right due to synchronization problems. The trick is to get two H atoms and one O atom together at the same time. Each atom is represented by a thread.
   
## Linux Utilities Lab 
  
In this project, you’ll build a few different Linux utilities, simple versions of commonly used commands like cat and grep. We’ll call each of them a slightly different name to avoid confusion (my-cat, my-grep). The next tools you will build come in a pair, because one (my-zip) is a file compression tool, and the other (my-unzip) is a file decompression tool.

The type of compression used here is a simple form of compression called run-length encoding (RLE). RLE is quite simple: when you encounter n characters of the same type in a row, the compression tool (vzip) will turn that into the number n and a single instance of the character.
 
