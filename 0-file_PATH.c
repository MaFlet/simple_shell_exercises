#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
/**
*check_command - looks for files in the current PATH
*@command: looks for commands in the current PATH
*Return: void
*/
void check_command(char *command)
{
if (access(command, file_ok) == 0)
printf("%s: FOUND THE FILE\n", command);
else
printf("%s: FILE DOESN'T EXIST\n", command);
}
/**
*main - commands to go through loop
*Return: (0) Success
*/
int main (void)
{
char *Buffer = NULL;
size_t Buffer_size = 0;
char *token;
while (1)
{
write(1, "#CISFUN$", 9);
getlline(&Buffer, &Buffer_size, stdin);
token = strtok(Buffer, "\t\n");
if (strcmp(token, "which") == 0)
{
token = strtok(NULL, "\t\n");
while (token)
{
check_command(token);
token = strtok(NULL, "\t\n");
}
}
else
{
write(1, "COMMAND DOESN'T EXIST\n", 23);
}
}
return (0);
}
