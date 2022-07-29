/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soumanso <soumanso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 12:27:46 by soumanso          #+#    #+#             */
/*   Updated: 2022/07/29 21:37:38 by soumanso         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <fcntl.h>

typedef char			t_s8;
typedef unsigned char	t_u8;
typedef short			t_s16;
typedef unsigned short	t_u16;
typedef int				t_s32;
typedef unsigned int	t_u32;
typedef long			t_s64;
typedef unsigned long	t_u64;
typedef int				t_int;
typedef unsigned int	t_uint;
typedef float			t_f32;
typedef double			t_f64;
typedef char			*t_str;
typedef const char		*t_cstr;
typedef int				t_file;
typedef t_u8			t_bool;
enum
{
	FALSE = 0,
	TRUE = 1
};

# ifndef STDIN
#  define STDIN 0
# endif

# ifndef STDOUT
#  define STDOUT 1
# endif

# ifndef STDERR
#  define STDERR 2
# endif

/* Debugging */

void		ft_debug_break(void);
void		ft_assert(t_bool assert, t_cstr fmt, ...);
void		ft_panic(t_cstr fmt, ...);

/* Memory allocation */

# ifndef TEMP_STORAGE_SIZE
#  define TEMP_STORAGE_SIZE (1048576)	/* 1 MB */
# endif

typedef struct s_arena
{
	t_u8	*mem;
	t_s64	size;
	t_s64	top;
}	t_arena;

typedef enum e_alloc_op
{
	OP_ALLOCATE = 0,
	OP_FREE = 1
}	t_alloc_op;

typedef void			*(*t_alloc_proc)(t_alloc_op, t_s64, void *, void *);

typedef struct s_alloc
{
	t_alloc_proc	proc;
	void			*data;
}	t_alloc;

void		*ft_alloc(t_s64 size, t_alloc alloc);
void		*ft_zalloc(t_s64 size, t_alloc alloc);
void		ft_free(void *ptr, t_alloc alloc);
void		*ft_realloc(void *ptr, t_s64 old_size, t_s64 size, t_alloc alloc);

t_alloc		ft_heap(void);
t_int		ft_get_heap_allocations(void);
void		*ft_heap_alloc(t_alloc_op op, t_s64 size, void *ptr, void *data);

t_alloc		ft_arena(t_arena *arena);
t_bool		ft_init_arena(t_arena *arena, t_s64 size);
void		ft_free_arena(t_arena *arena);
void		ft_reset_arena(t_arena *arena);
void		*ft_arena_alloc(t_alloc_op op, t_s64 size, void *ptr, void *data);

# ifdef USE_GLOBAL_TEMP_STORAGE

t_alloc		ft_temp(void);
void		ft_init_temp_storage(void);
void		ft_reset_temp_storage(void);
t_s64		ft_get_temp_storage_state(void);
void		ft_set_temp_storage_state(t_s64 state);

# endif

/* Math */

# define S8_MIN  0x80
# define S8_MAX  0x7f
# define U8_MAX  0xff
# define S16_MIN 0x8000
# define S16_MAX 0x7fff
# define U16_MAX 0xffff
# define S32_MIN 0x80000000
# define S32_MAX 0x7fffffff
# define U32_MAX 0xffffffff
# define S64_MIN 0x8000000000000000
# define S64_MAX 0x7fffffffffffffff
# define U64_MAX 0xffffffffffffffff
# define PI 3.1415927f

t_s64		ft_abs(t_s64 x);
t_f32		ft_absf(t_f32 x);
t_s64		ft_sign(t_s64 x);
t_f32		ft_signf(t_f32 x);
t_s64		ft_min(t_s64 a, t_s64 b);
t_f32		ft_minf(t_f32 a, t_f32 b);
t_s64		ft_max(t_s64 a, t_s64 b);
t_f32		ft_maxf(t_f32 a, t_f32 b);
t_s64		ft_clamp(t_s64 x, t_s64 min, t_s64 max);
t_f32		ft_clampf(t_f32 x, t_f32 min, t_f32 max);
t_f32		ft_floor(t_f32 x);
t_f32		ft_round(t_f32 x);
t_f32		ft_ceil(t_f32 x);
t_f32		ft_lerp(t_f32 a, t_f32 b, t_f32 t);

/* Random */

# define RNG_START 0x0173965

typedef t_int			t_rng;

void		ft_rand_seed(t_rng *rng, t_int seed);
t_int		ft_rand(t_rng *rng);
t_f32		ft_rand_rangef(t_rng *rng, t_f32 low, t_f32 high);
t_int		ft_rand_rangei(t_rng *rng, t_int low, t_int high);

/* IEEE 754 */

# define F32_EXP_BIAS 127
# define F64_EXP_BIAS 1023

void		ft_decompose_f32(t_f32 x, t_u32 *s, t_u32 *e, t_u32 *m);
t_bool		ft_is_nan(t_f32 x);
t_bool		ft_is_inf(t_f32 x);
t_f32		ft_nan32(void);
t_f32		ft_inf32(void);

/* Char */

# define BINARY "01"
# define OCTAL "0123456789"
# define DECIMAL "0123456789"
# define HEX "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"

char		ft_to_lower(char c);
char		ft_to_upper(char c);
t_bool		ft_is_lower(char c);
t_bool		ft_is_upper(char c);
t_bool		ft_is_alpha(char c);
t_bool		ft_is_digit(char c);
t_bool		ft_is_digit_of_base(char c, t_cstr base);
t_bool		ft_is_alnum(char c);
t_bool		ft_is_space(char c);

/* String */

typedef struct s_pstr
{
	t_str	data;
	t_s64	len;
}	t_pstr;

typedef struct s_pcstr
{
	t_cstr	data;
	t_s64	len;
}	t_pcstr;

t_pstr		ft_pstr(t_str data, t_s64 len);
t_pcstr		ft_pcstr(t_cstr data, t_s64 len);

void		*ft_memcpy(void *dst, const void *src, t_s64 n);
void		*ft_memmove(void *dst, const void *src, t_s64 n);
void		*ft_memset(void *dst, t_u8 c, t_s64 n);
t_int		ft_memcmp(const void *p1, const void *p2, t_s64 n);
t_bool		ft_memequ(const void *p1, const void *p2, t_s64 n);
const void	*ft_memchr(const void *p, t_u8 c, t_s64 n);
const void	*ft_memrchr(const void *p, t_u8 c, t_s64 n);

t_s64		ft_strlen(t_cstr s);
t_int		ft_strcmp(t_cstr s1, t_cstr s2);
t_int		ft_strncmp(t_cstr s1, t_cstr s2, t_s64 n);
t_bool		ft_strequ(t_cstr s1, t_cstr s2);
t_bool		ft_strnequ(t_cstr s1, t_cstr s2, t_s64 n);
t_str		ft_strcpy(t_str dst, t_cstr src);
t_str		ft_strncpy(t_str dst, t_cstr src, t_s64 n);
t_str		ft_strdup(t_cstr s, t_alloc alloc);
t_str		ft_strndup(t_cstr s, t_s64 n, t_alloc alloc);
t_cstr		ft_strchr(t_cstr s, char c);
t_cstr		ft_strnchr(t_cstr s, char c, t_s64 n);
t_cstr		ft_strrchr(t_cstr s, char c);
t_cstr		ft_strnrchr(t_cstr s, char c, t_s64 n);
t_cstr		ft_strstr(t_cstr s, t_cstr needle);
t_cstr		ft_strnstr(t_cstr s, t_cstr needle, t_s64 n);
t_cstr		ft_strrstr(t_cstr s, t_cstr needle);
t_cstr		ft_strnrstr(t_cstr s, t_cstr needle, t_s64 n);
t_int		ft_count_chars(t_cstr str, char c, t_s64 n);
t_pcstr		*ft_split(t_cstr str, char c, t_alloc alloc);

/* String convert */

/* Convert a string to an integer/boolean type.
 * `s`:		string to convert,
 * `out`:	output value.
 * Return value:
 * The number of characters that have been read from `s`.
 */
t_s64		ft_str_to_s64(t_cstr s, t_s64 *out);
t_s64		ft_str_to_int(t_cstr s, t_int *out);
t_s64		ft_str_to_u64(t_cstr s, t_u64 *out);
t_s64		ft_str_to_uint(t_cstr s, t_uint *out);
t_s64		ft_str_to_bool(t_cstr s, t_bool *out);

/* Lexer */

typedef enum e_token_kind
{
	TK_UNKNOWN = 0,
	TK_SPACES,
	TK_CHAR,
	TK_STRING,
	TK_QUOTED_STR,
	TK_DELIMITED,
	TK_SPACE_DELIM,
	TK_IDENTIFIER,
	TK_INTEGER
}	t_token_kind;

typedef struct s_token
{
	t_token_kind	kind;
	char			c;
	char			quote;
	char			delim;
	t_s64			len;
	t_cstr			str;
	t_s64			integer;
	struct s_token	*prev;
	struct s_token	*next;
}	t_token;

typedef struct s_lexer
{
	t_cstr	start;
	t_cstr	curr;
	t_cstr	end;
	t_token	*first_token;
	t_token	*last_token;
	t_alloc	allocator;
}	t_lexer;

void		ft_lexer_init(t_lexer *lexer, t_cstr str, t_alloc allocator);
void		ft_lexer_init_n(t_lexer *lexer, t_cstr str, t_s64 len,
				t_alloc allocator);
t_bool		ft_lexer_is_valid(t_lexer *lexer);
t_token		*ft_lexer_push_token(t_lexer *lexer);
t_token		*ft_lexer_skip_spaces(t_lexer *lexer);
t_token		*ft_lexer_skip_char(t_lexer *lexer, char c);
t_token		*ft_lexer_skip_string(t_lexer *lexer, t_cstr str);
t_token		*ft_lexer_skip_quoted_str(t_lexer *lexer);
t_token		*ft_lexer_skip_space_delim(t_lexer *lexer);
t_token		*ft_lexer_skip_delim(t_lexer *lexer, t_cstr delim);
t_token		*ft_lexer_return_string_before_delim(t_lexer *lexer, t_cstr delim);
t_token		*ft_lexer_skip_identifier(t_lexer *lexer);
t_bool		ft_lexer_is_integer(t_lexer *lexer);
t_token		*ft_lexer_skip_integer(t_lexer *lexer);

/* Output */

t_s64		ft_fputchar(t_file f, char c);
t_s64		ft_fputstr(t_file f, t_cstr s);
t_s64		ft_fputstrn(t_file f, t_cstr s, t_s64 n);
t_s64		ft_fputnbr(t_file f, t_s64 n);
t_s64		ft_putchar(char c);
t_s64		ft_putstr(t_cstr s);
t_s64		ft_putstrn(t_cstr s, t_s64 n);
t_s64		ft_putnbr(t_s64 n);

/* File */

t_str		ft_read_entire_file(t_cstr filename, t_alloc alloc);

/* String formatting */

typedef struct s_buff
{
	char	*data;
	t_s64	count;
}	t_buff;

typedef enum e_fmt_flags
{
	FLAG_NONE = 0x00,
	FLAG_LJUSTIFY = 0x01,
	FLAG_SIGN = 0x02,
	FLAG_SPACE = 0x04,
	FLAG_HASH = 0x08,
	FLAG_ZPAD = 0x10,
	FLAG_ESCAPED = 0x20
}	t_fmt_flags;

typedef enum e_fmt_width
{
	WIDTH_ARG = -2,
	WIDTH_DEFAULT = -1
}	t_fmt_width;

typedef enum e_fmt_precision
{
	PREC_ARG = -2,
	PREC_DEFAULT = -1
}	t_fmt_precision;

struct					s_fmt_arg;

typedef t_s64			(*t_fmt_func) (t_buff *, struct s_fmt_arg, va_list);

typedef struct s_fmt_arg
{
	t_fmt_flags		flags;
	t_fmt_width		width;
	t_fmt_precision	precision;
	char			specifier;
	t_fmt_func		func;
}	t_fmt_arg;

t_s64		ft_putchars_buff(t_buff *buff, char c, t_s64 len, t_bool escape);
t_s64		ft_putchar_buff(t_buff *buff, char c, t_bool escape);
t_s64		ft_putstr_buff(t_buff *buff, t_cstr s, t_bool escape);
t_s64		ft_putstrn_buff(t_buff *buff, t_cstr s, t_s64 len, t_bool escape);
t_s64		ft_putuint_buff(t_buff *buff, t_u64 n, t_int min, t_cstr base);

t_s64		ft_next_arg(t_cstr fmt, t_buff *buff, va_list va);
t_s64		ft_read_arg(t_cstr fmt, t_fmt_arg *arg, va_list va);

t_s64		ft_sprint_c(t_buff *buff, t_fmt_arg arg, va_list va);
t_s64		ft_sprint_s(t_buff *buff, t_fmt_arg arg, va_list va);
t_s64		ft_sprint_p(t_buff *buff, t_fmt_arg arg, va_list va);
t_s64		ft_sprint_i(t_buff *buff, t_fmt_arg arg, va_list va);
t_s64		ft_sprint_u(t_buff *buff, t_fmt_arg arg, va_list va);
t_s64		ft_sprint_x(t_buff *buff, t_fmt_arg arg, va_list va);
t_s64		ft_sprint_b(t_buff *buff, t_fmt_arg arg, va_list va);
t_s64		ft_sprint_n(t_buff *buff, t_fmt_arg arg, va_list va);
t_s64		ft_sprint_a(t_buff *buff, t_fmt_arg arg, va_list va);
t_s64		ft_sprint_m(t_buff *buff, t_fmt_arg arg, va_list va);

t_s64		ft_vsprint(t_str buff, t_cstr fmt, va_list va);
t_s64		ft_sprint(t_str buff, t_cstr fmt, ...);
t_s64		ft_vsprintln(t_str buff, t_cstr fmt, va_list va);
t_s64		ft_sprintln(t_str buff, t_cstr fmt, ...);
t_s64		ft_vfprint(t_file f, t_cstr fmt, va_list va);
t_s64		ft_fprint(t_file f, t_cstr fmt, ...);
t_s64		ft_vfprintln(t_file f, t_cstr fmt, va_list va);
t_s64		ft_fprintln(t_file f, t_cstr fmt, ...);
t_s64		ft_vprint(t_cstr fmt, va_list va);
t_s64		ft_print(t_cstr fmt, ...);
t_s64		ft_vprintln(t_cstr fmt, va_list va);
t_s64		ft_println(t_cstr fmt, ...);
t_str		ft_fmt(t_alloc alloc, t_str fmt, ...);

/* String builder */

typedef struct s_builder
{
	t_str	data;
	t_s64	len;
	t_s64	cap;
	t_alloc	allocator;
}	t_builder;

void		ft_builder_init(t_builder *builder, t_s64 cap, t_alloc allocator);
void		ft_builder_reset(t_builder *builder);
void		ft_builder_grow(t_builder *builder, t_s64 add_cap);
t_s64		ft_builder_append_char(t_builder *builder, char c);
t_s64		ft_builder_append_len(t_builder *builder, t_cstr str, t_s64 len);
t_s64		ft_builder_append(t_builder *builder, t_cstr str);
t_s64		ft_builder_append_fmt(t_builder *builder, t_cstr fmt_str, ...);
t_str		ft_builder_build(t_builder *builder);

#endif
