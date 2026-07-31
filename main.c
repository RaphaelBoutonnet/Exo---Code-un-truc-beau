#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <termios.h>

struct termios    *setup(struct termios *old)
{
    struct termios raw;

    tcgetattr(STDIN_FILENO, &raw);//permet de recuperer les attributs du terminal
    tcgetattr(STDIN_FILENO, old);
    raw.c_lflag &= ~(ECHO | ICANON);//desactive le mode canonique
    raw.c_cc[VMIN] = 0;//nombre min de caractere a recevoir
    raw.c_cc[VTIME] = 0;//attente a 0
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);//defini les attributs terminal
    return (old);
}

int    get_key(char *buff, int length)
{
    int nb = read(0, buff, length);
    return (nb);
}

void    print_key(char    *buff, int size)
{
    printf("lettre : %d, %d, %d, %d\n", buff[0], buff[1], buff[2], size);
    fflush(stdout);//vide le tampon de sortie (merci google)
}

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

void	ft_put_simple_spaces(int x)
{
	while (x > 0)
	{
		write(1, " ", 1);
		x--;
	}
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

void	ft_print_img(int nb, int offset)
{
	int (i) = 0;
	int (j) = 0;
	int (k) = 0;
	while (i < nb)
	{
		ft_put_simple_spaces(offset);
		ft_put_spaces(k);
		write(1, "o\n", 2);
		if (k % 7 == 0 && k > 0)
		{
			i++;
			k++;
			j = k;
			while (k % 7 != 0)
			{
				ft_put_simple_spaces(offset);
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
}

int	main(int argc, char **argv)
{
	int (nb) = ft_atoi(argv[1]);
	int x = 0;

	struct termios	old;
	char	c[3];
	old = *setup(&old);
	while (1)
	{
		int size = get_key(c, 3);
		if (size && c[2] == 67)
		{
			if (x < 0)
				x = 0;
			x += 1;
			ft_print_img(nb, x);
		}
		if (size && c[2] == 68)
		{
			if (x < 0)
				x = 0;
			x -= 1;
			ft_print_img(nb, x);
		}
	}
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &old);
	
	
	
	if (argc < 2 || nb < 0 || nb > 40)
	{
		write(1, "Relancez en entrant uniquement 1 argument numerique compris entre 1 et 40\n", 74);
		return (1);
	}
	return 0;
}
