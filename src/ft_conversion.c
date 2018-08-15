

#include <ft_printf.h>

int		percent(t_f *ft, char **fmt)
{
	++(*fmt);
	ft->cur_len = 1;
	while (ft->cur_len < ft->mfw && !ft->left)
		if (ft->zero && !ft->precision)
			ft->cur_len += write(1, "0", 1);
		else
			ft->cur_len += write(1, " ", 1);
	write(1, "%", 1);
	while (ft->cur_len < ft->mfw && ft->left)
		ft->cur_len += write(1, " ", 1);
	return (ft->cur_len);
}

int		binary(t_f *ft, char **fmt, va_list ap)
{
	ft->star = va_arg(ap, int);
	ft_putstr(ft_ulldtoa_base(ft->star, 2));
	++(*fmt);
	return (ft_lldlen_base(ft->star, 2));
}

int		handle1(t_f *ft, char **fmt, va_list ap, union u_var f)
{
	if (*(*fmt) == 'c')
		return (ft_printf_c(ft, fmt, ap, f));
	else if (*(*fmt) == 'b')
		return (binary(ft, fmt, ap));
	else if (*(*fmt) == 'C')
	{
		(*fmt)++;
		return (ft_putwchar(va_arg(ap, wchar_t)));
	}
	else if (*(*fmt) == 'd' || *(*fmt) == 'i')
		return (ft_printf_d(ft, fmt, ap, f));
	else if (*(*fmt) == 'D')
	{
		(*fmt)++;
		f.ld = va_arg(ap, long);
		ft_putlong(f.ld);
		return (ft_lldlen_base(f.ld, 10));
	}
	return (0);
}

int		handle2(t_f *ft, char **fmt, va_list ap, union u_var f)
{
	if (*(*fmt) == 'o')
		return (ft_printf_o(ft, fmt, ap, f));
	if (*(*fmt) == 'O')
		return (ft_printf_lo(ft, fmt, ap, f));
	if (*(*fmt) == 'p')
		return (ft_printf_p(ft, fmt, ap, f));
	if (*(*fmt) == 's')
		return (ft_printf_s(ft, fmt, ap, f));
	if (*(*fmt) == 'S')
		return (ft_printf_ls(ft, fmt, ap, f));
	if (*(*fmt) == 'u')
		return (ft_printf_u(ft, fmt, ap, f));
	if (*(*fmt) == 'U')
		return (ft_printf_lu(ft, fmt, ap, f));
	if (*(*fmt) == 'x')
		return (ft_printf_x(ft, fmt, ap, f));
	if (*(*fmt) == 'X')
		return (ft_printf_lx(ft, fmt, ap, f));
	if (*(*fmt) == '%')
		return (percent(ft, fmt));
	return (0);
}

int		ft_printf_format(t_f *ftoken, char **fmt, va_list ap)
{
	union u_var		f;
	int				len;

	len = 0;
	f.fuck = "This code is doing all the fucking..";
	ft_printf_mfw(ftoken, fmt, ap);
	if (*(*fmt) == 'c' || *(*fmt) == 'C' || *(*fmt) == 'i' ||
			*(*fmt) == 'd' || *(*fmt) == 'D' || *(*fmt) == 'b')
		return (handle1(ftoken, fmt, ap, f));
	if (*(*fmt) == 'o' || *(*fmt) == 'O' || *(*fmt) == 'p' ||
			*(*fmt) == 's' || *(*fmt) == 'S' || *(*fmt) == 'u' ||
			*(*fmt) == 'U' || *(*fmt) == 'x' || *(*fmt) == 'X' ||
			*(*fmt) == '%')
		return (handle2(ftoken, fmt, ap, f));
	return (len);
}
