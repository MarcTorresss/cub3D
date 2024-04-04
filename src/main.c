/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:17:20 by martorre          #+#    #+#             */
/*   Updated: 2024/04/04 19:22:32 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void    free_all(t_data *data)
{
    int	y;

	y = 0;
	while (data->file[y] != NULL)
	{
		free(data->file[y]);
		y++;
	}
	free(data->file);
    // free(data->elem.NO);
    // free(data->elem.SO);
    // free(data->elem.WE);
    // free(data->elem.EA);
    // free(data->elem.F);
    // free(data->elem.C);
}

int main(int argc, char **argv)
{
    t_data  data;
    (void) argc;
    (void) argv;
    if (argc != 2)
        return (ft_fprintf(2 ,"Bad arguments :\\\n"), 2);
    data_init(argv[1], &data);
    if (data.file == NULL)
        return (1);
    if (check_elements(&data) == 1)
        return (ft_fprintf(2, ERR_ELE), free_all(&data), 1);
    if (init_map(&data) == 1)
       return (ft_fprintf(2, ERR_MAP), free_all(&data), 1);
    else
        ft_fprintf(1, "OK elements :)\n");
    //calc_x_y(&data);
    //if (check_map(data))
    //{
    //   ft_fprintf(2, ERR_MAP);
    //}
    return (0);
}