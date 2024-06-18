/*
** EPITECH PROJECT, 2018
** display.c
** File description:
**
*/

#include "tetris.h"

void display_board(struct game *game)
{
	const int square_size = 15;

	mvhline(1, 5, 0, game->map_width);
	mvhline(game->map_height, 5, 0, game->map_width);
	mvvline(1, 5, 0, game->map_height - 1);
	mvvline(1, game->map_width + 5, 0, game->map_height - 1);
	mvaddch(1, 5, ACS_ULCORNER);
	mvaddch(1, game->map_width + 5, ACS_URCORNER);
	mvaddch(game->map_height, 5, ACS_LLCORNER);
	mvaddch(game->map_height, game->map_width + 5, ACS_LRCORNER);
	mvhline(1, 10 + game->map_width, 0, square_size);
	mvhline(square_size / 2, 10 + game->map_width, 0, square_size);
	mvvline(1, 10 + game->map_width, 0, square_size / 2);
	mvvline(1, 10 + game->map_width + square_size, 0, square_size / 2);
	mvaddch(1, game->map_width + 10, ACS_ULCORNER);
	mvaddch(1, game->map_width + 10 + square_size, ACS_URCORNER);
	mvaddch(square_size / 2, game->map_width + 10, ACS_LLCORNER);
	mvaddch(square_size / 2, game->map_width + 10 + square_size,
		ACS_LRCORNER);
}

void display_text(struct game *game)
{
	write_text("# Score :", game->map_width + 10, 10);
	write_text("# Level :", game->map_width + 10, 11);
	write_text("# Lines :", game->map_width + 10, 12);
	write_text("# Time  :", game->map_width + 10, 14);
	write_text(itc(game->score), game->map_width + 28, 10);
	write_text(itc(game->level), game->map_width + 28, 11);
	write_text(itc(game->lines_removed), game->map_width + 28, 12);
	write_text(itc(game->elapsed_time), game->map_width + 28, 14);
	write_text("*** *** *** *** * ***", game->map_width + 30, 2);
	write_text(" *  *    *  * *   *  ", game->map_width + 30, 3);
	write_text(" *  **   *  **  * ***", game->map_width + 30, 4);
	write_text(" *  *    *  * * *   *", game->map_width + 30, 5);
	write_text(" *  ***  *  * * * ***", game->map_width + 30, 6);
}

void display_entities(struct game *game)
{
	for (int i = 0; i < game->len; i++) {
		attron(COLOR_PAIR(game->entities[i]->color));
		if (game->entities[i]->display == 1)
			mvaddch(game->entities[i]->y,
				game->entities[i]->x, '*');
		for (int n = 0; n < game->entities[i]->len; n++) {
			if (game->entities[i]->cells[n].y == 0 &&
				game->entities[i]->cells[n].x == 0)
				continue;
			mvaddch(game->entities[i]->y
				+ game->entities[i]->cells[n].y,
				game->entities[i]->x
				+ game->entities[i]->cells[n].x, '*');
		}
		attroff(COLOR_PAIR(game->entities[i]->color));
	}
}

void display_preview(struct game *game)
{
	const int y = 2;
	int x = game->map_width + 16;
	struct entity *entity = game->preview;

	if (game->enable_preview == 0)
		return;
	attron(COLOR_PAIR(entity->color));
	mvaddch(y, x, '*');
	for (int n = 0; n < entity->len; n++) {
		if (entity->cells[n].y == 0 &&
			entity->cells[n].x == 0)
			continue;
		mvaddch(y + entity->cells[n].y,
			x + entity->cells[n].x, '*');
	}
	attroff(COLOR_PAIR(entity->color));
}

void write_text(const char *str, int x, int y)
{
	for (int i = 0; str[i]; i++)
		mvaddch(y, x + i, str[i]);
}