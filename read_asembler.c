//
// Created by kitos on 17.01.2020.
//

#include "asm.h"

//void	ft_strdel_split_mas(char **mas)
//{
//	int i;
//
//	i = 0;
//	while (mas[i])
//		ft_strdel(&mas[i++]);
//}

int ft_helper_check_metky(char *line, int *flag, int i, t_operation *list)
{
	if (line[i] == '\0' || line[i] == COMMENT_CHAR)
	{
		*flag = -2;
		return (1);
	}
	if (ft_check_on_instruction(line, i, flag, 0) == -1)
	{
		ft_strdel_t_oper(list);
		return (-1);
	}
	return (1);
}

int	ft_check_cooment(t_list_instruction *list, char	**mas_arg, int i, int j)
{
	if (i == 0)
	{
		if (list->params[1] != 0 || list->params[2] != 0)
			return (-1);
	}
	else if (i == 1)
	{
		if (list->params[2] != 0)
			return (-1);
	}
	if (mas_arg[i][j] == COMMENT_CHAR || mas_arg[i][j] == '\0')
		return (1);
	return (-1);
}

int ft_read_asembler(char *line, int *flag)
{
	int	i;

	i = 0;
	i = ft_skip_space(line, i);
	if (ft_check_on_metky(line, i, flag) == -1)
		if (ft_check_on_instruction(line, i, flag, 1) == -1)
			return (-1);
	return (1);
}