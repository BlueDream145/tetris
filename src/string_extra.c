/*
** EPITECH PROJECT, 2018
** string_extra.c
** File description:
*
*/

#include "tetris.h"

char **my_str_to_word_array(const char *str, char separator)
{
	char **result = malloc(sizeof(char *) * my_strlen(str));
	char *content = malloc(sizeof(char) * (my_strlen(str) + 1));

	if (result == NULL || content == NULL || my_strlen(str) == 0)
		return (NULL);
	content[0] = '\0';
	split_string(str, separator, result, content);
	return (result);
}

void split_string(const char *str, char separator,
	char **result, char *content)
{
	int word_len = 0;
	int total_len = 0;

	for (int i = 0; i < my_strlen(str) + 1; i++) {
		if (str[i] != separator) {
			content[word_len] = str[i];
			word_len++;
			content[word_len] = '\0';
		} else if (my_strlen(content) > 0) {
			word_len = 0;
			result[total_len] = my_strdup(content);
			total_len++;
		}
	}
	if (my_strlen(content) > 0) {
		content[word_len] = '\0';
		result[total_len] = my_strdup(content);
		total_len++;
	}
	result[total_len] = '\0';
}

char *get_line(char *str, int start)
{
	char *result;
	int i;
	int len = 0;

	for (i = start; i < my_strlen(str) && str[i] != '\n'; i++)
		len++;
	if (len == 0)
		return (NULL);
	result = malloc(sizeof(char) * (len + 2));
	if (result == NULL)
		return (NULL);
	for (i = start; str[i] && str[i] != '\n'; i++)
		result[i - start] = str[i];
	result[i - start] = '\0';
	return (result);
}

char *my_strdup(const char *src)
{
	char *str;
	int len = my_strlen(src) + 1;

	str = malloc(sizeof(char) * (len));
	if (str == NULL)
		return (NULL);
	str = my_strcpy(str, src);
	return (str);
}

int my_getnbr(char *str)
{
	int val = 0;

	while (*str) {
		if (*str >= '0' && *str <= '9') {
			val *= 10;
			val += *str - '0';
		} else
			return (-1);
		str++;
	}
	return (val);
}