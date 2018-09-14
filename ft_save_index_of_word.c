/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f.ff                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szverhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0000/00/00 00:00:00 by szverhov          #+#    #+#             */
/*   Updated: 0000/00/00 00:00:00 by szverhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void			ft_save_index_of_word(unsigned int index)
{
	unsigned int *tmp;
	unsigned int i;

	g_flags |= 1024;
	if (g_count_is == 0)
	{
		g_i_wrds[g_count_is] = index;
		g_count_is++;
	}
	else
	{
		i = -1;
		tmp = (unsigned int*)malloc(sizeof(unsigned int) * (g_count_is + 1));
		while (++i < g_count_is)
			tmp[i] = g_i_wrds[i];
		tmp[i] = index;
		g_count_is++;
		free(g_i_wrds);
		g_i_wrds = tmp;
	}
	g_argvi++;
}
