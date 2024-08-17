#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
/**
*main - creating program that executes command ls -l /tmp
*in 5 different child process.
*Return: 0 (Success)
*/
int main(void)
{
pid_t my_pid;
pid_t child_pid = 1;
int i = 0;
int status;
char *argv[] = {"bin/ls", "-l", "tmp/", NULL};
my_pid = getpid();
while (i <= 4 && (child_pid != 0))
{
child_pid = fork();
if (child_pid == -1)
{
perror("Error:");
return (1);
{
wait(&status);
i++;
}
if (child_pid == 0)
{
printf("------\n\n");
printf("Child ID: %u\n\nID Father ID: %u\n\n", getpid(), getppid());
printf("-----\n\n");
}
else
{
printf("%u Father ID is: %u\n", my_pid, child_pid);
}
if (execve(argv[0], argv, NULL) == -1)
{
}
return (0);
}
}
}

