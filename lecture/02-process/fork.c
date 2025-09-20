#include <stdio.h>
#include <unistd.h>

int main() {
  printf("start \n");
  fork();
  int pid = getpid();
  int ppid = getppid();
  if (pid != 0) {
    printf("Parent: %d \n", ppid);
  } else {
    printf("child: %d \n", pid);
  }
}
