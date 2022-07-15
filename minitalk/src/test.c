#include "ft_printf.h"

int main(void)
{
	int a = 1;
	int b = 2;

	ft_printf("[DEBUG] signal %d from pid : %d\n", a, b);
	return(0);
}