//
// Created by kitos on 25.01.2020.
//

#include "asm.h"

static void	ft_record_null(int fd)
{
	int i;

	i = 0;
	while (i < 4)
	{
		write(fd, "\0", 1);
		i++;
	}
}

static int	ft_record_champion_exec_code_size(int fd)
{
	t_operation	*oper;
	int			sum;

	sum = 0;
	oper = operation;
	while (oper != NULL)
	{
		sum += oper->size_instruction;
		oper = oper->next;
	}
//	if (sum > CHAMP_MAX_SIZE)
//		return (-1);
	ft_record_magic_file(fd, 4, sum);
	return (1);
}

static int	ft_record_champion_comment(int fd, char *str)
{
	int l;
	int len;

	l = ft_strlen(str);
//	if (l > COMMENT_LENGTH)
//		return (-1);
	len = COMMENT_LENGTH - l;
	write(fd, str, l);
	while (len-- > 0)
		write(fd, "\0", 1);
	return (1);
}

static void	ft_record_champion_exec_code(int fd)
{
	t_operation	*oper;

	oper = operation;
	while (oper)
	{
		ft_record_magic_file(fd, 1, oper->code_operation);
		if (oper->is_code_arg == 1)
			ft_record_magic_file(fd, 1, oper->code_type_arg);
		if (oper->col_arg == 1)
			ft_record_magic_file(fd, oper->size_arg[0], oper->value1);
		else if (oper->col_arg == 2)
		{
			ft_record_magic_file(fd, oper->size_arg[0], oper->value1);
			ft_record_magic_file(fd, oper->size_arg[1], oper->value2);
		}
		else if (oper->col_arg == 3)
		{
			ft_record_magic_file(fd, oper->size_arg[0], oper->value1);
			ft_record_magic_file(fd, oper->size_arg[1], oper->value2);
			ft_record_magic_file(fd, oper->size_arg[2], oper->value3);
		}
		oper = oper->next;
	}
}

int		ft_write_bytes_file(char *name_file)
{
	int		fd;
	char	*str;

	str = ft_get_name_file(name_file);
	fd = open(str, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	ft_record_magic_file(fd, 4, COREWAR_EXEC_MAGIC);
	if (ft_record_champion_name(fd, name) == -1)
		return (-1);
	ft_record_null(fd);
	if (ft_record_champion_exec_code_size(fd) == -1)
		return (-1);
	if (ft_record_champion_comment(fd, comment) == -1)
		return (-1);
	ft_record_null(fd);
	ft_record_champion_exec_code(fd);
    ft_putstr("Writing output program to ");
    ft_putstr(str);
    ft_putchar('\n');
    ft_strdel(&str);
	return(1);
}

