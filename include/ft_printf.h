

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <wchar.h>
# include <stdlib.h>

int				ft_strncmp(const char *s1, const char *s2, int n);
int				set_color(char **fmt);
int				ft_printf(const char *format, ...);
char			*ft_uldtoa_base_alt(unsigned long value, int base);
char			*ft_uldtoa_base(unsigned long value, int base);
char			*ft_udtoa_base_alt(long value, int base);
char			*ft_udtoa_base(long value, int base);
int				ft_uld_len_base(unsigned long value, int base);
int				ft_ud_len_base(unsigned int value, int base);
char			*ft_lldtoa_base(long long value, int base);
int				ft_lldlen_base(long long value, int base);
int				ft_wstr_len(wchar_t *ws);
int				ft_wchar_len(wchar_t wc);
int				ft_putchar_times(int c, int times);
int				ft_atoi(const char *str);
char			*ft_uhhdtoa_base_alt(unsigned char value, int base);
char			*ft_uhhdtoa_base(unsigned char value, int base);
void			ft_putuhhd_r(unsigned char n);
void			ft_putuhhd(unsigned char n);
void			ft_puthhd(signed char n);
void			ft_puthhd_r(signed char n);
char			*ft_lldtoa_base_alt(long long value, int base);
int				ft_ulld_len_base(unsigned long long value, int base);
char			*ft_ulldtoa_base_alt(unsigned long long value, int base);
char			*ft_ulldtoa_base(unsigned long long value, int base);
int				ft_nlen_base(long value, int base);
char			*ft_itoa_base(long value, int base);
int				ft_strlen(char *str);
void			ft_putstr(char *str);
void			ft_putchar(int c);
int				ft_putwchar(wchar_t wc);
int				ft_putwstr(wchar_t *ws);
void			ft_putlld_r(long long lld);
void			ft_putlld(long long lld);
void			ft_putlong_r(long n);
void			ft_putlong(long n);
void			ft_putnbr_r(int n);
void			ft_putnbr(int n);
void			ft_putulld_r(unsigned long long ulld);
void			ft_putulld(unsigned long long ulld);
void			ft_putuld_r(unsigned long uld);
void			ft_putuld(unsigned long ld);
void			ft_putud_r(unsigned int u);
void			ft_putud(unsigned int u);
typedef struct	s_ftoken
{
	int		alt:1;
	int		zero:1;
	int		space:1;
	int		sign:1;
	int		left:1;
	int		l:1;
	int		ll:1;
	int		h:1;
	int		hh:1;
	int		j:1;
	int		z:1;
	int		precision;
	int		mfw;
	int		cur_len;
	int		star;
}				t_f;
union			u_var
{
	char				*s;
	wchar_t				*ws;
	unsigned char		uc;
	wchar_t				wc;
	char				c;
	signed char			sc;
	unsigned int		ud;
	unsigned long		ul;
	unsigned long long	ull;
	int					d;
	long				ld;
	long long			lld;
	char				*fuck;
};
void			ft_handling_star(t_f *f, va_list ap);
void			ft_ftoken_reset(t_f *ft);
void			ft_printf_mfw(t_f *ft, char **fmt, va_list ap);
void			ft_printf_lenmod(t_f *ft, char **fmt);
void			ft_printf_flags(t_f *ft, char **fmt);
int				ft_printf_d(t_f *ft, char **fmt, va_list ap, union u_var f);
int				ft_printf_lu(t_f *ft, char **fmt, va_list ap, union u_var f);
int				ft_printf_u(t_f *ft, char **fmt, va_list ap, union u_var f);
int				ft_printf_p(t_f *ft, char **fmt, va_list ap, union u_var f);
int				ft_printf_c(t_f *ft, char **fmt, va_list ap, union u_var f);
int				ft_printf_lo(t_f *ft, char **fmt, va_list ap, union u_var f);
int				ft_printf_o(t_f *ft, char **fmt, va_list ap, union u_var f);
int				ft_printf_s(t_f *ft, char **fmt, va_list ap, union u_var f);
int				ft_printf_ls(t_f *ft, char **fmt, va_list ap, union u_var f);
int				ft_printf_x(t_f *ft, char **fmt, va_list ap, union u_var f);
int				ft_printf_lx(t_f *ft, char **fmt, va_list ap, union u_var f);
int				ft_printf_format(t_f *ft, char **fmt, va_list ap);
int				percent(t_f *ft, char **fmt);
int				binary(t_f *ft, char **fmt, va_list ap);

#endif
