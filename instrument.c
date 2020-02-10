//
// Created by kitos on 08.02.2020.
//

#include "asm.h"

int ft_skip_space(char *str, int index)
{
	while (str[index] != '\0' && (str[index] == ' ' || str[index] == '\t'))
		index++;
	return (index);
}

int ft_mystrcmp(char *str1, char *str2)
{
	int i;

	i = 0;
	while (str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i])
		i++;
	if (str1[i] == '\0' || str2[i] == '\0')
		return (1);
	else
		return (0);
}

char	*ft_strcopy_name_comment(char *str, int i, int a)
{
	int 	len;
	int		j;
	char 	*value;

	len = 0;
	j = i;
	while (str[++j] != '"')
	{
		len++;
		if (str[j] == '\0')
			return (NULL);
	}
	if (a == 0 && len > PROG_NAME_LENGTH)
		return (NULL);
	else if (len > COMMENT_LENGTH)
		return (NULL);
	value = (char *)malloc(sizeof(char) * (len + 1));
	value[len] = '\0';
	j = 0;
	while (str[++i] != '"')
		value[j++] = str[i];
	return (value);
}

int ft_check_com_value(char *str, int i)
{
	if (str[i++] != '"')
		return (-1);
	while (str[i] != '\0' && str[i] != '"')
		i++;
	if (str[i++] == '\0')
		return (-1);
	while (str[i] != '\0' && str[i] != COMMENT_CHAR && str[i] == ' ' && str[i] == '\t')
		i++;
	if (str[i] == '\0' || str[i] == COMMENT_CHAR)
		return (1);
	return (-1);
}