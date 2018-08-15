

#include <ft_printf.h>

void	ft_ftoken_reset(t_f *ftoken)
{
	ftoken->alt = 0;
	ftoken->left = 0;
	ftoken->sign = 0;
	ftoken->space = 0;
	ftoken->zero = 0;
	ftoken->h = 0;
	ftoken->hh = 0;
	ftoken->l = 0;
	ftoken->ll = 0;
	ftoken->j = 0;
	ftoken->z = 0;
	ftoken->cur_len = 0;
	ftoken->mfw = 0;
	ftoken->precision = 0;
}

void	ft_printf_mfw(t_f *ftoken, char **fmt, va_list ap)
{
	(*fmt)++;
	ft_printf_flags(ftoken, fmt);
	if (*(*fmt) >= '1' && *(*fmt) <= '9')
	{
		ftoken->mfw = ft_atoi(*fmt);
		*fmt += ft_nlen_base(ftoken->mfw, 10);
	}
	if (*(*fmt) == '*')
	{
		ft_handling_star(ftoken, ap);
		ftoken->mfw = ftoken->star;
		++(*fmt);
	}
	if (*(*fmt) == '.')
	{
		(*fmt)++;
		if (*(*fmt) >= '1' && *(*fmt) <= '9')
		{
			ftoken->precision = ft_atoi(*fmt);
			*fmt += ft_nlen_base(ftoken->precision, 10);
		}
		else if (*(*fmt) == '0')
			(*fmt)++;
	}
	ft_printf_lenmod(ftoken, fmt);
}

void	ft_printf_flags(t_f *ftoken, char **fmt)
{
	while (*(*fmt) == '#' || *(*fmt) == '-' || *(*fmt) == '+'
			|| *(*fmt) == '0' || *(*fmt) == ' ')
	{
		if (*(*fmt) == '#')
			ftoken->alt = 1;
		else if (*(*fmt) == '-')
			ftoken->left = 1;
		else if (*(*fmt) == '+')
			ftoken->sign = 1;
		else if (*(*fmt) == ' ')
			ftoken->space = 1;
		else if (*(*fmt) == '0')
			ftoken->zero = 1;
		(*fmt)++;
	}
}

void	ft_printf_lenmod(t_f *ftoken, char **fmt)
{
	while (*(*fmt) == 'l' || *(*fmt) == 'h' || *(*fmt) == 'j' || *(*fmt) == 'z')
	{
		if (*(*fmt) == 'l' && *((*fmt) + 1) == 'l')
		{
			ftoken->ll = 1;
			(*fmt)++;
		}
		else if (*(*fmt) == 'l')
			ftoken->l = 1;
		if (*(*fmt) == 'h' && *((*fmt) + 1) == 'h')
		{
			(*fmt)++;
			ftoken->hh = 1;
		}
		else if (*(*fmt) == 'h')
			ftoken->h = 1;
		if (*(*fmt) == 'j')
			ftoken->j = 1;
		if (*(*fmt) == 'z')
			ftoken->z = 1;
		(*fmt)++;
	}
}

int		ft_atoi(const char *str)
{
	int					i;
	int					sign;
	unsigned long long	result;

	i = 0;
	while (str[0] == '\t' || str[0] == '\n' || str[0] == '\v' ||
			str[0] == '\f' || str[0] == ' ' || str[0] == '\r')
		str++;
	result = 0;
	sign = (str[0] == '-' ? -1 : 1);
	str = (str[0] == '-' || str[0] == '+') ? str + 1 : str;
	while (str[0] == '0')
		str++;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
		result = result * 10 + (str[i++] - '0');
	if (i > 19 || result >= 9223372036854775808ULL)
		return (sign == 1 ? -1 : 0);
	return (result * sign);
}
