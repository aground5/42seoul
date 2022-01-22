void	ft_putstr_non_printable(char *str);

int main(int argc, char **argv)
{
	char *s1 = "\xff\x45\x1d\x3f\x9a";
	ft_putstr_non_printable(s1);
}
