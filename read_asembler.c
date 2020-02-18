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

int ft_del_return(char **line, int(foo)(char *str, int *flag), int	*flag, int *a)
{
    if (foo(*line, flag) == -1)
    {
		if (*flag == 0 && *a == 0)
		{
			*flag = 1;
			if (ft_del_return(line, &ft_string_command_comment, flag, a) == -1)
				return (-1);
    		*a = 1;
    		if (*flag != 10)
			{
    			*a = 2;
    			*flag = 0;
			}
			ft_strdel(line);
			return (1);
		}
		ft_strdel(line);
        return(-1);
    }
    if (*a == 1 && *flag == 2)
	{
    	*a = 2;
    	*flag = 0;
	}
    ft_strdel(line);
    return (1);
}

int ft_helper_check_metky(char *line, int *flag, int i, t_operation *list)
{
	if (line[i] == '\0' || line[i] == COMMENT_CHAR || line[i] == ALT_COMMENT_CHAR)
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