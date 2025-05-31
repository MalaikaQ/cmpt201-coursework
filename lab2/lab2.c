#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  char input[1024];

  while (1) {

    printf("Enter programs to run.\n");

    printf("> ");
    fflush(stdout);

    if (fgets(input, sizeof(input), stdin) == NULL) {
      break;
    }

    input[strcspn(input, "\n")] = '\0';

    pid_t pid = fork();

    if (pid == -1) {
      perror("fork");
      exit(1);
    } else if (pid == 0) {
      execl(input, input, (char *)NULL);
      perror("Exec failure");
      exit(1);
    } else {
      int status;
      waitpid(pid, &status, 0);
    }
  }

  return 0;
}
