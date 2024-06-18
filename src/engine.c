/*
** EPITECH PROJECT, 2018
** engine.c
** File description:
**
*/

#include "tetris.h"

void process_game(struct game *game)
{
	int len = 0;

	prepare_game(game);
	if (game->pause == 1)
		return;
	while (game->running == 1) {
		clear();
		display_board(game);
		display_text(game);
		if (len % (10 - (game->level - 1)) == 0)
			game_count(game);
		display_preview(game);
		display_entities(game);
		refresh();
		manage_getch(game, getch());
		usleep(100000);
		len++;
		if (len % 10 == 0)
			game->elapsed_time++;
	}
	end_game(game);
}

void prepare_game(struct game *game)
{
	int x;
	int y;

	initscr();
	getmaxyx(stdscr, y, x);
	if (y <= game->map_height || x <= game->map_width) {
		endwin();
		my_put_error("Please, "
			"change your terminal size and try again.\n");
		game->running = 0;
		game->pause = 1;
		return;
	}
	cbreak();
	noecho();
	keypad(stdscr, 1);
	timeout(0);
	curs_set(0);
	init_colors();
}

void end_game(struct game *game)
{
	const char *header = "You finished game with ";
	const char *footer = " points.\n";

	if (game->pause == 1) {
		while (getch() != game->keys->key_break);
		game->pause = 0;
		game->running = 1;
		process_game(game);
		return;
	}
	wclear(stdscr);
	endwin();
	my_put_str(header);
	my_put_nbr(game->score);
	my_put_str(footer);
}