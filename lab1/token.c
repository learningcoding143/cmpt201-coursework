#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
  // enter a line
  // sting as input
  // tokenize rthe string
  // print each word on a newline until empty
  //
  //
  char *buffer;
  size_t bufsize = 32;
  size_t chars;

  buffer = (char *)malloc(bufsize * sizeof(char));
  if (buffer == NULL) {
    return (1);
  }

  printf("Type a something: ");

  chars = getline(&buffer, &bufsize, stdin);

  printf("you have typed: %s", buffer);

  char *token;
  char *saveptr;

  token = strtok_r(buffer, ' ', &saveptr);
  printf("tokens are: %s", token);

  free(buffer);
  return 0;
}
