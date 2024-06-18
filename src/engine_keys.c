/*
** EPITECH PROJECT, 2018
** engine_keys.c
** File description:
**
*/

#include "tetris.h"

void manage_getch(struct game *game, int key)
{
	struct entity *current;

	if (moving_entity_exists(game) == 0)
		return;
	current = get_moving_entity(game);
	handle_key(game, current, key);
}

void handle_key(struct game *game, struct entity *current, int key)
{
	if (key == game->keys->key_rotate
		&& cell_colision(game, current->x, current->y) == 0)
		rotate_entity(game);
	if (key == game->keys->key_fall
		&& cell_colision(game, current->x, current->y) == 0
		&& current->y <= highest_entity(game))
		current->y++;
	if (key == game->keys->key_left &&
		entity_horizontal_colision(game, -1) == 0)
		current->x--;
	if (key == game->keys->key_right &&
		entity_horizontal_colision(game, 1) == 0)
		current->x++;
	handler_adv_key(game, key);
}

void handler_adv_key(struct game *game, int key)
{
	if (key == game->keys->key_leave)
		game->running = 0;
	if (key == game->keys->key_break) {
		game->running = 0;
		game->pause = 1;
	}
}

int entity_horizontal_colision(struct game *game, int val)
{
	struct entity *current = get_moving_entity(game);

	if (current->display == 1 &&
	cell_horizontal_colision(game, current->x, current->y, val) == 1)
		return (1);
	for (int n = 0; n < current->len; n++) {
		if (current->cells[n].x == 0 &&
			current->cells[n].y == 0)
			continue;
		if ((current->x + current->cells[n].x >= game->map_width + 4
			&& val == 1) || (current->x + current->cells[n].x <= 6
			&& val == -1))
			return (1);
		if (cell_horizontal_colision(game, current->x
			+ current->cells[n].x,
			current->y
			+ current->cells[n].y, val) == 1)
			return (1);
	}
	return (0);
}

int cell_horizontal_colision(struct game *game, int x, int y, int val)
{
	if ((val == 1 && x >= game->map_width + 4) || (val == -1 && x <= 6))
		return (1);
	for (int i = 0; i < game->len; i++) {
		if (game->entities[i]->moving == 1)
			continue;
		if (game->entities[i]->x == x + val
			&& game->entities[i]->y == y)
			return (1);
		for (int n = 0; n < game->entities[i]->len; n++) {
			if (game->entities[i]->cells[n].x == 0 &&
				game->entities[i]->cells[n].y == 0)
				continue;
			if (game->entities[i]->x
				+ game->entities[i]->cells[n].x == x + val &&
				game->entities[i]->y
				+ game->entities[i]->cells[n].y == y)
				return (1);
		}
	}
	return (0);
}