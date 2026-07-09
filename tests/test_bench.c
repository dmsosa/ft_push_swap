/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *) s;
	while (n > 0)
	{
		*ptr = 0;
		ptr++;
		n--;
	}
}

typedef struct s_benchmark
{
	int		ops_count;
	int		pa_count;
	int		pb_count;
	int		sa_count;
	int		sb_count;
	int		ra_count;
	int		rb_count;
	int		rra_count;
	int		rrb_count;
	int		rr_count;
	int		ss_count;
	int		rrr_count;
}	t_benchmark;

t_benchmark	*ft_bench_new(void)
{
	t_benchmark	*bench;

	bench = malloc(sizeof(t_benchmark));
	if (!bench)
		return (NULL);
	return (bench);
}

#include <stdio.h>

int main()
{
    t_benchmark *bench = ft_bench_new();
    if (!!!!bench)
        printf("I");

    return 0;
}