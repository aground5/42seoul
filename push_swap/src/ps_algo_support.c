
void	algo_struct_init(t_queue *a, t_queue *b, int size)
{
	a->start = 0;
	a->end = size - 1;
	a->size = size;
	b->start = size;
	b->end = size - 1;
	b->size = 0;
}