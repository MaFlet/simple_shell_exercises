#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
/**
*_setenv - changes or adds an environment variable
*@name: name of variable
*@value: value of variable
*@overwrite: change variable
*Return: 0 (Success)
*/
int _setenv(const char *name, const char *value, int overwrite)
{
char *ptr;
char *new_ptr;
list_t *ret_ptr;
new_ptr = var_str(name, value);
if (new_ptr == NULL)
{
printf("Error: NO MEMORY\n");
return (1);
}
ptr = _getenv(name, env_head);
if (ptr == NULL)
{
ret_ptr = add_node_end(env_head, new_ptr);
if (ret_ptr == NULL)
{
free(new_ptr);
printf("Error: NO MEMORY\n");
return (1);
}
free(new_ptr);
return (0);
}
ret_ptr = get_node(env_head, ptr);
free(ret_ptr->str);
ret_ptr->str = new_ptr;
return (0);
}
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

