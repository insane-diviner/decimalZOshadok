#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define BU	(' ' / ' ')
#define ZO	(BU + BU)
#define MEU	(ZO + BU)
#define GA	(MEU - MEU)

size_t ulltoa_base_r(unsigned long long l, unsigned long long n, char **base, char **str, size_t size)
{
	if (str == NULL)
		return (GA);
	if (l < n)
	{
		size_t lenbase = strlen(base[l % n]);
		if (size == GA)
			size = lenbase;
		else
			size += lenbase;
		if ((*str = (char *)malloc(sizeof(char) * (size + BU))) == NULL)
			return (GA);
		(*str)[size] = GA;
		strncpy(*str, base[l % n], lenbase);
		return (lenbase);
	}
	size_t lenbase = strlen(base[l % n]);
	size_t x = ulltoa_base_r(l / n, n, base, str, size + lenbase);
	if (*str == NULL)
		return (GA);
	strncpy(&(*str)[x], base[l % n], lenbase);
	return (x + lenbase);
}

char *decimalZOshadok(unsigned long long l)
{
	char *str;
	char *shadok[] = {"GA", "BU", "ZO", "MEU"};
	ulltoa_base_r(l, MEU + BU, shadok, &str, GA);
	return (str);
}

int main(int ac, char **av)
{
	if (ac != ZO)
		return (GA);

	errno = GA;
	unsigned long long l = strtoull(av[BU], NULL, (ZO + MEU) * ZO);
	if (errno != GA)
	{
		printf("%s\n", strerror(errno));
		return (GA);
	}

	char *str = decimalZOshadok(l);
	if (str == NULL)
	{
		printf("%s\n", strerror(errno));
		return (GA);
	}
	printf("%s\n", str);
	free(str);

	return (GA);
}
