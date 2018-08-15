

#include <ft_printf.h>

static	void	pts(char *s, int c)
{
	while (*s)
		write(1, s++, 1);
	ft_putnbr(c);
	write(1, "m", 1);
}

static	int		init_color(char **fmt, int color, int len)
{
	pts("\x1b[", color);
	(*fmt) = (*fmt + len);
	return (0);
}

static	int		no_color(char **fmt)
{
	++(*fmt);
	return (write(1, "{", 1));
}

int				set_color(char **fmt)
{
	if (ft_strncmp((const char *)*fmt, "{red}", 5) == 0)
		return (init_color(fmt, 91, 5));
	else if (ft_strncmp((const char *)*fmt, "{green}", 7) == 0)
		return (init_color(fmt, 92, 7));
	else if (ft_strncmp((const char *)*fmt, "{yellow}", 8) == 0)
		return (init_color(fmt, 93, 8));
	else if (ft_strncmp((const char *)*fmt, "{blue}", 6) == 0)
		return (init_color(fmt, 94, 6));
	else if (ft_strncmp((const char *)*fmt, "{magenta}", 9) == 0)
		return (init_color(fmt, 95, 9));
	else if (ft_strncmp((const char *)*fmt, "{cyan}", 6) == 0)
		return (init_color(fmt, 96, 6));
	else if (ft_strncmp((const char *)*fmt, "{white}", 7) == 0)
		return (init_color(fmt, 97, 7));
	else if (ft_strncmp((const char *)*fmt, "{eoc}", 5) == 0)
		return (init_color(fmt, 0, 5));
	else
		return (no_color(fmt));
}
