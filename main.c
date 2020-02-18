#include <stdio.h>
#include "asm.h"

static int ft_read_with_file(int fd, int flag)
{
	char	*line;
	int		a;

	line = NULL;
	a = 0;
	while (get_next_line(fd, &line) != 0)
	{
		if (flag == 1 && a == 2)
			flag = 2;
		if (ft_sting_empty_comment(line, flag) == 1)
			ft_strdel(&line);
		else if (flag == 0 || flag == 12)
		{
			if (ft_del_return(&line, &ft_string_command_name, &flag, &a) == -1)
				return (-1);
		}
		else if (flag == 1 || flag == 10)
		{
			if (ft_del_return(&line, &ft_string_command_comment, &flag, &a) == -1)
				return (-1);
		}
		else
		{
			if (ft_del_return(&line, &ft_read_asembler, &flag, &a) == -1)
				return (-1);
		}
	}
	return (1);
}

static int ft_work_with_file(char *str)
{
	int 	fd;

	code_type_arg[8] = '\0';
	code_type_arg[7] = '0';
	code_type_arg[6] = '0';
	if ((fd = open(str, O_RDONLY)) == -1)
		return (-1);
	operation = NULL;
	ft_list_instruction_one();
	return  (ft_read_with_file(fd, 0));
}

static int ft_check_s(char *str)
{
	int i;
	int	a;

	i = -1;
	a = -1;
	if (str == NULL || str[0] == '\0')
		return (-1);
	while (str[++i] != '\0')
	{
		if (str[i] == '.')
			a = i;
	}
	if (a == -1)
		return (-1);
	if (ft_strcmp(str + i - 1, "s") == 0)
		return (1);
	return (-1);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr("ERROR with file\n");
		return (-1);
	}
	if (ft_check_s(argv[1]) == -1)
	{
		ft_putstr("ERROR with expansion file\n");
		return (-1);
	}
	if (ft_work_with_file(argv[1]) == -1)
	{
		ft_putstr("ERRRROR BRAT WHERE ARE YOU WAS???\n");
		return (-1);
	}
	if (operation == NULL)
	{
		ft_putstr("Syntax error at token\n");
		return (-1);
	}
	ft_byte_counting();
	if (ft_write_bytes_file(argv[1]) == -1)
		return (-1);
	return (1);
}