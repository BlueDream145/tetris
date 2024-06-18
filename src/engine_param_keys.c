/*
** EPITECH PROJECT, 2018
** engine_param_keys.c
** File description:
**
*/

#include "tetris.h"

void handle_key_left(struct game *game, char *data)
{
	if (game == NULL || data == NULL)
		return;
	if (my_strlen(data) == 1)
		game->keys->key_left = (int)data[0];
	else if (str_to_key(data) != 0)
		game->keys->key_break = str_to_key(data);
}

void handle_key_right(struct game *game, char *data)
{
	if (game == NULL || data == NULL)
		return;
	if (my_strlen(data) == 1)
		game->keys->key_right = (int)data[0];
	else if (str_to_key(data) != 0)
		game->keys->key_break = str_to_key(data);
}

void handle_key_turn(struct game *game, char *data)
{
	if (game == NULL || data == NULL)
		return;
	if (my_strlen(data) == 1)
		game->keys->key_rotate = (int)data[0];
	else if (str_to_key(data) != 0)
		game->keys->key_break = str_to_key(data);
}

void handle_key_drop(struct game *game, char *data)
{
	if (game == NULL || data == NULL)
		return;
	if (my_strlen(data) == 1)
		game->keys->key_fall = (int)data[0];
	else if (str_to_key(data) != 0)
		game->keys->key_break = str_to_key(data);
}