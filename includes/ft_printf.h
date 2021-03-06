/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcollard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 09:57:07 by tcollard          #+#    #+#             */
/*   Updated: 2018/03/20 15:40:13 by tcollard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../includes/ft_printf.h"
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>
# include <wchar.h>
# include <stdlib.h>
# include "../../libft/includes/libft.h"

# define SIZE 60

typedef struct	s_flag
{
	int		flag[5];
	int		length[7];
	int		width;
	int		precision;
	int		ret;
	int		i;
	int		save_i;
	char	buff[SIZE];
}				t_flag;

int				ft_printf(const char *format, ...);

void			init_tab(t_flag *tab);
void			reinit_tab(t_flag *tab);
void			ft_ret(t_flag *tab, char c);
void			add_var(t_flag *tab, char *var);

void			add_modifier(char *str, size_t *i, t_flag *tab);
void			check_modifier(t_flag *tab);
void			inti_modifier(t_flag *tab);
int				flag_modifier(char *s, size_t *i, t_flag *tab);

char			*dispatch_flag(t_flag *tab, char *v, char c);
void			add_flag(char *str, size_t *i, t_flag *tab);
char			*hashtag(char **var, char c, t_flag *tab);
char			*minus(char **var, char c, t_flag *tab);
char			*space(char **var, char c, t_flag *tab);
char			*plus(char **v, char c, t_flag *tab);
char			*zero(char **var, char c, t_flag *tab);

void			add_width_preci(char *str, size_t *i, t_flag *tab);
void			precision_on_int(t_flag *tab, char **var, char c);

int				conversion(char c, va_list *ap, t_flag *tab, char **str);
int				conv_first(char *s, size_t *i, t_flag *tab, char **str);
int				conv_s(va_list *ap, char **var);
int				conv_c(va_list *ap, char **var, t_flag *tab);
int				conv_p(va_list *ap, char **var);
int				conv_ul(va_list *ap, char **var);
int				conv_ll(va_list *ap, char **var, char c);
int				conv_l(va_list *ap, char **var, char c);
int				conv_int(va_list *ap, char **var, char c);
int				conv_hh(va_list *ap, char **var, char c);
int				conv_h(va_list *ap, char **var, char c);
int				conv_j(va_list *ap, char **var, char c);
int				conv_z(va_list *ap, char **var, char c);

int				nb_octet_str(wchar_t *str, t_flag *tab);
int				nb_octet_char(wchar_t wc, t_flag *tab);
void			conv_wchar(va_list *ap, t_flag *tab, char c);
int				conv_wc(wchar_t c, t_flag *tab, int nb_octet);
void			intit_mask(char ***octet, int nb_octet);
void			apply_mask(char *str, int x, int nb_octet, t_flag *tab);
void			print_wchar(char ***oct, int nb_octet, t_flag *tab);

void			modif_flag(t_flag *tab, char **var, char c);
void			modif_width(t_flag *tab, char **var, char c);
void			modif_precision(t_flag *tab, char **var, char c);

char			*ft_check(char *s, size_t *i, t_flag *tab, va_list *ap);
void			check_flag(t_flag *tab);

void			init_buff(t_flag *tab);
void			ft_display(t_flag *tab);
void			ft_display_prev(t_flag *tab);

int				ft_atoi(const char *nptr);
int				ft_atoi_base(char *str, int base);
int				ft_isdigit(int c);
char			*ft_itoa(int n);
char			*ft_itoa_base(int nb, int base);
char			*ft_itoa_ll(long long n);
char			*ft_itoa_base_ull(unsigned long long nb, int base);
char			*ft_itoa_base_neg(int nb, int base);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
void			*ft_memset(void *b, int c, size_t len);
void			ft_putstr(char const *s);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strdup(const char *s);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlen(const char *str);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
int				ft_tolower(int c);
void			ft_putchar(char b);
char			*ft_strncpy(char *dest, const char *src, size_t n);
int				ft_isalpha(int c);

#endif
