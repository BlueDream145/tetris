/*
** EPITECH PROJECT, 2018
** engine_param_adapter.c
** File description:
**
*/

#include "tetris.h"

void display_key(int ch)
{
	if (key_to_str(ch) == NULL)
		my_put_char(ch);
	else
		my_put_str(key_to_str(ch));
}

int str_to_key(char *str)
{
	if (my_strcmp(str, "(space)") == 0)
		return ((int)' ');
	if (my_strcmp(str, "KEY_TOP") == 0)
		return (259);
	if (my_strcmp(str, "KEY_BOT") == 0)
		return (258);
	if (my_strcmp(str, "KEY_LEFT") == 0)
		return (260);
	if (my_strcmp(str, "KEY_RIGHT") == 0)
		return (261);
	return (0);
}

char *key_to_str(int ch)
{
	if (ch == ' ')
		return ("(space)");
	if (ch == 259)
		return ("KEY_TOP");
	if (ch == 258)
		return ("KEY_BOT");
	if (ch == 260)
		return ("KEY_LEFT");
	if (ch == 261)
		return ("KEY_RIGHT");
	return (NULL);
}