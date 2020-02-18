//
// Created by kitos on 20.01.2020.
//

#include "asm.h"

static int 	ft_work_with_arg(char **mas)
{
	t_operation *oper;
	t_list_instruction *list;

	oper = ft_return_last_oper();
	list = list_instruction;
	while (list != NULL)
	{
		if (list->index == oper->index)
			break ;
		list = list->next;
	}
	if (ft_col_arg_permitted(mas, oper, list) == -1)
		return (-1);
	if (ft_true_arg(mas, oper, list) == -1)
		return (-1);
	return (1);
}

static t_operation	*ft_add_old_operation(int code_oper, int is_code_arg, int index, int flag)
{
	t_operation	*oper;

	oper = operation;
	while (oper->next != NULL)
		oper = oper->next;
	if (flag == 1)
	{
		oper->is_code_arg = is_code_arg;
		oper->code_operation = code_oper;
		oper->index = index;
	}
	else
	{
		oper->is_code_arg = 0;
		oper->code_operation = 0;
		oper->index = 0;
	}
	return (oper);
}

static int ft_cycle_oper(char *word, int *flag, int new_list, int j)
{
	t_list_instruction	*list;

	list = list_instruction;
	while (list != NULL)
	{
		if (ft_strcmp(list->name_operat, word) == 0)
		{
			if (new_list == 1 && *flag == 2)
				ft_add_new_operation(list->code_operat, list->is_code_arg, list->index, 1);
			else
			{
				*flag = 2;
				ft_add_old_operation(list->code_operat, list->is_code_arg, list->index, 1);
			}
			return (j);
		}
		list = list->next;
	}
	return (-1);
}

static	int	ft_check_true_writing_oper(char *str, int i, int *flag, int new_list)
{
	char				*word;
	int 				j;

	j = i;
	while (str[j] != '\0' && str[j] != ' ' && str[j] != '\t' && str[j] != '%' && str[j] != '-')
		j++;
	if (str[j] == '\0')
		return (-1);
	word = ft_strsub(str, i, j - i);
	j = ft_cycle_oper(word, flag, new_list, j);
	ft_strdel(&word);
	if (j != -1)
		return (j);
	ft_putstr("Error with name operation");
	return (-1);
}

char	*ft_find_normal_str(char *str)
{
	int		i;
	int		col;
	char	*new;

	i = 0;
	col = 0;
	while (str[i] != '\0' && str[i] != COMMENT_CHAR && str[i] != ALT_COMMENT_CHAR)
	{
		if (str[i] == SEPARATOR_CHAR)
			col++;
		i++;
	}
	if (col > 2)
		return (NULL);
	new = ft_strsub(str, 0, i);
	return (new);
}

int ft_check_on_instruction(char *line, int i, int *flag, int new_list)
{
	char	**mas;
	int 	j;
	char 	*str;

	i = ft_skip_space(line, i);
	if ((i = ft_check_true_writing_oper(line, i, flag, new_list)) == -1)
		return (-1);
	if ((str = ft_find_normal_str(line + i)) == NULL)
		return (-1);
	mas = ft_strsplit(str, SEPARATOR_CHAR);
	ft_strdel(&str);
	j = 0;
	while (mas && mas[j])
		j++;
	if (j > 3 || ft_work_with_arg(mas) == -1)
	{
		j = 0;
		while (mas && mas[j] != NULL)
			free(mas[j++]);
		free(mas[j]);
		free(mas);
		return (-1);
	}
	j = 0;
	while (mas && mas[j] != NULL)
		free(mas[j++]);
	free(mas[j]);
	free(mas);
	return (1);
}
