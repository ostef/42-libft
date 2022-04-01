NAME = libft.a
SRC_DIR = source
SRC_FILES = debug.c file.c\
	letter.c char.c\
	str_to_number.c\
	putchar.c putstr.c putnbr.c\
	math/random.c math/sign.c math/min_max.c math/clamp.c\
	math/ieee754.c math/round.c math/lerp.c\
	string/memchr.c string/memcmp.c string/memcpy.c string/memset.c string/count_chars.c\
	string/strchr.c string/strcmp.c string/strcpy.c string/strdup.c string/strstr.c\
	string/pstr.c string/split.c\
	lexer/lexer.c lexer/spaces.c lexer/string.c lexer/integer.c\
	memory/alloc.c memory/heap.c memory/arena.c memory/temp.c\
	fmt/print.c fmt/sprint.c fmt/fprint.c\
	fmt/buff.c fmt/arg.c fmt/read_fmt.c\
	fmt/specifiers/sprint_c.c\
	fmt/specifiers/sprint_s.c\
	fmt/specifiers/sprint_i.c\
	fmt/specifiers/sprint_u.c\
	fmt/specifiers/sprint_b.c\
	fmt/specifiers/sprint_x.c\
	fmt/specifiers/sprint_p.c\
	fmt/specifiers/sprint_n.c\
	fmt/specifiers/sprint_a.c\
	fmt/specifiers/sprint_m.c
OBJ_DIR = obj
OBJ_FILES = $(SRC_FILES:.c=.o)
CC = gcc
C_FLAGS = -Wall -Wextra -Werror -I.

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c libft.h Makefile
	@mkdir -p $(dir $@)
	$(CC) $(C_FLAGS) -c $< -o $@

$(NAME): $(addprefix $(OBJ_DIR)/,$(OBJ_FILES))
	ar rcs $(NAME) $(addprefix $(OBJ_DIR)/,$(OBJ_FILES))

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

tests/%: tests/%.c $(NAME)
	$(CC) $(C_FLAGS) $< $(NAME) -o $@
	./$@
	@rm -f $@

.PHONY: all norme clean fclean re
