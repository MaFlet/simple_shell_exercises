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
pid_t my_pid, child_pid;
int child_status;
for (int i = 0; i < 5; i++)
child_pid = fork();
my_pid = getpid();
usleep(1000);
if (child_pid > 0)
{
printf("I'm the parent, and my pid is %d\n", my_pid);
printf("My child's pid is %d\n", child_pid);
wait(&child_status);
printf("Child returned status %d\n", child_status);
}
else if
(child_pid == 0)
{
char *args[5];
args[1] = "ls";
args[2] = "-l";
args[3] = "/tmp";
args[4] = "NULL";
args[5] = "NULL";
execvp(args[0], args);
printf("I'm the child, and my pid is %d\n", my_pid);
}
else
{
printf("Something went wrong. Fork returned %d\n.", child_pid);
}
printf("Process %d exiting.\n", my_pid);
return (1);
}
