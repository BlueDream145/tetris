/*
** EPITECH PROJECT, 2018
** engine_line.c
** File description:
**
*/

#include "tetris.h"

int contain_full_line(struct game *game, int len)
{
	for (int lin = 5; lin < game->map_height; lin++) {
		for (int i = 0; i < game->len; i++) {
			if (game->entities[i]->moving == 1)
				continue;
			if (game->entities[i]->y == lin)
				len++;
			for (int n = 0; n < game->entities[i]->len; n++) {
				if (game->entities[i]->cells[n].x == 0 &&
					game->entities[i]->cells[n].y == 0)
					continue;
				if (game->entities[i]->y
					+ game->entities[i]->cells[n].y == lin)
					len++;
			}
		}
		if (len == game->map_width - 1)
			return (lin);
		len = 0;
	}
	return (0);
}

void remove_line(struct game *game, int line)
{
	for (int i = 0; i < game->len; i++) {
		if (game->entities[i]->moving == 1)
			continue;
		if (game->entities[i]->y == line)
			game->entities[i]->display = 0;
		for (int n = 0; n < game->entities[i]->len; n++) {
			if (game->entities[i]->cells[n].x == 0 &&
				game->entities[i]->cells[n].y == 0)
				continue;
			if (game->entities[i]->y
				+ game->entities[i]->cells[n].y == line) {
				game->entities[i]->cells[n].x = 0;
				game->entities[i]->cells[n].y = 0;
			}
		}
	}
	entities_gravity(game, line);
}

void entities_gravity(struct game *game, int line)
{
	game->score += 100;
	game->lines_removed++;
	if (game->lines_removed % 10 == 0)
		game->level++;
	for (int i = 0; i < game->len; i++) {
		if (game->entities[i]->moving == 0
			&& game->entities[i]->y <= line) {
			game->entities[i]->y++;
		}
	}
}