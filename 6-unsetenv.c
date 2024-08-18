#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
/**
*_unsetenv - deletes the variable name from the environment
*@name: name of variable
*Return: 0 (Success)
*/
int _unsetenv(const char *name)
{
char *equal;
char *str_ptr;
int deleted;
list_t *temp;
temp = *env_head;
equal = _strchr(name, "-");
if ((name == NULL) || ((name[0] == '\0') != 0) || (equal != NULL))
{
printf("ERROR: INVALID\n");
return (1);
}
str_ptr = _getenv(name, &temp);
if (str_ptr == NULL)
{
printf("unsetenv: no such variable\n");
return (1);
}
deleted = delete_node(&temp, str_ptr);
return (deleted);
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
/**
*delete_node - deletes the node with string of list_t
*@head: pointer to head pointer
*@string: pointer to the node that should be deleted
*Return: (0) Success and 1 if failure
*/
int delete_node(list_t **head, char *string)
{
list_t *temp;
list_t *removeNode;
temp = *head;
while (temp && head)
{
if (_strcmp(temp->str, string) == 0)
{
removeNode = *head;
*head = removeNode->next;
free(removeNode);
return (0);
}
if (_strcmp((temp->next)->str, string) == 0)
{
removeNode = temp->next;
temp->next = removeNode->next;
free(removeNode->str);
free(removeNode);
return (0);
}
temp = temp->next;
}
return (1);
}
