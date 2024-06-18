/*
** EPITECH PROJECT, 2018
** instances.c
** File description:
**
*/

#include "tetris.h"

struct game *get_game_instance(void)
{
	const int max_entities = 300;
	struct game *game = malloc(sizeof(struct game));

	if (!game || !(game->entities = malloc(sizeof(struct entity*) *
		max_entities)) || !(game->keys = malloc(sizeof(struct keys)))
		|| max_tetriminos() == 0 || available_tetriminos() == 0)
			return (NULL);
	game->running = 1;
	game->len = 0;
	game->score = 0;
	game->elapsed_time = 0;
	game->level = 1;
	game->pause = 0;
	game->next_type = crand(0, max_tetriminos());
	game->preview = get_entity_instance(game->next_type);
	game->map_width = game->map_height = 25;
	game->enable_preview = 1;
	game->display_debug = 0;
	game->display_help = 0;
	define_keys(game->keys);
	return (game);
}

struct entity *get_entity_instance(int type)
{
	struct entity *entity = malloc(sizeof(struct entity));

	if (entity == NULL)
		return (NULL);
	entity->moving = 1;
	entity->y = 2;
	entity->x = 17;
	entity->type = type;
	entity->display = 1;
	if (available_tetriminos() == 0 || max_tetriminos() == 0)
		return (NULL);
	if (get_tetriminos(entity, entity->type) == 0) {
		free(entity);
		return (get_entity_instance(crand(0, max_tetriminos())));
	}
	return (entity);
}

void free_instance(struct game *game)
{
	if (game->preview != NULL)
		free(game->preview);
	for (int i = 0; i < game->len; i++) {
		free(game->entities[i]->patern);
		free(game->entities[i]);
	}
	free(game->entities);
	free(game);
}

struct cell get_cell_instance(int x, int y)
{
	struct cell cell;

	cell.x = x;
	cell.y = y;
	return (cell);
}

void define_keys(struct keys *keys)
{
	keys->key_rotate = 259;
	keys->key_fall = 258;
	keys->key_left = 260;
	keys->key_right = 261;
	keys->key_break = (int)' ';
	keys->key_leave = (int)'q';
}