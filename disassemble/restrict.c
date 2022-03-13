void increase(int *a, int *b, int *x) 
{
    *a += *x;
    *b += *x;
}

void restrict_increase(int *restrict a, int *restrict b, int *restrict x) 
{
    *a += *x;
    *b += *x;
}

int main(void)
{
	return (0);
}