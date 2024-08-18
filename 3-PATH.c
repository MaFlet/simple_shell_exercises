#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
*main - prints each directory contained in the environment
*variable PATH, one directory per line
*Return: (0) Success
*/
int main ()
{
char *path = getenv("PATH");
int length = strlen(path) -1;
for (int i = 0; i <= length; i++)
{
if (path[i] == ":")
path[i] = "\n";
printf("%c", path[i]);
}
printf("\n");
return (0);
}
