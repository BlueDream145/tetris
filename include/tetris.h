/*
** EPITECH PROJECT, 2017
** file.h
** File description:
**
*/

#ifndef TETRIS_
	#define TETRIS_

	#define _DEFAULT_SOURCE
	#include <stdio.h>
	#include <stdlib.h>
	#include <unistd.h>
	#include <ncurses.h>
	#include <time.h>
	#include <sys/types.h>
	#include <sys/stat.h>
	#include <dirent.h>
	#include <fcntl.h>
	#include <string.h>

struct game {
	void (*handlers[8])(struct game *game, char *data);
	struct entity **entities;
	struct entity *preview;
	struct keys *keys;
	int display_help;
	int display_debug;
	int enable_preview;
	int map_width;
	int map_height;
	int score;
	int elapsed_time;
	int lines_removed;
	int next_type;
	int running;
	int level;
	int len;
	int step;
	int pause;
};

struct keys {
	int key_rotate;
	int key_fall;
	int key_left;
	int key_right;
	int key_break;
	int key_leave;
};

struct entity {
	struct cell *cells;
	char *patern;
	int len;
	int y;
	int x;
	int size_y;
	int size_x;
	int moving;
	int display;
	int type;
	int color;
};

struct cell {
	int x;
	int y;
};

enum colors {
	C_GREEN = 1,
	C_BLUE,
	C_RED,
	C_YELLOW,
	C_MAGENTA,
	C_WHITE,
	C_CYAN,
	C_CYANN,
	C_YELLOWW
};

	// check.c
	int string_len(char *src, char find);
	int available_tetriminos(void);

	// color.c
	void init_colors(void);

	// display.c
	void display_board(struct game *game);
	void display_text(struct game *game);
	void display_entities(struct game *game);
	void display_preview(struct game *game);
	void write_text(const char *str, int x, int y);

	// engine_colision.c
	int entity_colision(struct game *game);
	int cell_colision(struct game *game, int x, int y);

	// engine_entities.c
	void insert_entity(struct game *game);
	int moving_entity_exists(struct game *game);
	struct entity *get_moving_entity(struct game *game);
	int highest_entity(struct game *game);

	// engine_game.c
	void game_count(struct game *game);
	void make_entity_move(struct game *game);
	void check_game_finished(struct game *game);

	// engine_keys.c
	void manage_getch(struct game *game, int key);
	void handle_key(struct game *game, struct entity *current, int key);
	void handler_adv_key(struct game *game, int key);
	int entity_horizontal_colision(struct game *game, int val);
	int cell_horizontal_colision(struct game *game, int x, int y, int val);

	// engine_line.c
	int contain_full_line(struct game *game, int len);
	void remove_line(struct game *game, int line);
	void entities_gravity(struct game *game, int line);

	// engine_movement.c
	void rotate_entity(struct game *game);
	int can_rotate(struct game *game);
	int available_cell(struct game *game, int x, int y);

	// engine_param_adapter.c
	void display_key(int ch);
	char *key_to_str(int ch);
	int str_to_key(char *str);

	// engine_param_debug.c
	void display_keys(struct game *game);
	void display_variables(struct game *game);
	void display_tetriminos(void);
	void display_tetri(struct entity *entity);
	void debug_reader(struct entity *entity, int i);

	// engine_param_handler.c
	void prepare_handler(struct game *game);
	void handle_level(struct game *game, char *data);
	void handle_map_size(struct game *game, char *data);
	void handle_key_pause(struct game *game, char *data);
	void handle_key_quit(struct game *game, char *data);

	// engine_param_keys.c
	void handle_key_left(struct game *game, char *data);
	void handle_key_right(struct game *game, char *data);
	void handle_key_turn(struct game *game, char *data);
	void handle_key_drop(struct game *game, char *data);

	// engine_param_utils.c
	char *get_name(int index);
	char *get_file_name(char *full_path);
	int *get_sorted_list(void);
	int my_sort_alpha(int *elems, char **src, int success);
	int get_start_index(char *full_path);

	// engine_param.c
	int dispatch_params(struct game *game, int ac, char **as);
	int manage_composed_param(struct game *game, char *str, char *next);
	int manage_simple_param(struct game *game, char *str);

	// engine_tetriminos.c
	int max_tetriminos(void);
	int get_tetriminos(struct entity *entity, int index);
	int read_tetriminos(struct entity *entity, char *file_name);
	void process_read_tetriminos(struct entity *entity, char *file_name);
	int check_tetriminos(char *str);

	// engine_reader.c
	char *read_file(const char *file_name);
	void read_tetri(struct entity *entity, char *content, char *first_line,
		int f_y);
	int my_getchar(void);

	// engine.c
	void process_game(struct game *game);
	void prepare_game(struct game *game);
	void end_game(struct game *game);

	// instances.c
	struct game *get_game_instance(void);
	struct entity *get_entity_instance(int type);
	struct cell get_cell_instance(int x, int y);
	void free_instance(struct game *game);
	void define_keys(struct keys *keys);

	// main.c
	void debug(struct game *game);
	void help(char *app_name);
	void help_header(char *app_name);

	// string_extra.c
	char **my_str_to_word_array(const char *str, char separator);
	void split_string(const char *str, char separator,
		char **result, char *content);
	char *my_strdup(const char *src);
	char *get_line(char *str, int start);
	int my_getnbr(char *str);

	// string.c
	int my_strlen(const char *str);
	int my_strncmp(char const *s1, char const *s2, int n);
	char *my_strcat(char *dest, const char *src);
	char *my_strcpy(char *dest, const char *src);
	char *get_tetriminos_path(char *file_name);

	// output.c
	void my_put_char(char c);
	void my_put_str(const char *str);
	void my_put_error(const char *str);
	int my_put_nbr(int nb);

	// utils.c
	int crand(int a, int b);
	char *itc(int nbr);
	int number_digits(int nbr);
	int my_strcmp(char const *s1, char const *s2);
	char *my_strncpy(char *dest, const char *src, int start, int n);

#endif /* TETRIS */