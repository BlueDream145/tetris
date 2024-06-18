/*
** EPITECH PROJECT, 2018
** engine_entities.c
** File description:
**
*/

#include "tetris.h"

void insert_entity(struct game *game)
{
	game->entities[game->len] = get_entity_instance(game->next_type);
	game->len++;
	game->next_type = crand(0, max_tetriminos());
	game->preview = get_entity_instance(game->next_type);
}

struct entity *get_moving_entity(struct game *game)
{
	struct entity *ent;

	for (int i = 0; i < game->len; i++)
		if (game->entities[i]->moving == 1)
			ent = game->entities[i];
	return (ent);
}

int moving_entity_exists(struct game *game)
{
	for (int i = 0; i < game->len; i++)
		if (game->entities[i]->moving == 1)
			return (1);
	return (0);
}

int highest_entity(struct game *game)
{
	int highest = game->map_height - 1;

	for (int i = 0; i < game->len; i++) {
		if (game->entities[i]->moving == 1)
			continue;
		if (game->entities[i]->y < highest)
			highest = game->entities[i]->y;
		for (int n = 0; n < game->entities[i]->len; n++) {
			if (game->entities[i]->cells[n].x == 0 &&
				game->entities[i]->cells[n].y == 0)
				continue;
			if (game->entities[i]->y
				+ game->entities[i]->cells[n].y < highest)
				highest = game->entities[i]->y
				+ game->entities[i]->cells[n].y;
		}
	}
	return (highest - 5);
}