#include <iostream>

int	main(int ac, char **av)
{
	int		i;
	int		j;

	i = 0;
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while (ac > 1 && av && av[i])
	{
		j = 0;
		while (i > 0 && av[i][j])
        {
			std::cout << (char)std::toupper(av[i][j]);
            j++;
        }
        i++;
	}
	std::cout << std::endl; 
	return (0);
}