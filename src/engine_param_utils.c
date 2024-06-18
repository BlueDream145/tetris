/*
** EPITECH PROJECT, 2018
** engine_param_utils.c
** File description:
**
*/

#include "tetris.h"

char *get_name(int index)
{
	const char *folder = "./tetriminos";
	DIR *rep = opendir(folder);
	struct dirent *reader;
	int i = 0;

	if (rep == NULL)
		return (0);
	while ((reader = readdir(rep))) {
		if (reader->d_name[0] == '.')
			continue;
		if (i == index)
			return (my_strdup(reader->d_name));
		i++;
	}
	closedir(rep);
	free(reader);
	return (NULL);
}

char *get_file_name(char *full_path)
{
	int start;
	char *res;

	if (string_len(full_path, '.') == 0)
		return (full_path);
	if ((start = get_start_index(full_path)) == -1)
		return (NULL);
	res = malloc(sizeof(char) * (start + 1));
	if (res == NULL)
		return (NULL);
	my_strncpy(res, full_path, 0, start - 1);
	res[start - 1] = '\0';
	return (res);
}

int *get_sorted_list(void)
{
	int *elems = malloc(sizeof(int) * max_tetriminos());
	char **tmp = malloc(sizeof(char*) * max_tetriminos());
	int success = 0;
	int i = 0;

	if (elems == NULL || tmp == NULL)
		return (NULL);
	while (i < max_tetriminos()) {
		tmp[i] = get_name(i);
		elems[i] = i;
		i++;
	}
	while (success == 0) {
		success = 1;
		success = my_sort_alpha(elems, tmp, success);
	}
	free(tmp);
	return (elems);
}

int my_sort_alpha(int *elems, char **src, int success)
{
	int size = max_tetriminos();
	char *tmp;
	int n_tmp;
	int i = 0;

	for (i = 0; i < size - 1; i++) {
		if (my_strcmp(src[i], src[i + 1]) > 0) {
			tmp = my_strdup(src[i]);
			src[i] = my_strdup(src[i + 1]);
			src[i + 1] = my_strdup(tmp);
			n_tmp = elems[i];
			elems[i] = elems[i + 1];
			elems[i + 1] = n_tmp;
			success = 0;
		}
	}
	return (success);
}

int get_start_index(char *full_path)
{
	int len;
	int start;

	if ((len = string_len(full_path, '.')) == 0)
		return (-1);
	for (start = 0; full_path[start] && len != 0; start++) {
		if (full_path[start] == '.')
			len--;
	}
	return (start);
}