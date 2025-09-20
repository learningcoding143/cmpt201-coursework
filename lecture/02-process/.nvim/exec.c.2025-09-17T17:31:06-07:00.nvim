#include <stdio.h>
#include <unistd.h>

int main() {
  printf("forking\n");
  int pid = fork();

  if (pid != 0) {
    execlp("ls", "ls", (char *)NULL);
    //parent
  } else {
    execlp("ls", "ls", "-alh", (char *)NULL);
    //child  
  }
}
