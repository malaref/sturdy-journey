#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Enter number of children: ");
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int pid = fork();

        if (pid == -1)
            perror("error in fork");

        else if (pid == 0)
        {
            printf("\nI am the child, my pid = %d and my parent's pid = %d\n\n", getpid(), getppid());
            //exit(0);
        }
        else
        {
            printf("\nI am the parent, my pid = %d and my child pid = %d\n\n", getpid(), pid);
        }
    }
    return 0;
}
