/*
** EPITECH PROJECT, 2018
** engine_reader.c
** File description:
**
*/

#include "tetris.h"

char *read_file(const char *file_name)
{
	int fd = open(file_name, O_RDONLY);
	char *buff = malloc(sizeof(char) * 4096);
	int offset = 0;

	if (fd <= 0 || buff == NULL)
		return (NULL);
	while (read(fd, buff + offset, 1) > 0 && offset < 4095)
		offset += 1;
	buff[offset] = '\0';
	close(fd);
	return (buff);
}

void read_tetri(struct entity *entity, char *content, char *first_line,
	int f_y)
{
	int x = 0;
	int y = 0;
	int count = 0;
	int f_x = 0;

	for (int i = my_strlen(first_line) + 1; content[i]; i++) {
		if (content[i] == '\n') {
			y++;
			x = 0;
			continue;
		} else if (content[i] == '*') {
			if (count != 0)
				entity->cells[count - 1]
					= get_cell_instance(x - f_x, y - f_y);
			else {
				f_x = x;
				f_y = y;
			}
			count++;
		}
		x++;
	}
}

int my_getchar(void)
{
	const int intput_shell = 0;
	const int size = 1;
	char c;

	if (read(intput_shell, &c, size) == 1)
		return (unsigned char)c;
	else
		return (0);
}