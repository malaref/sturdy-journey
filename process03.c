#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
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
        exit(42); // return 42;
    }
    else
    {
        printf("\nI am the parent, my pid = %d and my parent's pid = %d\n\n", getpid(), getppid());
        int status;
        pid = wait(&status);
        if(WIFEXITED(status))
          	printf("\nA child with pid %d terminated with exit code %d\n", pid, WEXITSTATUS(status));
        
    }
    // Another comment!!!!!
    printf("\nPID %d terminated\n\n", getpid());
    return 0;
}
