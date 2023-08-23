#include<stdio.h>

int main()
{
	unsigned long b, m;
	int r, t, T;
	b = (1024 * 1024) / 4;
	r = 32;
	m = 32 * 1000;
	t = b/m;

	while(1)
	{
		T = (b + (t * r)) / m;
		if (T == t)
			break ;
		t = T;
	}
	printf(" t = %d\n", t);

	return 0;
}
