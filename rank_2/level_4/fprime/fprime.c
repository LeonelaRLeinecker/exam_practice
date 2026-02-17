#include <stdlib.h>
#include <stdio.h>

int is_prime(int n)
{
		int i = 2;
		while(i < n)
		{
				if (n % i == 0)
						return 0;
				i++;
		}
		return 1;
}


int main(int argc, char **argv)
{
		if (argc == 2)
		{
				int num = atoi(argv[1]);

				if (num == 1)
						printf("1");
				else
				{
						int divisor = 2;
						while(num > 1)
						{
								if (num % divisor == 0)
								{
										printf("%d", divisor);
										num = num / divisor;
										if (num > 1)
												printf("*");
								}
								else 
										divisor++;
						}
				}
		}
		printf("\n");
		return 0;
}
