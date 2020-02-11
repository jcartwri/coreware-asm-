# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/10 20:09:49 by jcartwri          #+#    #+#              #
#    Updated: 2020/02/10 20:32:31 by jcartwri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm
SRC = ./byte_counting.c ./check_true_arg.c ./find_name_comment.c ./friend_find_instruction.c ./ft_create_operation.c \
		./helper_work_oper.c ./instrument_check_arg.c ./instrument.c ./list_instruction.c ./one_combination_arg.c \
		./read_asembler.c ./two_combination_arg.c ./work_with_metky.c ./work_with_operations.c ./write_bytes_file.c \
		./writes_byte_file_two.c

OBJ = ./byte_counting.o ./check_true_arg.o ./find_name_comment.o ./friend_find_instruction.o ./ft_create_operation.o \
	  ./helper_work_oper.o ./instrument_check_arg.o ./instrument.o ./list_instruction.o ./one_combination_arg.o \
	  ./read_asembler.o ./two_combination_arg.o ./work_with_metky.o ./work_with_operations.o ./write_bytes_file.o \
	  ./writes_byte_file_two.o main.o

FLAGS = -Wall -Wextra -Werror
LIBRF = ./lib/printf/libftprintf.a
LIBRL = ./lib/printf/libft/libft.a

all: $(NAME)

$(NAME):
		@make re -C ./lib/printf/
		@gcc -c $(SRC) ./main.c
		@gcc $(LIBRF) $(LIBRL) $(FLAGS) $(OBJ) -o $(NAME)

clean:
		make clean -C ./lib/printf
		@rm -f $(OBJ)

fclean: clean
		make fclean -C ./lib/printf
		@rm -f asm

re: fclean all
