

#include <ft_printf.h>

int		ft_lldlen_base(long long value, int base)
{
	int len;

	len = 0;
	if (!value)
		return (1);
	if (value < 0)
		len++;
	while (value)
	{
		value /= base;
		len++;
	}
	return (len);
}

int		ft_ulld_len_base(unsigned long long value, int base)
{
	int len;

	len = 0;
	if (!value)
		return (1);
	while (value)
	{
		value /= base;
		len++;
	}
	return (len);
}

int		ft_uld_len_base(unsigned long value, int base)
{
	int len;

	len = 0;
	if (!value)
		return (1);
	while (value)
	{
		value /= base;
		len++;
	}
	return (len);
}

int		ft_ud_len_base(unsigned int value, int base)
{
	int len;

	len = 0;
	if (!value)
		return (1);
	while (value)
	{
		value /= base;
		len++;
	}
	return (len);
}

int		ft_nlen_base(long value, int base)
{
	int len;

	len = 0;
	if (!value)
		return (1);
	if (value < 0)
		len++;
	while (value)
	{
		value /= base;
		len++;
	}
	return (len);
}
