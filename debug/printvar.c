#include <stdio.h>

int	printnum(char *name, int num)
{
	int	ret;

	ret = 0;
	if (name)
		ret = printf("%-20s", name);
	ret += printf("%d\n", num);
	return (ret);
}

int	printlong(char *name, long long num)
{
	int	ret;

	ret = 0;
	if (name)
		ret = printf("%-20s", name);
	ret += printf("%lld\n", num);
	return (ret);
}

int	printfloat(char *name, float num)
{
	int	ret;

	ret = 0;
	if (name)
		ret = printf("%-20s", name);
	ret += printf("%f\n", num);
	return (ret);
}

int	printstr(char *name, char *str)
{
	int	ret;

	ret = 0;
	if (name)
		ret = printf("%-20s", name);
	ret += printf("%s\n", str);
	return (ret);
}

int	printchar(char *name, char c)
{
	int	ret;

	ret = 0;
	if (name)
		ret = printf("%-20s", name);
	ret += printf("%c\n", c);
	return (ret);
}

int	printco(char *name, int x, int y)
{
	int	ret;

	ret = 0;
	if (name)
		ret = printf("%-20s", name);
	ret = printf("( %d, %d )\n", x, y);
	return (ret);
}

void	print2darray(char **array, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		printf("%s\n", array[i]);
		i++;
	}
}
