WINDOWS_NAME = libft.lib
UNIX_NAME = libft.a

ifdef OS
NAME = $(WINDOWS_NAME)
else
NAME = $(UNIX_NAME)
endif

SRC_DIR = source
SRC_FILES = debug.c read_entire_file.c\
	letter.c char.c\
	str_to_number.c\
	putchar.c putstr.c putnbr.c\
	file/open_close.c file/read_write.c\
	math/random.c math/sign.c math/min_max.c math/clamp.c\
	math/ieee754.c math/round.c math/lerp.c\
	string/memchr.c string/memcmp.c string/memcpy.c string/memset.c string/count_chars.c\
	string/strchr.c string/strcmp.c string/strcpy.c string/strdup.c string/strstr.c\
	string/pstr.c string/split.c\
	builder/builder.c builder/append.c\
	lexer/lexer.c lexer/spaces.c lexer/string.c lexer/integer.c\
	memory/alloc.c memory/heap.c memory/arena.c memory/arena_page.c\
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

ifdef OS	# This environment variable is only defined on Windows

OBJ_FILES = $(SRC_FILES:.c=.obj)
CC = cl
C_FLAGS = -I. -TC -nologo -O2

else

OBJ_FILES = $(SRC_FILES:.c=.o)
CC = gcc
C_FLAGS = -Wall -Wextra -Werror -I.

endif

all: $(NAME)

.PRECIOUS: $(OBJ_DIR)/%.o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c libft.h Makefile
	@mkdir -p $(dir $@)
	$(CC) $(C_FLAGS) -c $< -o $@

.PRECIOUS: $(OBJ_DIR)/%.obj
$(OBJ_DIR)/%.obj: $(SRC_DIR)/%.c libft.h Makefile
	@mkdir -p $(dir $@)
	@$(CC) $(C_FLAGS) -c $< -Fo$(dir $@)

%.a: $(addprefix $(OBJ_DIR)/,$(OBJ_FILES))
	ar rcs $@ $(addprefix $(OBJ_DIR)/,$(OBJ_FILES))

%.lib: $(addprefix $(OBJ_DIR)/,$(OBJ_FILES))
	lib -nologo /OUT:$@ $(addprefix $(OBJ_DIR)/,$(OBJ_FILES))

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

tests/%: tests/%.c $(NAME)
	$(CC) $(C_FLAGS) $< $(NAME) -o $@
	./$@
	@rm -f $@

.PHONY: all clean fclean re
