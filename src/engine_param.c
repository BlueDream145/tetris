/*
** EPITECH PROJECT, 2018
** engine_param.c
** File description:
**
*/

#include "constants.h"
#include "tetris.h"

int dispatch_params(struct game *game, int ac, char **as)
{
	int callback;

	for (int i = 1; i < ac; i++) {
		if (string_len(as[i], '=') == 0) {
			if ((callback =
				manage_composed_param(game, as[i], as[i + 1]))
				!= 1)
				return (callback);
			else
				continue;
		} else if (string_len(as[i], '=') == 1) {
			if ((callback =
				manage_simple_param(game, as[i])
				!= 1))
				return (callback);
			else
				continue;
		}
		return (84);
	}
	return (1);
}

int manage_composed_param(struct game *game, char *str, char *next)
{
	if (my_strcmp(str, "-w") == 0
		|| my_strcmp(str, "--without-next") == 0)
			game->enable_preview = 0;
	if (my_strcmp(str, "-D") == 0
		|| my_strcmp(str, "--debug") == 0)
			game->display_debug = 1;
	if (my_strcmp(str, "--help") == 0)
			game->display_help = 1;
	if (next == NULL)
		return (1);
	for (int i = 0; i < 8; i++) {
		if (my_strncmp(str, composed_flags[i],
			my_strlen(composed_flags[i])) == 0)
			game->handlers[i](game, next);
	}
	return (1);
}

int manage_simple_param(struct game *game, char *str)
{
	char *result;

	for (int i = 0; i < 8; i++)
		if (my_strncmp(str, simple_flags[i],
			my_strlen(simple_flags[i])) == 0) {
			result = malloc(sizeof(char) *
			(my_strlen(str) - my_strlen(simple_flags[i]) + 1));
			if (result == NULL)
				return (0);
			my_strncpy(result, str, my_strlen(simple_flags[i]),
			my_strlen(str) - my_strlen(simple_flags[i]) + 1);
			game->handlers[i](game, result);
			free(result);
		}
	return (1);
}