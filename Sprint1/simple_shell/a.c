#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
    pid_t pid; // pid_t <-> int

    pid = fork();

    if (pid < 0)
    {
        /* fork failed */
        perror("fork");
        return (1);
    }
    else if (pid == 0)
    {
        /* Child process */
        printf("I am the child, PID=%d\n", getpid());
    }
    else
    {
        /* Parent process */
        printf("I am the parent, child PID=%d\n", pid);
    }

    return (0);
}
