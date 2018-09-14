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

void			ft_fill_w(unsigned int *x, unsigned char *data, unsigned int count)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	while (j < count)
	{
		x[i] = (data[j] << 24) | (data[j + 1] << 16)
		| (data[j + 2] << 8) | (data[j + 3]);
		i++;
		j += 4;
	}
}
