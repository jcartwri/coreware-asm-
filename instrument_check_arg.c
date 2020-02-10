//
// Created by kitos on 09.02.2020.
//

#include "asm.h"

char	**ft_add_one_elem_mas(char **mas, char *value)
{
	char	**new_mas;
	int 	i;

	i = 0;
	if (mas == NULL)
	{
		new_mas = (char **)malloc(sizeof(char *) * (2));
		new_mas[1] = NULL;
		new_mas[0] = value;
		return (new_mas);
	}
	while (mas[i])
		i++;
	new_mas = (char **)malloc(sizeof(char *) * (i + 2));
	new_mas[i + 1] = NULL;
	i = -1;
	while (mas[++i])
		new_mas[i] = mas[i];
	new_mas[i] = value;
	return (new_mas);
}

int ft_col_number(int a)
{
	int i;

	i = 0;
	while (a > 10)
	{
		a = a % 10;
		i++;
	}
	return (i + 1);
}

