

#include <ft_printf.h>

void	ft_putuhhd_r(unsigned char n)
{
	if (n)
		ft_putuhhd_r(n / 10);
	if (n)
		ft_putchar((n % 10) + '0');
}

void	ft_putuhhd(unsigned char n)
{
	if (n == 0)
		ft_putchar('0');
	else
		ft_putuhhd_r(n);
}

void	ft_putud_r(unsigned int u)
{
	if (u)
		ft_putud_r(u / 10);
	if (u)
		ft_putchar((u % 10) + '0');
}

void	ft_putud(unsigned int u)
{
	if (u == 0)
		ft_putchar('0');
	else
		ft_putud_r(u);
}
