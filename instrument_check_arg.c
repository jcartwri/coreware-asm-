/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instrument_check_arg.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 23:10:37 by jcartwri          #+#    #+#             */
/*   Updated: 2020/02/19 23:10:39 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	**ft_add_one_elem_mas(char **mas, char *value)
{
	char	**new_mas;
	int		i;

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

int		ft_col_number(long long a, char **mas_arg,
		int i, int j)
{
	int k;
	int flag;

	k = 0;
	flag = 0;
	if (mas_arg[i][j] == '-' && mas_arg[i][j + 1] == '0')
	{
		flag = 1;
		j++;
	}
	if (mas_arg[i][j] == '0')
	{
		while (mas_arg[i][j++] == '0')
			k++;
	}
	if (a == 0)
		return (k + flag);
	if (a < 0)
	{
		flag = 1;
		a = a * (-1);
		k += flag;
	}
	while (a != 0)
	{
		a = a / 10;
		k++;
	}
	return (k);
}
