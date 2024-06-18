/*
** EPITECH PROJECT, 2018
** engine_colision.c
** File description:
**
*/

#include "tetris.h"

int entity_colision(struct game *game)
{
	struct entity *current = get_moving_entity(game);

	if (current->display == 1 &&
		cell_colision(game, current->x, current->y) == 1)
		return (1);
	for (int n = 0; n < current->len; n++) {
		if (current->cells[n].x == 0 &&
			current->cells[n].y == 0)
			continue;
		if (current->y + current->cells[n].y >= game->map_height - 1)
			return (1);
		if (cell_colision(game, current->x
			+ current->cells[n].x,
			current->y
			+ current->cells[n].y) == 1)
			return (1);
	}
	return (0);
}

int cell_colision(struct game *game, int x, int y)
{
	if (y >= game->map_height - 1)
		return (1);
	for (int i = 0; i < game->len; i++) {
		if (game->entities[i]->moving == 1)
			continue;
		if (game->entities[i]->x == x && game->entities[i]->y == y + 1)
			return (1);
		for (int n = 0; n < game->entities[i]->len; n++) {
			if (game->entities[i]->cells[n].x == 0 &&
				game->entities[i]->cells[n].y == 0)
				continue;
			if (game->entities[i]->x
				+ game->entities[i]->cells[n].x == x &&
				game->entities[i]->y
				+ game->entities[i]->cells[n].y == y + 1)
				return (1);
		}
	}
	return (0);
}