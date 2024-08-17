#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
/**
*main - super simple shell that can run commands with thier
*full path without any argument
*Return: 0 (Success)
*/
int main(void)
{
size_t buf_size = 0;
char *buf = NULL;
char *token;
int status;
int i = 0;
char **array;
pid_t child_pid;
while (1)
{
write(1, "#cisfun$", 9);
getline(&buf, &buf_size, stdin);
token = strtok(buf, "\t\n");
array = malloc(sizeof(char *) * 1024);
while (token)
{
array[i] = token;
token = strtok(NULL, "\t\n");
i++;
}
array[i] = NULL;
child_pid = fork();
if (child_pid == 0)
{
if (execve(array[0], array, NULL) == -1)
printf("Error: not executable\n");
}
else
{
wait(&status);
}
i = 0;
free(array);
}
}
