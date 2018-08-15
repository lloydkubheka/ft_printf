

NAME = libftprintf.a

RED         = \033[1;91m
GREEN       = \033[1;92m
CYAN        = \033[1;96m

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar
INC = -I ./include

FILES = ft_printf.c ft_conversion.c \
		printf_d.c printf_xsp.c printf_cou.c \
		printf_utils.c printf_len_base.c \
		printf_toa_base_1.c printf_toa_base_2.c \
		printf_strlen_str_char.c \
		printf_wchar.c printf_wchar_utils.c \
		printf_lld.c printf_ulld.c \
		printf_d_hhd.c printf_ud_uhhd.c printf_color.c \
		ft_strncmp.c

OBJ = $(addprefix build/, $(FILES:.c=.o))
SRC = $(addprefix src/, $(FILES))


.PHONY: all clean fclean re test

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) crs $@ $^
	@echo "$(GREEN)Creating $(NAME)$(CYAN)"

build/%.o: src/%.c | build
	@echo "$(GREEN)Making object file $@$(CYAN)"
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

build:
	mkdir build

clean:
	@rm -rf build
	@echo "$(GREEN)clean successful$(CYAN)"

fclean: clean
	@echo "$(RED)Removing $(NAME)$(RED)"
	rm -f $(NAME)

re: fclean all
