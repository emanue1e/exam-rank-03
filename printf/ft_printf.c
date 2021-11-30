#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

void ft_putchar_len(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

void ft_str(char *str, int *len)
{
	int i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		(*len) += 6;
		return;
	}
	while (str[i])
	{
		ft_putchar_len(str[i], len);
		i++;
	}
}

void ft_nbr(int n, int *len)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*len) += 11;
		return;
	}
	if (n < 0)
	{
		ft_putchar_len('-', len);
		ft_nbr(-n, len);
	}
	else
	{
		if (n > 9)
			ft_nbr(n / 10, len);
		ft_putchar_len(n % 10 + '0', len);
	}
}

void ft_hex(unsigned int x, int *len)
{
	char str[25], *base_char = "0123456789abcdef";
	int i = 0;
	if (x == 0)
	{
		ft_putchar_len('0', len);
		return;
	}
	while (x != 0)
	{
		str[i] = base_char[x % 16];
		x /= 16;
		i++;
	}
	while (i--)
		ft_putchar_len(str[i], len);
}

void check(char c, va_list *args, int *len)
{
	if (c == 's')
		ft_str(va_arg(*args, char *), len);
	else if (c == 'd')
		ft_nbr(va_arg(*args, int), len);
	else if (c == 'x')
		ft_hex(va_arg(*args, unsigned int), len);
	else if (c == '%')
		ft_putchar_len('%', len);
}

int ft_printf(const char *s, ...)
{
	int i = 0, len = 0;
	va_list ap;
	va_start(ap, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			check(s[++i], &ap, &len);
			i++;
		}
		else
		{
			ft_putchar_len(s[i], &len);
			i++;
		}
	}
	va_end(ap);
	return len;
}

#include <stdio.h>
int main()
{
	printf("%d\n\n", (ft_printf("%d\n", -12345678)));
	printf("%d\n", (ft_printf("%s\n", "AVE MARIE")));
}
