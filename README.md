Avneet Sahi
CMSC 421 - Operating Systems
Project #1
October 8, 2021

1. I have a command promt for the user which keeps running until the user exits. This is all
under one big while loop that keeps running while true.


2.I have an arguments array which stores the commands that user wants executed. This happends
through the use of strtok(). I split the input wherever there is a space and place it into the
arguments array.


3. Not sure if I did this right. But I have multiple statements checking the input to see what
the command is and whether it will get passed into execvp() to execute.


4. Again, same as number 3. these checks prevent and make sure the correct command is executed
and gone in the right direction.


5. My shell keeps prompting until the user's command is exit. Otherwise it will keep prompting.
I did this through while loops, if statements, and using the exit(0) function.