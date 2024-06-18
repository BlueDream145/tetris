/*
** EPITECH PROJECT, 2017
** main.c
** File description:
**
*/

#include "tetris.h"

int main(int ac, char **as)
{
	struct game *game;

	srand(time(NULL));
	if (available_tetriminos() == 0 || max_tetriminos() == 0)
		return (0);
	game = get_game_instance();
	prepare_handler(game);
	if (game == NULL || dispatch_params(game, ac, as) == 84)
		return (84);
	game->lines_removed = 0;
	if (game->display_help == 1)
		help(as[0]);
	else {
		if (game->display_debug == 1)
			debug(game);
		process_game(game);
	}
	if (game->pause == 1)
		return (84);
	free_instance(game);
	return (0);
}

void debug(struct game *game)
{
	const char *header = "*** DEBUG MODE ***\n";
	const char *footer = "Press any key to start Tetris\n";

	my_put_str(header);
	display_keys(game);
	display_variables(game);
	display_tetriminos();
	my_put_str(footer);
	my_getchar();
}

void help(char *app_name)
{
	const char *content = " --help               Display this help\n"
	" -L --level={num}     Start Tetris at level num (def: 1)\n"
	" -l --key-left={K}    Move the tetrimino LEFT using the K key "
		"(def: left arrow)\n"
	" -r --key-right={K}   Move the tetrimino RIGHT using the K key "
		"(def: right arrow)\n"
	" -t --key-turn={K}    TURN the tetrimino clockwise 90d using the K "
		"key (def: top arrow)\n"
	" -d --key-drop={K}    DROP the tetrimino using the K key "
		"(def: down arrow)\n"
	" -q --key-quit={K}    QUIT the game using the K key (def: `q' "
		"key)\n"
	" -p --key-pause={K}   PAUSE/RESTART the game using the K key (def: "
		"space bar)\n"
	" --map-size={row,col} Set the numbers of rows and columns of the "
		"map (def: 20,10)\n"
	" -w --without-next    Hide next tetrimino (def: false)\n"
	" -D --debug           Debug mode (def: false)\n";

	help_header(app_name);
	my_put_str(content);
}

void help_header(char *app_name)
{
	const char *help = "Usage: ";
	const char *content = " [options]\nOptions:\n";

	my_put_str(help);
	my_put_str(app_name);
	my_put_str(content);
}