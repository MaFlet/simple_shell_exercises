#include <stdio.h>
/**
*main - prints all arugments without using ac
*@ac: argument counter
*@av: handle an array of arguments
*Return: (0) Success
*/
int main(__attribute__((unused))int ac, char **av)
{
int i = 0;
while (av[i])
{
printf("%s", av[i]);
i++;
}
printf("\n");
return (0);
}
