#include <stdio.h>
#include <string.h>
#include <unistd.h>
int main() {

  printf("execl now!\n");
  char arg1[] = "/usr/bin/ls";
  execl(arg1, arg1, (char *)NULL);
}
