#ifndef LIBFT_H
# define LIBFT_H

# ifndef ASSERT
#  define ASSERT(x, msg) { if (!(x)) { PANIC (msg); } }
# endif

# ifndef PANIC
#  define PANIC(msg) { ft_putendl (msg); *(volatile t_int *)0 = 0xbad; }
# endif

# ifndef ABS
#  define ABS(x) ((x) < 0 ? -(x) : (x))
# endif

# ifndef MIN
#  define MIN(a, b) ((a) < (b) ? (a) : (b))
# endif

# ifndef MAX
#  define MAX(a, b) ((a) > (b) ? (a) : (b))
# endif

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
typedef t_s64			t_ssize;
typedef t_u64			t_usize;
typedef float			t_f32;
typedef double			t_f64;

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
}	t_bool;

# ifndef NULL
#  define NULL ((void *)0)
# endif

void		*ft_calloc(t_usize count, t_usize size);
void		*ft_memset(void *ptr, t_int val, t_usize n);
void		ft_bzero(void *ptr, t_usize n);
void		*ft_memcpy(void *dst, const void *src, t_usize n);
void		*ft_memccpy(void *dst, const void *src, t_int end, t_usize n);
void		*ft_memmove(void *dst, const void *src, t_usize n);
void		*ft_memchr(const void *ptr, t_int val, t_usize n);
t_int		ft_memcmp(const void *p1, const void *p2, t_usize n);
t_usize		ft_strlen(const char *str);
char		*ft_strdup(const char *str);
char		*ft_strcpy(char *dst, const char *src);
char		*ft_strncpy(char *dst, const char *src, t_usize n);
t_usize		ft_strlcpy(char *dst, const char *src, t_usize size);
char		*ft_strcat(char *dst, const char *src);
char		*ft_strncat(char *dst, const char *src, t_usize n);
t_usize		ft_strlcat(char *dst, const char *src, t_usize size);
const char	*ft_strchr(const char *str, t_int c);
const char	*ft_strrchr(const char *str, t_int c);
const char	*ft_strstr(const char *s1, const char *s2);
const char	*ft_strnstr(const char *s1, const char *s2, t_usize n);
t_int		ft_strcmp(const char *s1, const char *s2);
t_int		ft_strncmp(const char *s1, const char *s2, t_usize n);
t_int		ft_atoi(const char *str);
t_bool		ft_isalpha(t_int c);
t_bool		ft_isdigit(t_int c);
t_bool		ft_isalnum(t_int c);
t_bool		ft_isascii(t_int c);
t_bool		ft_isprint(t_int c);
t_int		ft_toupper(t_int c);
t_int		ft_tolower(t_int c);

char		*ft_substr(const char *str, t_uint start, t_usize len);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strtrim(const char *str, const char *set);
char		*ft_strnew(t_usize size);
void		ft_strdel(char **as);
void		ft_strclr(char *s);
void		ft_striter(char *s, void (*f)(char *));
void		ft_striteri(char *s, void (*f)(t_uint, char *));
char		*ft_strmap(const char *s, char (*f)(char));
char		*ft_strmapi(const char *s, char (*f)(t_uint, char));
t_bool		ft_strequ(const char *s1, const char *s2);
t_bool		ft_strnequ(const char *s1, const char *s2, t_usize n);
char		**ft_split(const char *s, char c);
char		*ft_itoa(t_int n);
void		ft_putchar(char c);
void		ft_putstr(const char *s);
void		ft_putendl(const char *s);
void		ft_putnbr(t_int n);
void		ft_putchar_fd(char c, t_int fd);
void		ft_putstr_fd(const char *s, t_int fd);
void		ft_putendl_fd(const char *s, t_int fd);
void		ft_putnbr_fd(t_int n, t_int fd);

/* Allocator */

typedef enum e_alloc
{
	ALLOC_TEMP = 0,
	ALLOC_HEAP = 1
}	t_alloc;

typedef struct s_temp_storage
{
	t_usize	cap;
	t_usize	top;
	void	*mem;
}	t_temp_storage;

t_bool		ft_init_temp_storage(t_usize cap);
void		ft_free_temp_storage(void);
void		ft_reset_temp_storage(void);
void		*ft_alloc(t_usize size, t_alloc type);
void		ft_free(void *ptr, t_alloc type);

/* Dynamic array */

# define ARRAY_ALLOC(a) ((t_alloc *)((t_usize *)(a) - 2))[-1]
/* Get the number of elements in the array a (mutable). */
# define COUNT(a) ((t_usize *)(a))[-1]
/* Get the number of allocated elements in the array a (mutable). */
# define CAP(a) ((t_usize *)(a))[-2]
/* Get the number of elements in the array a (immutable). */
# define CCOUNT(a) ((a) ? COUNT (a) : 0)
/* Get the number of allocated elements in the array a (immutable). */
# define CCAP(a) ((a) ? CAP (a) : 0)
/* Get the base address of the array. */
# define ARRAY_BASE(a) ((a) ? (t_usize *)(a) - 2 : NULL)
/* Create a new array, allocating cap elements upfront. */
# define ARRAY_NEW(T, cap, alloc) (T *)ft_arraynew (cap, sizeof (T), alloc)
/* Free the allocated memory and set a to NULL. */
# define ARRAY_DEL(a) ft_arraydel ((void **)a)
/* Remove all elements, don't free the memory. */
# define CLEAR(a) { if (*(a)) COUNT (*(a)) = 0; }
/* Allocate more space for the array. */
# define GROW(a, cap) ft_grow ((void **)a, cap, sizeof (**(a)))
/* Push an element and return a pointer to it. */
# define PPUSH(a) ft_push ((void **)a, sizeof (**(a)))
/* Push an element and assign e to it. */
# define PUSH(a, e) { PPUSH (a); (*(a))[CCOUNT (*(a)) - 1] = e; }
/* Pop the last element in the array and return a pointer to it. */
# define POP(a) ft_pop ((void **)a, sizeof (**(a)))
/* Insert an element at index i, return a pointer to it. */
# define PINSERT(a, i) ft_insert ((void **)a, i, sizeof (**(a)))
/* Insert an element at index i and assign e to it. */
# define INSERT(a, i, e) { PINSERT (a, i); (*(a))[i] = e; }
/* Remove the element at index i, return a pointer to it. */
# define REMOVE(a, i) ft_remove ((void **)a, i, sizeof (**(a)))
/* Insert an element at index i, keep the order and return a pointer to it. */
# define PSORT_INSERT(a, i) ft_sort_insert ((void **)a, i, sizeof (**(a)))
/* Insert an element at index i, keep the order and assign e to it. */
# define SORT_INSERT(a, i, e) { PSORT_INSERT (a, i); (*(a))[i] = e; }
/* Remove the element at index i, keep the order and return a pointer to it. */
# define SORT_REMOVE(a, i) ft_sort_remove ((void **)a, i, sizeof (**(a)))

void		*ft_arraynew(t_usize cap, t_usize size, t_alloc allocator);
void		ft_arraydel(void **array);
void		ft_grow(void **array, t_usize add_cap, t_usize size);
void		*ft_push(void **array, t_usize size);
void		*ft_pop(void **array, t_usize size);
void		*ft_insert(void **array, t_usize index, t_usize size);
void		ft_remove(void **array, t_usize index, t_usize size);
void		*ft_sort_insert(void **array, t_usize index, t_usize size);
void		ft_sort_remove(void **array, t_usize index, t_usize size);

#endif
