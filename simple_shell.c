#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include "utils.h"

// the file you are going to write your user input in

int main() {
  
  int BUFFER_SIZE = 250; // constant for size of input
  int counter = 0; // how many characters in argument
  int args_counter = 0; // how many arguments in array

  // initialization of array of user input
  char *user_input = NULL;
  user_input = (char*)malloc(BUFFER_SIZE * sizeof(char) );

  // take input and put into sep array to pass into exec()
  char** args = NULL;
  args = (char**)malloc(BUFFER_SIZE * sizeof(char) );

  // split up char array at spaces
  char* token = NULL;
 
  // while user does not enter 'exit' keep prompting
  while (1) {
    printf("$ " );

    // read in user input and put into 1D array
    int index = 0;
    int i = 0;

    while((index = fgetc(stdin)) != '\n') {
      user_input[i] = index;
      counter++;
      i++;
    }
    

    token = strtok(user_input, " ");
    
    int j = 0;
    while (token != NULL) {
      args[j] = token;
      token = strtok(NULL, " "); 
      j++;
      args_counter++;
    }
        
    
    // if command exit, exit process
    if (strcmp(args[0], "exit") == 0){  
      
      // free memory for user_input
      free(user_input);
      user_input = NULL;
      
      // free memory for args
      free(args);
      args = NULL;
      
      // free token
      free(token);
      token = NULL;
      
      exit(0);
    }
    

    
    // running execvp()
    int pid = fork();

    if (pid == 0){
      execvp(args[0], args);
    
    } else {
      wait(NULL);
    }
    
  }
  
  return 0;

  
}
