/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:17:20 by martorre          #+#    #+#             */
/*   Updated: 2024/04/02 17:40:15 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int main(int argc, char **argv)
{
    t_data  data;
    (void) argc;
    (void) argv;
    if (argc != 2)
        return (ft_fprintf(2 ,"Bad arguments :\\\n"), 2);
    data_init(argv[1], &data);
    if (data.map == NULL)
        ft_fprintf(2, "FFFFF\n");
    if (check_map(data))
    {
        ft_fprintf(1, "AA\n");
    }
    return (0);
}