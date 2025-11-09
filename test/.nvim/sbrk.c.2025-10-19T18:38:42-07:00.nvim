#define _POSIX_C_SOURCE 200809
#include <stdio.h>
#include <unistd.h>

void *sbrk(intptr_t increment);
int main() {
  void *curr = sbrk(0);
  printf("%p\n", curr);
}
