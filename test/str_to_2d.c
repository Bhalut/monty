#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char *str_div(char *str_to_div)
{
	char *str_aux = NULL;
	char *token = NULL;

	str_aux = strdup(str_to_div);
	if (str_aux == NULL)
	{
		return (NULL);
	}
	token = strtok(str_aux, " \n\t\r");
	return (token);
}
int main()
{
	char *result;

	result = str_div("Push 1");
	printf("token: %s\n", result);
	return 0;
}