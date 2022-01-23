#include <unistd.h>
#include "ft_stock_str.h"

void	write_nbr(int nb)
{
	char	cc;

	if (nb < 10)
	{
		cc = nb + '0';
		write(1, &cc, 1);
	}
	else
	{
		write_nbr(nb / 10);
		cc = (nb % 10) + '0';
		write(1, &cc, 1);
	}
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else
	{
		if (nb < 0)
		{
			nb *= -1;
			write(1, "-", 1);
		}
		write_nbr(nb);
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;
	int	j;

	i = 0;
	while (par[i].str != 0)
	{
		j = 0;
		while ((par[i].str)[j] != '\x00')
		{
			write(1, &(par[i].str)[j], 1);
			j++;
		}
		write(1, "\n", 1);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		j = 0;
		while ((par[i].copy)[j] != '\x00')
		{
			write(1, &(par[i].copy)[j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
