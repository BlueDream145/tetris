/*
** EPITECH PROJECT, 2018
** engine_param_debug.c
** File description:
**
*/

#include "tetris.h"

void display_keys(struct game *game)
{
	const char *key_left = "Key Left : ";
	const char *key_right = "\nKey Right : ";
	const char *key_turn = "\nKey Turn : ";
	const char *key_drop = "\nKey Drop : ";
	const char *key_quit = "\nKey Quit : ";
	const char *key_break = "\nKey Pause : ";

	my_put_str(key_left);
	display_key(game->keys->key_left);
	my_put_str(key_right);
	display_key(game->keys->key_right);
	my_put_str(key_turn);
	display_key(game->keys->key_rotate);
	my_put_str(key_drop);
	display_key(game->keys->key_fall);
	my_put_str(key_quit);
	display_key(game->keys->key_leave);
	my_put_str(key_break);
	display_key(game->keys->key_break);
	my_put_char('\n');
}

void display_variables(struct game *game)
{
	const char *d_next = "Next : ";
	const char *d_level = "Level : ";
	const char *d_size = "Size : ";

	my_put_str(d_next);
	if (game->enable_preview == 0)
		my_put_str("No\n");
	else
		my_put_str("Yes\n");
	my_put_str(d_level);
	my_put_nbr(game->level);
	my_put_char('\n');
	my_put_str(d_size);
	my_put_nbr(game->map_width);
	my_put_char('*');
	my_put_nbr(game->map_height);
	my_put_char('\n');
}

void display_tetriminos(void)
{
	struct entity *entity = malloc(sizeof(struct entity));
	int *elems = get_sorted_list();
	int i = 0;

	my_put_str("Tetriminos : ");
	my_put_nbr(max_tetriminos());
	my_put_char('\n');
	while (i < max_tetriminos()) {
		debug_reader(entity, elems[i]);
		i++;
	}
	free(entity);
	free(elems);
}

void debug_reader(struct entity *entity, int i)
{
	my_put_str("Tetriminos : Name ");
	my_put_str(get_file_name(get_name(i)));
	my_put_str(" : ");
	if (get_tetriminos(entity, i) == 0)
		my_put_str("Error");
	else
		display_tetri(entity);
	my_put_char('\n');
}

void display_tetri(struct entity *entity)
{
	my_put_str("Size ");
	my_put_nbr(entity->size_y);
	my_put_char('*');
	my_put_nbr(entity->size_x);
	my_put_str(" : ");
	my_put_str("Color ");
	my_put_nbr(entity->color);
	my_put_str(" :\n");
	for (int i = 0; entity->patern[i]; i++)
		if (entity->patern[i] == '\n' && !entity->patern[i + 1])
			return;
		else
			my_put_char(entity->patern[i]);
}