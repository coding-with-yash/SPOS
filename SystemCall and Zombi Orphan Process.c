// TO DEMONSTRATE PROCESS SYSTEM CALL

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t pid;
    pid = fork();

    if (pid == -1)
    {
              printf("Fork failed!\n");
    } else if (pid == 0) 
    {
                printf("Child process ID is: \"%d\" and my parent process ID is: \"%d\"\n\n", getpid(), getppid());
    } else 
    {
        printf("Parent process ID is: \"%d\" and my grandparent process ID is: \"%d\"\n\n", getpid(), getppid());
    }

    return 0;
}


// TO DEMONSTRATE ORPHAN PROCESS USING sleep()

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t pid;
    pid = fork();

    if (pid == 0) {
        printf("Before Sleep!!\n");
        printf("Child process ID is: \"%d\" and my parent process ID is: \"%d\"\n\n", getpid(), getppid());
        sleep(10);
        printf("After Sleep!!\n");
        printf("Child process ID is: \"%d\" and my parent process ID is: \"%d\"\n\n", getpid(), getppid());
    } else {
        _exit(0);
    }

    return 0;
}


//TO DEMONSTRATE ZOMBIE PROCESSUSING_exit()

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t pid;
    pid = fork();

    if (pid == 0) {
        printf("Before Sleep!!\n");
        printf("Child process ID is: \"%d\" and my parent process ID is: \"%d\"\n\n", getpid(), getppid());
        _exit(0);
    } else {
        sleep(2);
    }

    return 0;
}
