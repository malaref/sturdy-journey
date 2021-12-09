#include <unistd.h>
#include <stdio.h>

void do_parent()
{
    printf("\nI am the parent, my pid = %d and my parent's pid = %d\n\n", getpid(), getppid());
}

void do_child()
{
    printf("\nI am the child, my pid = %d and my parent's pid = %d\n\n", getpid(), getppid());
}

int main()
{
    printf("\nmy pid = %d\n", getpid());
    int pid = fork();

    if (pid == -1)
        perror("error in fork");

    else if (pid == 0)
    {
        do_child();
    }
    else
    {
        do_parent();
    }

    printf("\nPID %d terminated\n\n", getpid());
    return 0;
}
