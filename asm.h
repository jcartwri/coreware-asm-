//
// Created by kitos on 15.01.2020.
//

#ifndef ASM_H
#define ASM_H

#include "./lib/printf/ft_printf.h"
#include "./lib/printf/libft/libft.h"
#include "./lib/printf/libft/get_next_line.h"
#include "op.h"

#include <fcntl.h>
#include <stdlib.h>

typedef struct					s_operation
{
  		int 					index;   // индех инструкции
  		int						label_flag; // есть ли метка для этой инструкции да - 1 нет - 0
  		int						size_instruction; // размер  инструкции
  		int 					size_arg[3];
  		char					**label_names; // имя если label-flag == 1
		int						code_operation; // код с dinamic памятью
		int 					is_code_arg; // есть ли код для аргументов 1 - да 0 - нет
		int 					value1;
		int 					value2;
		int 					value3;
		char 					*mas_label_arg1;
  		char 					*mas_label_arg2;
  		char 					*mas_label_arg3; //массив name label потом index arg;
		int 					code_type_arg;
		int 					col_arg;
  		struct s_operation		*next;
}								t_operation;

typedef struct					s_list_instruction
{
  		int 					index;
  		char					*name_operat;
  		int 					params[3];
  		int						size_tdir;
  		int						carry;
  		int						code_operat;
  		int 					is_code_arg;
  		struct s_list_instruction	*next;
}								t_list_instruction;

char							*name;
char							*comment;
t_list_instruction				*list_instruction;
t_operation						*operation;
int 							num_arg;
char 							code_type_arg[9];

int								main(int argc, char **argv);
void							ft_counting_size_instruction(void);
char							*ft_get_str_label(t_operation *oper, int i);
void							ft_insert_value(t_operation *oper, int i, int value);
int								ft_read_asembler(char *line, int *flag);
int								ft_skip_space(char *str, int index);
int								ft_mystrcmp(char *str1, char *str2);
char							*ft_strcopy_name_comment(char *str, int i, int a);
int								ft_check_com_value(char *str, int i);
t_operation						*ft_add_new_operation(int code_oper, int is_code_arg, int index, int flag);
t_list_instruction				*ft_create_list_operation(char *name, int par[3], int size, int carry);
void							ft_list_instruction_one(void);
int								ft_string_command_name(char *str, int *flag);
int								ft_string_command_comment(char *str, int *flag);
int								ft_sting_empty_comment(char *str);
void							ft_strdel_split_mas(char **mas);
int								ft_check_chars_label(char c);
int								ft_check_on_metky(char *line, int index, int *flag);
t_operation						*ft_return_last_oper(void);
int								ft_col_arg_permitted(char **mas, t_operation *oper, t_list_instruction *list);
int								ft_check_on_instruction(char *line, int i, int *flag, int new_list);
int								ft_true_arg(char **mas_arg, t_operation *oper, t_list_instruction *list);
// combination
void							ft_strdel_t_oper(t_operation *oper);
int								ft_helper_check_metky(char *line, int *flag, int i, t_operation *list);
int								ft_add_mas_label_arg(t_operation *oper, int i, char	**mas_arg, int j);
char							*ft_get_name_label_arg(char *str, int i);
int								ft_col_number(int a);
int								ft_check_cooment(t_list_instruction *list, char	**mas_arg, int i, int j);
int								ft_record_value(t_operation *oper, char **mas_arg, int j, int i);
int								ft_record_value_reg(t_operation *oper, char **mas_arg, int j, int i);
int								ft_reg(t_list_instruction *list, t_operation *oper, int i, char	**mas_arg);
int								ft_dir(t_list_instruction *list, t_operation *oper, int i, char	**mas_arg);
int								ft_ind(t_list_instruction *list, t_operation *oper, int i, char	**mas_arg);
int								ft_reg_ind(t_list_instruction *list, t_operation *oper, int i, char	**mas_arg);
int								ft_dir_ind(t_list_instruction *list, t_operation *oper, int i, char	**mas_arg);
int								ft_reg_dir_ind(t_list_instruction *list, t_operation *oper, int i, char	**mas_arg);
int								ft_reg_dir(t_list_instruction *list, t_operation *oper, int i, char	**mas_arg);
char							**ft_add_one_elem_mas(char **mas, char *value);
void							ft_byte_counting(void);
char							*ft_get_name_file(char *name);
void							ft_record_magic_file(int fd, size_t size, int l);
int								ft_record_champion_name(int fd, char *str);
int								ft_write_bytes_file(char *name_file);

#endif
