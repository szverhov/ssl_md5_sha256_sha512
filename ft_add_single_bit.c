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

unsigned char	*ft_add_single_bit(unsigned char **data,
	unsigned long long data_len)
{
	unsigned char	*res;
	unsigned int	i;

	i = 0;
	if (!(res = (unsigned char*)malloc(sizeof(unsigned char) * data_len + 2)))
		return (0);
	while (data_len--)
	{
		res[i] = (*data)[i];
		i++;
	}
	res[i] = (unsigned char)128;
	res[++i] = 0;
	free(*data);
	return (res); 
}
