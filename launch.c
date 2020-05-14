#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
int main(int argc, char* argv[])
{
    int status;

    pid_t pid = fork();
    if (pid < 0) {
        printf("PID: %d, CPID: %d, RETVAL: %d\n", getpid(), pid, status);
    } else if (pid == 0) {
        char *args[argc];
        int i;
	int j = 0;
        for (i = 1; i < argc; i++, j++) {
            args[j] = argv[i];
            args[j + 1] = NULL;
        }

      // char *args[] = {"/bin/ls", "-l", "2>/dev/null", NULL};
        execve(args[0], args, NULL);
        perror("Could not execve");

    } else if (pid > 0) {

        printf("CPID: %d\n", pid);
        waitpid(pid, &status, WUNTRACED);
        printf("RETVAL: %d\n", status);
    }
    return 0;
}
