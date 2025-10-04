#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

int main() {
  pid_t pid = fork();

  if (pid) {
    int wstatus = 0;
    if (waitpid(pid, &wstatus, 0) == -1) {

      perror("waitpid");
      exit(EXIT_FAILIURE);
    }
    if (WIFEXITED(wstatus)) {
      printf("child done with exit status: %d/n", WEXITSTATUS(wstatus));
    } else {
      printf("child did not exit normally.\n");
    }
  } else {
    *(volatile int *)NULL;
    if (execl("usr/bin/ls", "/usr/bin/ls", "-a", "-l", NULL) == -1) {
      perror("execl");
      exit(EXIT_FAILIURE);
    }
  }
}
