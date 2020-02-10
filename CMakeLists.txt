cmake_minimum_required(VERSION 3.14)
project(coreware_asm_ C)

set(CMAKE_C_STANDARD 99)

file(GLOB lib/printf
        "lib/printf/*.c"
        "lib/printf/libft/*.c"
        "lib/printf/ft_printf.h"
        "lib/printf/libft/libft.h"
        "lib/printf/libft/get_next_line.h"
        )

add_executable(coreware_asm_ main.c asm.h ${lib/printf} op.h list_instruction.c read_asembler.c ft_create_operation.c work_with_metky.c work_with_operations.c check_true_arg.c one_combination_arg.c two_combination_arg.c byte_counting.c write_bytes_file.c instrument.c find_name_comment.c friend_find_instruction.c instrument_check_arg.c helper_work_oper.c writes_byte_file_two.c)