

#include <ft_printf.h>

int		ft_printf_u(t_f *ftoken, char **fmt, va_list ap, union u_var f)
{
	(*fmt)++;
	if (ftoken->l || ftoken->z || ftoken->ll || ftoken->j)
	{
		f.ul = va_arg(ap, unsigned long);
		ftoken->cur_len = ft_uld_len_base(f.ul, 10);
		ft_putuld(f.ul);
	}
	else if (ftoken->hh)
	{
		f.uc = va_arg(ap, unsigned int);
		ftoken->cur_len = ft_ud_len_base(f.uc, 10);
		ft_putuhhd(f.uc);
	}
	else
	{
		f.ud = va_arg(ap, unsigned int);
		ftoken->cur_len = ft_ud_len_base(f.ul, 10);
		ft_putud(f.ud);
	}
	return (ftoken->cur_len);
}

int		ft_printf_lu(t_f *ftoken, char **fmt, va_list ap, union u_var f)
{
	(*fmt)++;
	f.ul = va_arg(ap, unsigned long);
	ftoken->cur_len = ft_uld_len_base(f.ul, 10);
	ft_putuld(f.ul);
	return (ftoken->cur_len);
}

int		ft_printf_c(t_f *ftoken, char **fmt, va_list ap, union u_var f)
{
	(*fmt)++;
	if (ftoken->l)
	{
		f.wc = va_arg(ap, wchar_t);
		ftoken->cur_len = ft_putwchar(f.wc);
		while (ftoken->cur_len < ftoken->mfw)
			ftoken->cur_len += write(1, " ", 1);
	}
	else
	{
		f.c = va_arg(ap, int);
		ftoken->cur_len = 1;
		while (ftoken->cur_len < ftoken->mfw)
		{
			if (ftoken->zero)
				ftoken->cur_len += write(1, "0", 1);
			else
				ftoken->cur_len += write(1, " ", 1);
		}
		write(1, &f.c, 1);
	}
	return (ftoken->cur_len);
}

int		ft_printf_o(t_f *ftoken, char **fmt, va_list ap, union u_var f)
{
	(*fmt)++;
	if (ftoken->l || ftoken->z || ftoken->ll || ftoken->j)
	{
		f.ul = va_arg(ap, unsigned long);
		ftoken->cur_len = ft_uld_len_base(f.ul, 8);
		ft_putstr(ft_uldtoa_base(f.ul, 8));
	}
	else if (ftoken->hh)
	{
		f.uc = va_arg(ap, unsigned int);
		ftoken->cur_len = ft_nlen_base(f.uc, 8);
		ft_putstr(ft_uhhdtoa_base(f.uc, 8));
	}
	else
	{
		f.ud = va_arg(ap, unsigned int);
		ftoken->cur_len = ft_ud_len_base(f.ud, 8);
		if (ftoken->alt && f.ud != 0)
		{
			ftoken->cur_len++;
			write(1, "0", 1);
		}
		ft_putstr(ft_udtoa_base(f.ud, 8));
	}
	return (ftoken->cur_len);
}

int		ft_printf_lo(t_f *ftoken, char **fmt, va_list ap, union u_var f)
{
	(*fmt)++;
	f.ul = va_arg(ap, unsigned long);
	ftoken->cur_len = ft_uld_len_base(f.ul, 8);
	if (ftoken->alt && f.ud != 0)
	{
		ftoken->cur_len++;
		write(1, "0", 1);
	}
	ft_putstr(ft_uldtoa_base(f.ul, 8));
	return (ftoken->cur_len);
}
