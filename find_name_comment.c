//
// Created by kitos on 08.02.2020.
//

#include "asm.h"

int ft_string_command_name(char *str, int *flag)
{
	int i;

	i = ft_skip_space(str, 0);
	if (ft_mystrcmp(str + i, NAME_CMD_STRING) != 1)
	{
		ft_putstr("Error with name\n");
		return (-1);
	}
	*flag += 1;
	i += ft_strlen(NAME_CMD_STRING);
	i = ft_skip_space(str, i);
	if (ft_check_com_value(str, i) == -1)
	{
		ft_putstr("Error with name\n");
		return (-1);
	}
	if ((name = ft_strcopy_name_comment(str, i, 0)) == NULL)
	{
		ft_putstr("Error with name\n");
		return (-1);
	}
	return (1);
}

int ft_string_command_comment(char *str, int *flag)
{
	int i;

	i = ft_skip_space(str, 0);
	if (ft_mystrcmp(str + i, COMMENT_CMD_STRING) != 1)
	{
		ft_putstr("Error with comment\n");
		return (-1);
	}
	*flag += 1;
	i += ft_strlen(COMMENT_CMD_STRING);
	i = ft_skip_space(str, i);
	if (ft_check_com_value(str, i) == -1)
	{
		ft_putstr("Error with comment\n");
		return (-1);
	}
	if ((comment = ft_strcopy_name_comment(str, i, 1)) == NULL)
	{
		ft_putstr("Error with comment\n");
		return (-1);
	}
	return (1);
}

int ft_sting_empty_comment(char *str)
{
	int i;

	i = 0;
	if (str == NULL || str[0] == '\0')
		return (1);
	while ((str[i] != '\0') && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (str[i] == COMMENT_CHAR)
		return (1);
    i = ft_skip_space(str, i);
    if (str[i] == '\0')
        return (1);
	return (-1);
}