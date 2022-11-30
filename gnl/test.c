#include <unistd.h>

int ft_putchar(char c)
{
	return (write(1,&c, 1));
}
int main(int ac, char **av)
{
	int i=0;
	int arr[128]={0,};
	if (ac ==3)
	{		
		while (av[1][i])
		{
			if (arr[av[1][i]]==0)
			{
				arr[av[1][i]] = 1;
				ft_putchar(av[1][i]);
			}
			i++;
		}
		i=0;
		while (av[2][i])
		{
			if (arr[av[2][i]]==0)
			{
				arr[av[2][i]]=1;
				ft_putchar(av[2][i]);
			}
			i++;
		}
	}
	ft_putchar('\n');
	return (0);
}
// union 문제 입력받은 문자열 중복되지 않게 순서대로