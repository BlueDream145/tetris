/*
** EPITECH PROJECT, 2018
** engine_game.c
** File description:
**
*/

#include "tetris.h"

void game_count(struct game *game)
{
	if (moving_entity_exists(game) == 0)
		insert_entity(game);
	else
		make_entity_move(game);
	check_game_finished(game);
}

void make_entity_move(struct game *game)
{
	int line = 0;

	for (int i = 0; i < game->len; i++) {
		if (game->entities[i]->moving == 1
			&& entity_colision(game) == 1) {
				game->entities[i]->moving = 0;
				game->score += 5;
				while ((line = contain_full_line(game, 0)) > 0)
					remove_line(game, line);
				return;
		}
		if (game->entities[i]->moving == 1)
			game->entities[i]->y++;
	}
}

void check_game_finished(struct game *game)
{
	for (int i = 0; i < game->len; i++) {
		if (game->entities[i]->moving == 1)
			continue;
		if (game->entities[i]->y <= 3) {
			game->running = 0;
			return;
		}
		for (int n = 0; n < game->entities[i]->len; n++) {
			if (game->entities[i]->y +
				game->entities[i]->cells[n].y <= 3) {
				game->running = 0;
				return;
			}
		}
	}
}