/*
** EPITECH PROJECT, 2018
** engine_param_handler.c
** File description:
**
*/

#include "tetris.h"

void prepare_handler(struct game *game)
{
	if (game == NULL)
		return;
	game->handlers[0] = handle_level;
	game->handlers[1] = handle_key_left;
	game->handlers[2] = handle_key_right;
	game->handlers[3] = handle_key_turn;
	game->handlers[4] = handle_key_drop;
	game->handlers[5] = handle_key_quit;
	game->handlers[6] = handle_key_pause;
	game->handlers[7] = handle_map_size;
}

void handle_level(struct game *game, char *data)
{
	if (game == NULL || data == NULL)
		return;
	if (my_getnbr(data) <= 0 || my_getnbr(data) > 10)
		return;
	game->level = my_getnbr(data);
}

void handle_map_size(struct game *game, char *data)
{
	char **str;

	if (game == NULL || data == NULL || string_len(data, ',') != 1)
		return;
	for (int i = 0; data[i]; i++)
		if (!(data[i] >= '0' && data[i] <= '9') && data[i] != ',')
			return;
	if ((str = my_str_to_word_array(data, ',')) == NULL ||
		my_getnbr(str[0]) <= 0 || my_getnbr(str[1]) <= 0)
		return;
	game->map_width = my_getnbr(str[0]);
	game->map_height = my_getnbr(str[1]);
	free(str);

}

void handle_key_pause(struct game *game, char *data)
{
	if (game == NULL || data == NULL)
		return;
	if (my_strlen(data) == 1)
		game->keys->key_break = (int)data[0];
	else if (str_to_key(data) != 0)
		game->keys->key_break = str_to_key(data);
}

void handle_key_quit(struct game *game, char *data)
{
	if (game == NULL || data == NULL)
		return;
	if (my_strlen(data) == 1)
		game->keys->key_leave = (int)data[0];
	else if (str_to_key(data) != 0)
		game->keys->key_break = str_to_key(data);
}