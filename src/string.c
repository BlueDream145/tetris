/*
** EPITECH PROJECT, 2018
** string.c
** File description:
**
*/

#include "tetris.h"

int my_strlen(const char *str)
{
	int len = 0;

	for (; str[len]; len++);
	return (len);
}

int my_strncmp(char const *s1, char const *s2, int n)
{
	int i = 0;

	for (i = 0; s1[i] == s2[i] && s1[i] && i < n; i++);
	if (i < n)
		return (s1[i] - s2[i]);
	return (0);
}

char *my_strcat(char *dest, const char *src)
{
	int dest_len = my_strlen(dest);
	int j = 0;

	for (j = 0; src[j] != '\0'; j++)
		dest[dest_len + j] = src[j];
	dest[dest_len + j] = '\0';
	return (dest);
}

char *my_strcpy(char *dest, const char *src)
{
	int i;

	for (i = 0; src[i]; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

char *get_tetriminos_path(char *file_name)
{
	const char *folder = "./tetriminos";

	char *file_path = malloc(sizeof(char) * (
		my_strlen(folder) +
		my_strlen(file_name) +
		2
	));
	if (file_path == NULL)
		return (NULL);
	my_strcpy(file_path, folder);
	my_strcat(file_path, "/");
	my_strcat(file_path, file_name);
	return (file_path);
}