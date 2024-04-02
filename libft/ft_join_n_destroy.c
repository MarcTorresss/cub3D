/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_n_destroy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:08:00 by rbarbier          #+#    #+#             */
/*   Updated: 2024/03/12 15:17:43 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_join_n_destroy(char *s1, char *s2, int to_free)
{
	char	*new;

	if (!s1 || !s2)
		return (NULL);
	else if (!s1)
		new = ft_strdup(s2);
	else if (!s2)
		new = ft_strdup(s1);
	else
		new = ft_strjoin(s1, s2);
	if (to_free == 1 && s1)
		free(s1);
	else if (to_free == 2 && s2)
		free(s2);
	else if (to_free == 3 && s1 && s2)
	{
		free(s1);
		free(s2);
	}
	return (new);
}
