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

unsigned int	ft_add_zero_to_data(unsigned char **data,
	unsigned long long data_len)
{
	unsigned char		*res;
	unsigned long long	i;

	i = -1;
	if (!(res = (unsigned char*)malloc(sizeof(unsigned char)
	* (data_len / 8) + 2)))
		return (0);
	while (++i < (data_len / 8) + 1)
	{
		res[i] = (*data)[i];
	}
	res[i] = 0;
	res[++i] = 0;
	free(*data);
	(*data) = res;
 	return (1);
}
