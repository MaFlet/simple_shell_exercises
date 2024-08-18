#include <stdio.h>
#include <unistd.h>
extern char **environ;
**/
*main - prints the address of env and environ
*Return: (0) Success
*/
int main(int ac, char **av, char **env)
{
printf("%p\n %p\n", environ, env);
return (0);
}
