#ifndef _TOKENIZER_

#define _TOKENIZER_

#include <stdio.h>

#include <stdlib.h>



/* Return true (non-zero) if c is a whitespace character ('\t' or ' '). */

int space_char(char c) {

  return (c == ' ' || c == '\t');

}



/* Return true if c is a non-whitespace character. */

int non_space_char(char c) {

  return !space_char(c) && c != '\0';

}



/* Returns a pointer to the first character of the next token. */

char *token_start(char *str) {

  while (*str != '\0' && space_char(*str)) {

    str++;

  }

  return (*str == '\0') ? NULL : str;

}



/* Returns a pointer to the end of a token. */

char *token_terminator(char *token) {

  while (*token != '\0' && non_space_char(*token)) {

    token++;

  }

  return token;

}



/* Counts the number of tokens in the string. */

int count_tokens(char *str) {

  int count = 0;

  char *token = token_start(str);

  while (token != NULL) {

    count++;

    str = token_terminator(token);

    token = token_start(str);

    while (token != NULL) {

      count++;

      str = token_terminator(token);

      token = token_start(str); // Move to next token

    }

    return count;

  }



  /* Returns a newly allocated string containing <len> chars from <inStr>. */

  char *copy_str(char *inStr, short len) {

    char *str_copy = (char *)malloc((len + 1) * sizeof(char)); // Cast malloc result

    if (!str_copy) {

      perror("Memory allocation failed");

      exit(1);

    }

    for (short i = 0; i < len; i++) {

      str_copy[i] = inStr[i];

    }

    str_copy[len] = '\0';

    return str_copy;

  }

  /* Tokenizes the input string and returns a list of tokens. */

  char **tokenize(char *str) {

    int token_count = count_tokens(str);

    char **tokens = (char **)malloc(sizeof(char *) * (token_count + 1));

    if (!tokens) {

      perror("Memory allocation failed");

      exit(1);

    }



    char *token = str;

    for (int i = 0; i < token_count; i++) {

      token = token_start(token);
      char *token_end = token_terminator(token);

      int length = token_end - token;

      tokens[i] = copy_str(token, length);

      token = token_end;

    }

    tokens[token_count] = NULL;

    return tokens;

  }



  /* Prints all tokens. */

  void print_tokens(char **tokens) {

    int i = 0;

    while (tokens[i] != NULL) {

      printf("Token[%d]: %s\n", i, tokens[i]);

      i++;

    }

  }



  /* Frees all tokens and the vector containing them. */

  void free_tokens(char **tokens) {

    int i = 0;

    while (tokens[i]) {

      free(tokens[i]);

      i++;

    }

    free(tokens); // Free the tokens

  }



  #endif

  
