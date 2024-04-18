/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 19:36:33 by jaqribei          #+#    #+#             */
/*   Updated: 2023/11/04 20:23:41 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}t_list;

// -*- libft -*-
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *big, const char*little, size_t len);
int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const*set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
long	ft_atol(const char *nptr);
int		ft_strcmp(char *s1, char *s2);

// -*- get_next_line -*-
char	*get_next_line(int fd);
char	*ft_get_line(char *str);
char	*ft_read(int fd, char *next);
char	*ft_get_rest(char *str);
int		ft_check_bytes(long bytes_readed, char *aux, char *buf, char *temp);

// -*- printf -*-
int		ft_printf(const char *format, ...);
int		ft_numbers_flag(char format, va_list args);
int		ft_str_flag(va_list args);
int		ft_numbers_hexa_upper_flag(va_list args);
int		ft_numbers_hexa_low_flag(va_list args);
int		ft_check_specifier_type_flag(char format, char flag, va_list args);
size_t	ft_unsigned_number_flag(va_list args);
int		ft_pointer_flag(va_list args);
int		ft_check_specifier_type(char format, va_list args);
size_t	ft_unsigned_number_flag(va_list args);
int		ft_percent_flag(char c);
int		ft_chr_flag(va_list args);
int		ft_check_specifier_type(char format, va_list args);
int		ft_numbers(va_list args);
int		ft_str(va_list args);
int		ft_chr(va_list args);
int		ft_numbers_hexa_upper(va_list args);
int		ft_numbers_hexa_low(va_list args);
int		ft_check_specifier_type(char format, va_list args);
size_t	ft_unsigned_number(va_list args);
int		ft_pointer(va_list args);
int		ft_percent(char c);

#endif
