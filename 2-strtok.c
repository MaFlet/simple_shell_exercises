#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/**
*main - splits strings
*
*Return: (0) Success
*/
int main(void)
{
char string[] = "The project is challenging";
char *token = strtok(string, " ");
while (token != NULL)
{
printf("%s\n", token);
token = strtok(NULL, " ");
}
return (0);
}
