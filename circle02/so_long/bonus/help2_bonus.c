/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdevove <zdevove@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:10:49 by zdevove           #+#    #+#             */
/*   Updated: 2023/01/29 18:20:04 by zdevove          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_next(int keycode, t_data *data)
{
	if (((keycode == 65361 || keycode == 97) \
		&& data->matrix[data->p_i][data->p_j - 1] == '1') \
			|| ((keycode == 65364 || keycode == 115) \
			&& data->matrix[data->p_i + 1][data->p_j] == '1') \
			|| ((keycode == 65363 || keycode == 100) \
			&& data->matrix[data->p_i][data->p_j + 1] == '1') \
			|| ((keycode == 65362 || keycode == 119) \
			&& data->matrix[data->p_i - 1][data->p_j] == '1'))
		return (1);
	return (0);
}

int	check_rectangular(t_data *data)
{
	int	i;
	int	j;

	if (data->nb_line == data->nb_column)
		return (0);
	i = 0;
	while (i < data->nb_line)
	{
		j = 0;
		while (data->matrix[i][j] && data->matrix[i][j] != '\n')
			j++;
		if (j != data->nb_column)
			return (0);
		i++;
	}
	return (1);
}

void	ft_print_step(t_data *data, int flg)
{
	char	*ptr;
	char	*str;

	ptr = print_steps(data->steps_count);
	str = ft_strjoin("steps count: ", ptr);
	if (flg == 1)
		ft_putendl_fd(str, 1);
	mlx_string_put(data->mlx, data->win, 16, 16, 0xFFFFFF, str);
	free(str);
	free(ptr);
}
