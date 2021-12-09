#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main()
{
    printf("\nmy pid = %d\n", getpid());
    int pid = fork();

    if (pid == -1)
        perror("error in fork");

    else if (pid == 0)
    {
        printf("\nI am the child, my pid = %d and my parent's pid = %d\n\n", getpid(), getppid());
        char *argv[] = { "/bin/echo", "hi", "there", 0 };
        execve(argv[0], &argv[0], NULL);
        printf("\nAnybody here?\n\n");
    }
    else
    {
        printf("\nI am the parent, my pid = %d and my parent's pid = %d\n\n", getpid(), getppid());
        int status;
        pid = wait(&status);
    }

    printf("\nPID %d terminated\n\n", getpid());

    return 0;
}
