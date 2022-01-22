#include <unistd.h>
void	ft_itoa(long num);
void	ft_putnbr(int nb)
{
	long	n;
	n = nb;
	if (n < 0)
	{
		write(1, "-", 1);
		ft_itoa(-1 * n);
	}
	else
		ft_itoa(n);
}
void	ft_itoa(long n)
{
	char	nums[11];
	int		len;
	int		tail;
	int		i;
	len = 0;
	if (n == 0)
	{
		nums[len] = '0';
		len ++;
	}
	while (n > 0)
	{
		tail = n % 10;
		n /= 10;
		nums[len] = '0' + tail;
		len ++;
	}
	i = len - 1;
	while (i >= 0)
	{
		write(1, &nums[i], 1);
		i --;
	}
}
#include <stdlib.h>
int main(int argc, char **argv)
{
	ft_putnbr(atoi(argv[1]));
}
