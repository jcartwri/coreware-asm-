//
// Created by kitos on 20.01.2020.
//

#include "asm.h"

int ft_reg_ind(t_list_instruction *list, t_operation *oper, int i, char	**mas_arg)
{
	int j;

	if (list->params[i] != 4)
		return (0);
	j = ft_skip_space(mas_arg[i], 0);
	num_arg++;
	if (mas_arg[i][j] >= '0' && mas_arg[i][j] <= '9')
	{
		code_type_arg[(num_arg - 1) * 2] = '1';
		code_type_arg[(num_arg - 1) * 2 + 1] = '1';
		oper->size_arg[i] += 2;
		return (ft_record_value(oper, mas_arg, j, i));
	}
	else if (mas_arg[i][j] == 'r')
	{
		code_type_arg[(num_arg - 1) * 2] = '0';
		code_type_arg[(num_arg - 1) * 2 + 1] = '1';
		oper->size_arg[i] += 1;
		return (ft_record_value_reg(oper, mas_arg, j + 1, i));
	}
	else
		return (-1);
}

int ft_dir_ind(t_list_instruction *list, t_operation *oper, int i, char	**mas_arg)
{
	int j;

	if (list->params[i] != 5)
		return (0);
	j = ft_skip_space(mas_arg[i], 0);
	num_arg++;
	if (mas_arg[i][j] >= '0' && mas_arg[i][j] <= '9')
	{
		code_type_arg[(num_arg - 1) * 2] = '1';
		code_type_arg[(num_arg - 1) * 2 + 1] = '1';
		oper->size_arg[i] += 2;
		return (ft_record_value(oper, mas_arg, j, i));
	}
	else
	{
		code_type_arg[(num_arg - 1) * 2] = '1';
		code_type_arg[(num_arg - 1) * 2 + 1] = '0';
		if (mas_arg[i][j] != DIRECT_CHAR)
			return (-1);
		oper->size_arg[i] += list->size_tdir;
		if (mas_arg[i][j + 1] == LABEL_CHAR)
			return (ft_add_mas_label_arg(oper, i, mas_arg, j + 2));
		return (ft_record_value(oper, mas_arg, j + 1, i));
	}
}

static int ft_helper_ind(t_operation *oper, int i, int j, char	**mas_arg)
{
	code_type_arg[(num_arg - 1) * 2] = '1';
	code_type_arg[(num_arg - 1) * 2 + 1] = '1';
	oper->size_arg[i] += 2;
	return (ft_record_value(oper, mas_arg, j, i));
}

int ft_reg_dir_ind(t_list_instruction *list, t_operation *oper, int i, char	**mas_arg)
{
	int j;

	if (list->params[i] != 6)
		return (0);
	j = ft_skip_space(mas_arg[i], 0);
	num_arg++;
//	if (mas_arg[i][j] >= '0' && mas_arg[i][j] <= '9')
//	{
//		code_type_arg[(num_arg - 1) * 2] = '1';
//		code_type_arg[(num_arg - 1) * 2 + 1] = '1';
//		oper->size_arg[i] += 2;
//		return (ft_record_value(oper, mas_arg, j, i));
//	}
	if (mas_arg[i][j] >= '0' && mas_arg[i][j] <= '9')
		return(ft_helper_ind(oper, i, j, mas_arg));
	else if (mas_arg[i][j] == DIRECT_CHAR)
	{
		code_type_arg[(num_arg - 1) * 2] = '1';
		code_type_arg[(num_arg - 1) * 2 + 1] = '0';
		oper->size_arg[i] += list->size_tdir;
		if (mas_arg[i][j + 1] == LABEL_CHAR)
			return (ft_add_mas_label_arg(oper, i, mas_arg, j + 2));
		return (ft_record_value(oper, mas_arg, j + 1, i));
	}
	else if (mas_arg[i][j] == 'r')
	{
		code_type_arg[(num_arg - 1) * 2] = '0';
		code_type_arg[(num_arg - 1) * 2 + 1] = '1';
		oper->size_arg[i] += 1;
		return (ft_record_value_reg(oper, mas_arg, j + 1, i));
	}
	return (-1);
}

int ft_reg_dir(t_list_instruction *list, t_operation *oper, int i, char	**mas_arg)
{
	int j;

	if (list->params[i] != 7)
		return (0);
	j = ft_skip_space(mas_arg[i], 0);
	num_arg++;
	if (mas_arg[i][j] == DIRECT_CHAR)
	{
		code_type_arg[(num_arg - 1) * 2] = '1';
		code_type_arg[(num_arg - 1) * 2 + 1] = '0';
		oper->size_arg[i] += list->size_tdir;
		if (mas_arg[i][j + 1] == LABEL_CHAR)
			return (ft_add_mas_label_arg(oper, i, mas_arg, j + 2));
		return (ft_record_value(oper, mas_arg, j + 1, i));
	}
	else if (mas_arg[i][j] == 'r')
	{
		code_type_arg[(num_arg - 1) * 2] = '0';
		code_type_arg[(num_arg - 1) * 2 + 1] = '1';
		oper->size_arg[i] += 1;
		return (ft_record_value_reg(oper, mas_arg, j + 1, i));
	}
	else
		return (-1);
}
