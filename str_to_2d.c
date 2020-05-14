#include "monty.h"
/**
 * token_count - Count the number of words on a string
 * @str: string to split and count the words
 * @del: strin whit the caracter delimiters
 *
 * Return: number of words
 */
unsigned int token_count(char *str, char del[])
{
	char *token = NULL;
	unsigned int m;

	token = strtok(str, del);
	m = 0;
	while (token != NULL)
	{
		token = strtok('\0', del);
		m++;
	}
	return (m);
}
/**
 * split_token - split a string on diferent arrays
 * @str: String to split
 * @splt_str: pointer with the memory space allocated fo the strs
 * @m: number of words to split
 * @del: strin whit the caracter delimiters
 *
 * Return: Double pointer with the adress of the sub-strings
 */
char **split_token(char **splt_str, char *str, unsigned int m, char del[])
{
	char *token = NULL;
	unsigned int p_idx;

	token = strtok(str, del);
	p_idx = 0;
	while (p_idx < m)
	{
		splt_str[p_idx] = strdup(token);
		if (splt_str[p_idx] == NULL)
		{
			while (p_idx > 0)
			{
				free(splt_str[p_idx]);
				p_idx--;
			}
			free(splt_str[0]);
			free(splt_str);
			free(str);
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		token = strtok('\0', del);
		p_idx++;
	}
	splt_str[p_idx] = NULL;
	return (splt_str);
}
/**
 * str_to_2d - Split a string in sub strings
 * @buff_str: String to split
 * @del: strin whit the caracter delimiters
 *
 * Return: Double pointer with the adress of the sub-strings
 */
char **str_to_2d(char *buff_str, char del[])
{
	char *tmp_len = NULL, *tmp_splt = NULL, **splt_str = NULL;
	unsigned int m;

	tmp_len = strdup(buff_str);
	if (tmp_len == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	tmp_splt = strdup(buff_str);
	if (tmp_splt == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	m = token_count(tmp_len, del);
	free(tmp_len);
	splt_str = malloc((sizeof(char *)) * (m + 1));
	if (splt_str == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	splt_str = split_token(splt_str, tmp_splt, m, del);
	free(tmp_splt);
	return (splt_str);
}