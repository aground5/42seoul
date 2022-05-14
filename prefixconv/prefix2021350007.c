#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct s_node
{
	int				data;
	int				type;
	struct s_node	*next;
}					t_node;

char	**load_file(int	*num)
{
	char	buff;
	int		n;
	int		i;
	char	**prefixes;

	FILE	*in = fopen("prefix.in", "r");
	if (in == NULL)
		exit(-1);
	buff = (char)fgetc(in);
	n = 0;
	// Step 1: read n
	while (buff != EOF)
	{
		if (buff == '\n')
			break ;
		else if (buff >= '0' && buff <= '9')
		{
			n *= 10;
			n += buff - '0';
		}
		else
		{
			printf("%c: ERROR\n", buff);
			exit(-1);
		}
		buff = (char)fgetc(in);
	}
	//Step 2: read prefixes
	prefixes = (char **)calloc(n, sizeof(char *));
	if (prefixes == NULL)
		exit(-1);
	i = 0;
	buff = (char)fgetc(in);
	while (buff != EOF && i < n)
	{
		if (buff == '\n')
			i++;
		else if ((buff >= '0' && buff <= '9') || buff == '/' || buff == '*' || buff == '+' || buff == '-' || buff == ' ')
		{
			if (prefixes[i] == NULL)
			{
				prefixes[i] = (char *)calloc(sizeof(char), 2);
			}
			else
			{
				prefixes[i] = (char *)realloc(prefixes[i], sizeof(char) * (strlen(prefixes[i])) + 2);
			}
			prefixes[i][strlen(prefixes[i]) + 1] = '\x00';
			prefixes[i][strlen(prefixes[i])] = buff;
		}
		buff = (char)fgetc(in);
	}
	fclose(in);
	*num = n;
	return (prefixes);
}

void	push(t_node **start, int data, int type)
{
	t_node	*tmp = *start;
	*start = (t_node *)calloc(1, sizeof(t_node));
	(*start)->data = data;
	(*start)->type = type;
	(*start)->next = tmp;
}

int	pop(t_node **start)
{
	t_node	*target = *start;
	int		ret = target->data;
	*start = target->next;
	free(target);
	return (ret);
}

void	free_array(char **array, int n)
{
	for (int i = 0; i < n; i++)
	{
		free(array[i]);
	}
	free(array);
}

int interpreter(const char *prefix, int *interpreted, int *type)
{
	int i = 0;

	while (prefix[i] != '\x00')
	{
		if (prefix[i] >= '0' && prefix[i] <= '9')
		{
			*interpreted *= 10;
			*interpreted += prefix[i] - '0';
			*type = 1;	// int number
		}
		else if (prefix[i] == ' ')
			break;
		else
		{
			*type = 0;	// operator
			*interpreted = prefix[i];
			i++;
			break;
		}
		i++;
	}
	return (i);
}

int operate(const char *prefix)
{
	t_node	*start = NULL;
	int		len = strlen(prefix);
	int		interpreted;
	int		type;

	for (int i = 0; i < len; i++)
	{
		interpreted = 0;
		type = 0;
		i += interpreter(prefix + i, &interpreted, &type);
		push(&start, interpreted, type);
		while (start->next != NULL && start->type == 1 && start->next->type == 1)
		{
			int tmp1, tmp2, op;
			tmp1 = pop(&start);
			tmp2 = pop(&start);
			op = pop(&start);
			switch (op)
			{
			case '+':
				tmp2 += tmp1;
				break;
			case '-':
				tmp2 -= tmp1;
				break;
			case '*':
				tmp2 *= tmp1;
				break;
			case '/':
				tmp2 /= tmp1;
				break;
			default:
				printf("ERROR: %d, %c\n", start->next->data, start->next->data);
			}
			push(&start, tmp2, 1);
		}
	}
	int ret = start->data;
	free(start);
	return (ret);
}

int main(void)
{
	int		n;
	char	**prefixes;
	FILE	*out;

	prefixes = load_file(&n);
	out = fopen("prefix.out", "w");
	fprintf(out, "%d\n", n);
	for (int i = 0; i < n; i++)
		fprintf(out, "%d\n", operate(prefixes[i]));
	fclose(out);
	free_array(prefixes, n);
	return (0);
}