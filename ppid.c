#include <stdio.h>
#include <unistd.h>
/**
*main - creating a parent PID
*Return: (0) Success
*/
int main(void)
{
pid_t parent_pid;
parent_pid = getppid();
printf("%u\n", parent_pid);
return (0);
}
