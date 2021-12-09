#include <unistd.h>
#include <stdio.h>

int main()
{
    printf("\nmy pid = %d\n", getpid());
    int pid = fork();

    if (pid == -1)
        perror("error in fork");

    else if (pid == 0)
    {
        printf("\nI am the child, my pid = %d and my parent's pid = %d\n\n", getpid(), getppid());
        sleep(5);
        printf("\nAgain I am now an orphan child, my pid = %d and my parent's pid = %d\n\n", getpid(), getppid());
    }
    else
    {
        printf("\nI am the parent, my pid = %d and my parent's pid = %d\n\n", getpid(), getppid());
        //sleep(2);
    }

    printf("\nPID %d terminated\n\n", getpid());
    return 0;
}
