/*
** EPITECH PROJECT, 2018
** engine_tetriminos.c
** File description:
**
*/

#include "tetris.h"

int max_tetriminos(void)
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
		i++;
	}
	closedir(rep);
	free(reader);
	return (i);
}

int get_tetriminos(struct entity *entity, int index)
{
	const char *folder = "./tetriminos";
	DIR *rep = opendir(folder);
	struct dirent *reader;
	int i = 0;
	int out;

	while ((reader = readdir(rep))) {
		if (reader->d_name[0] == '.')
			continue;
		if (i == index) {
			out = read_tetriminos(entity,
				get_tetriminos_path(reader->d_name));
			closedir(rep);
			return (out);
		}
		i++;
	}
	closedir(rep);
	free(reader);
	return (0);
}

int read_tetriminos(struct entity *entity, char *file_name)
{
	char *content = read_file(file_name);
	char *first_line;
	char **str;

	if (content == NULL || check_tetriminos(content) == 0 ||
		(first_line = get_line(content, 0)) == NULL ||
		string_len(first_line, ' ') != 2 ||
		(str = my_str_to_word_array(first_line, ' ')) == NULL)
		return (0);
	entity->size_y = my_getnbr(str[0]);
	entity->size_x = my_getnbr(str[1]);
	entity->color = my_getnbr(str[2]);
	entity->len = check_tetriminos(content) - 1;
	entity->cells = malloc(sizeof(struct cell) * (entity->len));
	if (entity->cells == NULL)
		return (0);
	process_read_tetriminos(entity, file_name);
	free(content);
	free(first_line);
	free(str);
	return (1);
}

void process_read_tetriminos(struct entity *entity, char *file_name)
{
	char *content = read_file(file_name);
	char *first_line;

	if (content == NULL || (first_line = get_line(content, 0)) == NULL ||
		(entity->patern = malloc(sizeof(char) *
		(my_strlen(content) - my_strlen(first_line) + 1))) == NULL)
		return;
	my_strncpy(entity->patern, content, my_strlen(first_line) + 1,
		my_strlen(content));
	read_tetri(entity, content, first_line, 0);
	free(first_line);
	free(content);
}

int check_tetriminos(char *str)
{
	int contain = 0;
	char *first_line = get_line(str, 0);
	char **src;

	if (my_strlen(str) < 7 || first_line == NULL
		|| string_len(first_line, ' ') != 2 ||
		(src = my_str_to_word_array(first_line, ' ')) == NULL)
		return (0);
	if ((my_getnbr(src[0]) < 0) || (my_getnbr(src[1]) < 0) ||
		(my_getnbr(src[2]) <= 0) || (my_getnbr(src[2]) >= 10))
		return (0);
	for (int i = my_strlen(first_line); str[i]; i++) {
		if (str[i] == '*')
			contain++;
		if (str[i] != '*' && str[i] != ' ' && str[i] != '\n')
			return (0);
	}
	free(first_line);
	free(src);
	return (contain);
}