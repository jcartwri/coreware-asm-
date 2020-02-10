//
// Created by kitos on 24.01.2020.
//

#include "asm.h"

static int ft_eqals_label_left(t_operation *new, t_operation *oper, int i)
{
	char	*str;
	int 	j;
	int 	sum;

	j = -1;
	str = ft_get_str_label(oper, i);
	while (new->label_names[++j])
	{
		if (ft_strcmp(str, new->label_names[j]) == 0)
			break;
	}
	if (!new->label_names[j])
		return (-1);
	sum = 0;
	while (new != oper)
	{
		sum += new->size_instruction;
		new = new->next;
	}
	ft_insert_value(oper, i, sum * (-1));
	return (1);
}

static int ft_eqals_label_right(t_operation *new, t_operation *oper, int i)
{
	char 		*str;
	int			j;
	int			sum;
	t_operation	*copy;

	j = -1;
	str = ft_get_str_label(oper, i);
	while (new->label_names[++j])
	{
		if (ft_strcmp(str, new->label_names[j]) == 0)
			break;
	}
	if (new->label_names[j] == NULL)
		return (-1);
	copy = oper;
	sum = 0;
	while (new != copy)
	{
		sum += copy->size_instruction;
		copy = copy->next;
	}
	ft_insert_value(oper, i, sum);
	return (1);
}

static int	ft_counting_size_label(t_operation	*oper, int a)
{
	t_operation	*new;
	int			i;
	int 		flag;

	i = 0;
	while (i < a)
	{
		flag = 0;
		new = operation;
		while (new != NULL)
		{
			if (new == oper)
				flag = 1;
			if (flag == 0 && new->label_flag == 1 && ft_eqals_label_left(new, oper, i) == 1)
				break;
			if (flag == 1 && new->label_flag == 1 && ft_eqals_label_right(new, oper, i) == 1)
				break;
			new = new->next;
		}
		i++;
	}
	return (1);
}

static int	ft_check_oper_on_label(t_operation *oper)
{
	int i;

	i = 0;
	if (oper->mas_label_arg1 != NULL)
		i++;
	if (oper->mas_label_arg2 != NULL)
		i++;
	if (oper->mas_label_arg3 != NULL)
		i++;
	return (i);
}

void	ft_byte_counting(void)
{
	t_operation	*oper;
	int			a;

	oper = operation;
	ft_counting_size_instruction();
	while (oper != NULL)
	{
		if ((a = ft_check_oper_on_label(oper)) == 0)
		{
			oper = oper->next;
			continue;
		}
		ft_counting_size_label(oper, a);
		oper = oper->next;
	}
}

