/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 14:13:25 by durisosa          #+#    #+#             */
/*   Updated: 2026/07/16 20:15:31 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

/* LISTS ---------------------------------------------------------------  */

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/* CHARS ---------------------------------------------------------------  */

void	*ft_calloc(size_t nmemb, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_isascii(int c);
void	ft_putchar(char c);
void	ft_putstr(const char *str);
void	ft_putnbr(int c);
void	ft_putendl(const char *str);

/* STRINGS ---------------------------------------------------------------  */

char	*ft_itoa(int n);
int		ft_atoi(const char *n);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strdup(const char *s);
char	*ft_strjoin(const char *s1, const char *s2);
int		ft_count_words(char *str);
int		ft_count_words(char *str);
char	*ft_strdup(const char *s);
int		ft_isspace(char c);
char	**ft_split(const char *s, char c);

/* FILE DESCRIPTORS -----------------------------------------------------  */

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/* GET NEXT LINE ------------------------------------------------  */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
int		ft_strlen_chr(char *s, char c);
void	ft_strcpy_gnl(char *dst, char *src);
void	ft_clean_buf(char *buf);
char	*ft_strjoin_gnl(char *prev, char *new);

/* PRINTF ---------------------------------------------------------------  */

# define NULL_PTR "(null)"
# define NULL_ADR "(nil)"

//Flags
//What are present flags?

typedef struct s_context
{
	int			written;
	int			fd;
	va_list		va;
}	t_context;

typedef struct s_flags
{
	int		zero;
	int		left;
	int		min_width;
	int		alt;
	int		asterisk;
	int		precision;
	int		valid_spec;
	int		blank;
	int		sign;
	int		to_upper;
	size_t	strlen;
}	t_flags;

// flags parsing

int		ft_isspec(char c);
int		ft_isflag(char c);
int		ft_valid_flag(char c);
void	ft_flags_width(const char **format, t_flags *flags);
t_flags	*ft_flags_asterisk(t_flags *flags, t_context *ctx);
t_flags	*ft_flags_setleft(t_flags *flags);
void	ft_flags_setprecision(const char **format, t_flags *flags,
			t_context *ctx);
t_flags	*ft_flags_setsign(t_flags *flags);
t_flags	*ft_flags_init(void);

// printf logic
void	ft_print_pad(int width, int max, int zeroes, t_context *ctx);
int		ft_printf(const char	*format, ...);
void	ft_printc(int c, t_context *ctx);
void	ft_printc_flags(int c, t_flags *flags, t_context *ctx);
void	ft_printstr(char *s, t_context *ctx);
int		ft_printstr_flags(char *s, t_flags *flags, t_context *ctx);
int		ft_printint(int n, t_flags *flags, t_context *ctx);
int		ft_printuint(unsigned int n, t_flags *flags, t_context *ctx);
int		ft_printhex(unsigned int n, int to_upper,
			t_flags *flags, t_context *ctx);
int		ft_printptr(void *ptr, t_flags *flags, t_context *ctx);

// Used while printing integers and decimal integers
char	*ft_print_itoa_abs(int n);
char	*ft_print_xtoa(unsigned long long n, int to_upper);
char	*ft_print_utoa(unsigned int n);

#endif
