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
//		ft_putstr("Error with name\n");
		return (-1);
	}
	*flag += 1;
	i += ft_strlen(NAME_CMD_STRING);
	i = ft_skip_space(str, i);
	if (ft_check_com_value(str, i, flag) == -1)
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

static void ft_friend_add_com(char *str, int i, int j, int flag)
{
	char	*new;
	char 	*str1;

	if (i == j && flag == 2)
		return ;
	if (i == j)
		new = ft_strdup("\n");
	else
		new = ft_strsub(str, i, j - i);
	if (comment == NULL)
		comment = new;
	else
	{
		str1 = comment;
		comment = ft_strjoin(comment, new);
		ft_strdel(&str1);
		ft_strdel(&new);
	}
}

static int ft_add_str_comment(char *str, int i, int *flag)
{
	int		j;
	char 	*str1;
//	char	*new;

	i = i + 1;
	j = i;
	while (str[j] != '\0' && str[j] != '"')
		j++;
	if (str[j] == '"')
	{
		*flag = 2;
		ft_friend_add_com(str, i, j, *flag);
		return (1);
	}
	ft_friend_add_com(str, i, j, *flag);
	if (i == j)
		return (1);
//	new = ft_strsub(str, i, j - i);
//	if (comment == NULL)
//		comment = new;
//	else
//	{
//		str1 = comment;
//		comment = ft_strjoin(comment, new);
//		ft_strdel(&str1);
//		ft_strdel(&new);
//	}
	str1 = comment;
	comment = ft_strjoin(comment, "\n");
	ft_strdel(&str1);
	return (1);
}

int ft_string_command_comment(char *str, int *flag)
{
	int i;

	if (*flag == 10)
		return (ft_add_str_comment(str, -1, flag));
	i = ft_skip_space(str, 0);
	if (ft_mystrcmp(str + i, COMMENT_CMD_STRING) != 1)
	{
		ft_putstr("Error with comment\n");
		return (-1);
	}
	*flag += 1;
	i += ft_strlen(COMMENT_CMD_STRING);
	i = ft_skip_space(str, i);
	if (ft_check_com_value(str, i, flag) == -1)
	{
		ft_putstr("Error with comment\n");
		return (-1);
	}
	if (*flag == 10)
		return (ft_add_str_comment(str, i, flag));
	else if ((comment = ft_strcopy_name_comment(str, i, 1)) != NULL)
		return (1);
	ft_putstr("Error with comment\n");
	return (-1);
}

int ft_sting_empty_comment(char *str, int flag)
{
	int i;

	i = 0;
	if (flag == 10)
		return (-1);
	if (str == NULL || str[0] == '\0')
		return (1);
	while ((str[i] != '\0') && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (str[i] == COMMENT_CHAR || str[i] == ALT_COMMENT_CHAR)
		return (1);
    i = ft_skip_space(str, i);
    if (str[i] == '\0')
        return (1);
	return (-1);
}
