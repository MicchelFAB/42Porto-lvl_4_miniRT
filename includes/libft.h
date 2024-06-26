/**
 * @file libft.h
 * @author Michel Batista (michel_fab@outlook.com)
 * @brief Include file for the libft functions.
 * @version 0.1
 * @date 2024-05-22 * 
 * @note This file is part of the MiniRT project.
 * 
 * @copyright Copyright (c) 2024 * 
 */
#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdint.h>
# include "ft_printf.h"
# include "get_next_line.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/*  # Check functions # */

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_isspace(int c);

// # String functions #
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
int				ft_strcmp(char *s1, char *s2);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_joinstr(char *s1, char *s2);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strdup(const char *s);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			**ft_split(char const *s, char c);
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_str_replace(char *str, char *old, char *n, int i);
char			*ft_str_join(char *str, char *old, char *n, int i);
char			*ft_strcpy(char *dest, char *src);
size_t			ft_repetition_break(const char *str);
int				ft_strstr_init(char *str, char *to_find);
int				ft_strstr_end(char *str, char *to_find);
char			*ft_rmvchar(char *str, int pos);

// # Memory functions #
size_t			ft_strlen(const char *s);
size_t			ft_strlen_at(const char *s, char c);
void			*ft_memset(void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_tolower_c(char c);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_atoi(const char *nptr);
size_t			ft_intlen(int *s);
int				ft_arrlen(int *a);
void			ft_swap(int *a, int *b);
void			*ft_calloc(size_t nmemb, size_t size);

char			*ft_itoa(int n);
long long int	ft_atol(const char *nptr);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
int				ft_limit_int(int nb, int a, int b);
int				ft_max(int a, int b);

// # List functions #
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *n);
void			ft_lstadd_back(t_list **lst, t_list *n);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void*));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*));

#endif