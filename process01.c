#include <unistd.h>
#include <stdio.h>
// this is NOT A COMMENT
int main()
{
    int x = 3;

    printf("\nmy pid = %d\n", getpid());
    int pid = fork();

    if (pid == -1)
        perror("error in fork");

    else if (pid == 0)
    {
        x = 7;
        printf("\nI am the child, my pid = %d and my parent's pid = %d\n\n", getpid(), getppid());
    }
    else
    {
        x = 19;
        printf("\nI am the parent, my pid = %d and my parent's pid = %d\n\n", getpid(), getppid());

    }

    printf("\n Finish: PID:%d, X:%d\n", getpid(), x);
    return 0;
}
