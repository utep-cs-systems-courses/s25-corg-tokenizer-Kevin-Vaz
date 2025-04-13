#include <stdio.h>

#include <string.h>

#include "tokenizer.c"



int main() {

  char input[128];

  puts("Welcome to my tokenizer");

  printf("Write anything or enter 0415 to exit\n");



  while (1) {

    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = '\0';



    if (strcmp(input, "0415") == 0) {

      break;

    }



    char **tokens = tokenize(input);

    if (tokens) {

      print_tokens(tokens);

      free_tokens(tokens);

    }

  }



  return 0;

}
