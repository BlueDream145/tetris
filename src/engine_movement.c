/*
** EPITECH PROJECT, 2018
** engine_movement.c
** File description:
**
*/

#include "tetris.h"

void rotate_entity(struct game *game)
{
	struct entity *ent;

	if (can_rotate(game) == 0)
		return;
	ent = get_moving_entity(game);
	for (int i = 0; i < ent->len; i++) {
		if (ent->cells[i].x == 0 &&
			ent->cells[i].y == 0)
			continue;
		ent->cells[i] = get_cell_instance(-ent->cells[i].y,
			ent->cells[i].x);
	}
}

int can_rotate(struct game *game)
{
	struct entity *ent = get_moving_entity(game);

	for (int i = 0; i < ent->len; i++) {
		if (ent->cells[i].x == 0 &&
			ent->cells[i].y == 0)
			continue;
		if (available_cell(game,
			ent->x + (-ent->cells[i].y),
			ent->y + ent->cells[i].x) == 0)
			return (0);
	}
	return (1);
}

int available_cell(struct game *game, int x, int y)
{
	if (x > game->map_width + 4 || x < 6 || y >= game->map_height - 1)
		return (0);
	for (int i = 0; i < game->len; i++) {
		if (game->entities[i]->moving == 1)
			continue;
		if (game->entities[i]->x == x && game->entities[i]->y == y
			&& game->entities[i]->display == 1)
			return (0);
		for (int n = 0; n < game->entities[i]->len; n++) {
			if (game->entities[i]->cells[n].x == 0 &&
				game->entities[i]->cells[n].y == 0)
				continue;
			if (game->entities[i]->x +
				game->entities[i]->cells[n].x == x
				&& game->entities[i]->y +
				game->entities[i]->cells[n].y == y)
				return (0);
		}
	}
	return (1);
}