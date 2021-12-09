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
    }
    else
    {
        printf("\nI am the parent, my pid = %d and my parent's pid = %d\n\n", getpid(), getppid());
        sleep(200);
        int status;
        pid = wait(&status);
        if(!(status & 0x00FF))
            printf("\nA child with pid %d terminated with exit code %d\n", pid, status>>8);
    }

    printf("\nPID %d terminated\n\n", getpid());

    return 0;
}
