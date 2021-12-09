#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>

main()
{
    int pid = fork();

    if (pid == -1)
        perror("error in fork");
    else if (pid ==0)
    {
        printf("\nI am the child with pid %d, and priority %d\n", getpid(), getpriority(PRIO_PROCESS,0));

        printf("\nOriginal priority\n");
        system("ps -l");
        for (long counter = 0; counter < 5000000; counter++);
        printf("\nChild is now nice 5");
        nice(5);

        printf("\nI am the child with pid %d, and priority %d\n", getpid(), getpriority(PRIO_PROCESS,0));
        system("ps -l");
        while(1) {}
    }
    else
    {
        printf("\nI am the parent with pid %d, and priority %d\n", getpid(), getpriority(PRIO_PROCESS,0));

        printf("\nOriginal priority\n");
        system("ps -l");
        for (long counter = 0; counter < 5000000; counter++);
        printf("\nParent is now nice 10");
        nice(20);

        printf("\nI am the parent with pid %d, and priority %d\n", getpid(), getpriority(PRIO_PROCESS,0));
        system("ps -l");
        while(1) {}
    }

}
