//
// Created by kitos on 20.01.2020.
//

#include "asm.h"

long long	ft_llatoi(const char *str)
{
	int					i;
	unsigned long long	res;
	int					sign;

	i = 0;
	res = 0;
	sign = 1;
	if (*str == '\0')
		return (0);
	while (str[i] == ' ' || str[i] == '\v' || str[i] == '\n' || \
		str[i] == '\f' || str[i] == '\t' || str[i] == '\r')
		++i;
	(str[i] == '-') ? sign *= -1 : sign;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] == '0')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + str[i] - 48;
		++i;
	}
	if (res > 9223372036854775807)
	{
		return (sign < 0) ? 0 : -1;
	}
	return (res * sign);
}

int ft_record_value(t_operation *oper, char **mas_arg, int j, int i)
{
	long long			a;
	t_list_instruction	*list;

	a = ft_llatoi(mas_arg[i] + j);
	if (i == 0)
		oper->value1 = a;
	else if (i == 1)
		oper->value2 = a;
	else
		oper->value3 = a;
	j += ft_col_number(a, mas_arg, i, j);
	j = ft_skip_space(mas_arg[i], j);
	list = list_instruction;
	while (list != NULL && list->index != oper->index)
		list = list->next;
	if (ft_check_cooment(list, mas_arg, i, j) == 1)
		return (1);
	if (mas_arg[i][j] == '\0')
		return (1);
	return (-1);
}

int ft_record_value_reg(t_operation *oper, char **mas_arg, int j, int i)
{
	int					a;
	t_list_instruction	*list;

	a = ft_atoi(mas_arg[i] + j);
	if (a < 1 || a > REG_NUMBER)
		return (-1);
	if (i == 0)
		oper->value1 = a;
	else if (i == 1)
		oper->value2 = a;
	else
		oper->value3 = a;
	j = j + ft_col_number(a, mas_arg, i, j);
	j = ft_skip_space(mas_arg[i], j);
	list = list_instruction;
	while (list != NULL && list->index != oper->index)
		list = list->next;
	if (ft_check_cooment(list, mas_arg, i, j) == 1)
		return (1);
	if (mas_arg[i][j] == '\0')
		return (1);
	return (-1);
}

int ft_reg(t_list_instruction *list, t_operation *oper, int i, char	**mas_arg)
{
	int	j;

//    j = ft_skip_space(mas_arg[i], j);
	if (list->params[i] != 1)
		return (0);
	num_arg++;
	code_type_arg[(num_arg - 1) * 2] = '0';
	code_type_arg[(num_arg - 1) * 2 + 1] = '1';
	j = ft_skip_space(mas_arg[i], 0);
	if (mas_arg[i][j] != 'r')
		return (-1);
	oper->size_arg[i] += 1;
	return (ft_record_value_reg(oper, mas_arg, j + 1, i));
}

int ft_dir(t_list_instruction *list, t_operation *oper, int i, char	**mas_arg)
{
	int		j;

	if (list->params[i] != 2)
		return (0);
	num_arg++;
	code_type_arg[(num_arg - 1) * 2] = '1';
	code_type_arg[(num_arg - 1) * 2 + 1] = '0';
	j = ft_skip_space(mas_arg[i], 0);
	if (mas_arg[i][j] != DIRECT_CHAR)
		return (-1);
	oper->size_arg[i] += list->size_tdir;
	if (mas_arg[i][j + 1] == LABEL_CHAR)
		return (ft_add_mas_label_arg(oper, i, mas_arg, j + 2));
	return (ft_record_value(oper, mas_arg, j + 1, i));
}

int ft_ind(t_list_instruction *list, t_operation *oper, int i, char	**mas_arg)
{
	int j;

	if (list->params[i] != 3)
		return (0);
	num_arg++;
	code_type_arg[(num_arg - 1) * 2] = '1';
	code_type_arg[(num_arg - 1) * 2 + 1] = '1';
	j = ft_skip_space(mas_arg[i], 0);
	if ((mas_arg[i][j] >= '0' && mas_arg[i][j] <= '9') || (mas_arg[i][j] == '-' &&
		mas_arg[i][j + 1] >= '0' && mas_arg[i][j + 1] <= '9'))
		return (-1);
	oper->size_arg[i] += 2;
	return (ft_record_value(oper, mas_arg, j, i));
}
