int	is_printable(char c)
{
	if (c >= 0x20 && c <= 0xfe)
		return (1);
	return (0);
}
