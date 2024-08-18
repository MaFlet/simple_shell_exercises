#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
*_getenv - gets an environment variable
*@name - name of variable
*Return: token or NULL if otherwise
*/
char *_getenv(const char *name)
{
extern char **environ;
int i;
char *token;
i = 0;
while (environ[i])
{
token = strtok(environ[i], "=");
if (strcmp(token, name) == 0)
{
return (strtok(NULL, "="));
}
i++;
}
return (NULL);
}
/**
*main - main command loops
*Return: void
*/
void main(void)
{
char *homevalue = _getenv("HOME");
printf("%s\n", homevalue);
}
