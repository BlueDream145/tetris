/*
** EPITECH PROJECT, 2018
** check.c
** File description:
**
*/

#include "tetris.h"

int string_len(char *src, char find)
{
	int len = 0;

	for (int i = 0; src[i]; i++)
		if (src[i] == find)
			len++;
	return (len);
}

int available_tetriminos(void)
{
	const char *folder = "./tetriminos";
	char *file = NULL;
	DIR *rep = opendir(folder);
	struct dirent *reader;
	int i = 0;

	if (rep == NULL)
		return (0);
	while ((reader = readdir(rep))) {
		if (reader->d_name[0] == '.')
			continue;
		file = read_file(get_tetriminos_path(reader->d_name));
		if (file == NULL)
			continue;
		if (check_tetriminos(file) > 0)
			i++;
	}
	closedir(rep);
	free(file);
	free(reader);
	return (i);
}