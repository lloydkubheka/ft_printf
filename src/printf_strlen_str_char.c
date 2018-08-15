

#include <ft_printf.h>

int		ft_strlen(char *str)
{
	return (*str ? 1 + ft_strlen(++str) : 0);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

int		ft_putchar_times(int c, int times)
{
	int i;

	i = 0;
	while (i < times)
	{
		write(1, &c, 1);
		i++;
	}
	return (times);
}

void	ft_putchar(int c)
{
	write(1, &c, 1);
}
