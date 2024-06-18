/*
** EPITECH PROJECT, 2018
** utils.c
** File description:
**
*/

#include "tetris.h"

int crand(int a, int b)
{
	return (rand() % (b - a) + a);
}

char *itc(int nbr)
{
	int len = number_digits(nbr);
	char *result;

	result = malloc(sizeof(char) * (len + 1));
	result[len] = '\0';
	while (len--) {
		result[len] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (result);
}

int my_strcmp(char const *s1, char const *s2)
{
	int i = 0;

	for (i = 0; s1[i] && s2[i] && s1[i] == s2[i]; i++);
	return (s1[i] - s2[i]);
}

int number_digits(int nbr)
{
	int n = 1;
	int po = 10;

	if (nbr < 0)
		nbr = -nbr;
	while (nbr >= po) {
		n++;
		if (po > 214748364)
			break;
		po *= 10;
	}
	return (n);
}

char *my_strncpy(char *dest, const char *src, int start, int n)
{
	int i = start;
	int j = 0;

	while (n > 0 && src[i] != '\0') {
		dest[j] = src[i];
		j++;
		i++;
		n--;
	}
	if (n > 0)
		dest[j++] = '\0';
	return (dest);
}