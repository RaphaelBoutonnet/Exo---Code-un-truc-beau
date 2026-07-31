#include <unistd.h>

int	ft_pow(float nb, int pow)
{
	float (res) = 1;
	if (nb == 0 || pow < 0)
		return (0);
	if (pow == 0)
		return (1);
	while (pow > 0)
	{
		res = (res * nb);
		pow--;
	}
	return (res);
}

void	ft_put_spaces(int i)
{
	int (j) = ft_pow(1.4, i);
	int (k) = 0;
	while (k < j)
	{
		write(1, " ", 1);
		k++;
	}
}

int	ft_atoi(char *nbr)
{
	int (res) = 0;
	int (i) = 0;
	while (nbr[i])
	{
		res = (res * 10) + (nbr[i] - '0');
		i++;
	}
	return (res);
}

int	main(int argc, char **argv)
{
	int (nb) = ft_atoi(argv[1]);
	int (i) = 0;
	int (j) = 0;
	int (k) = 0;
	if (argc < 2 || nb < 0 || nb > 40)
	{
		write(1, "Relancez en entrant uniquement 1 argument numerique compris entre 1 et 40\n", 74);
		return (1);
	}
	while (i < nb)
	{
		ft_put_spaces(k);
		write(1, "o\n", 2);
		if (k % 7 == 0 && k > 0)
		{
			i++;
			k++;
			j = k;
			while (k % 7 != 0)
			{
				ft_put_spaces(j - (k - j));
				write(1, "o\n", 2);
				i++;
				k++;
			}
			k = 0;
		}
		i++;
		k++;
	}
	return 0;
}
