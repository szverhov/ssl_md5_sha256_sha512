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

static void		ft_write_len(unsigned int i, unsigned char **res,
	unsigned long long zero, unsigned long long start_count)
{
	(*res)[i] = zero | start_count >> 56;
	(*res)[i + 1] = zero | start_count >> 48;
	(*res)[i + 2] = zero | start_count >> 40;
	(*res)[i + 3] = zero | start_count >> 32;
	(*res)[i + 4] = zero | start_count >> 24;
	(*res)[i + 5] = zero | start_count >> 16;
	(*res)[i + 6] = zero | start_count >> 8;
	(*res)[i + 7] = zero | start_count;
	(*res)[i + 8] = zero;	
}

unsigned int	ft_sha256_len(unsigned char **data,
	unsigned long long start_count, unsigned bits_len)
{
	unsigned char		*res;
	unsigned int		i;
	unsigned int		count;

	i = 0;
	count = bits_len / 8;
	if (!(res = (unsigned char*)malloc(sizeof(unsigned char) * (count + 9))))
		return (0);
	while (count)
	{
		res[i] = (*data)[i];
		i++;
		count--;
	}
	ft_write_len(i, &res, 0, start_count);
	free(*data);
	(*data) = res;
	return (bits_len + 64); 	
}
