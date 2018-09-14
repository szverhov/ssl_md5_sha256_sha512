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

unsigned long long	ft_add_zeros(unsigned char **data,
	unsigned long long data_len)
{
	unsigned long long	bits_len;
	unsigned int		reserv_bits;

	bits_len = data_len * 8 - 7;
	reserv_bits = 7;

	while (bits_len % 512 != 448)
	{
		if (reserv_bits == 0)
		{
			reserv_bits = 8;
			if (!(ft_add_zero_to_data(&(*data), bits_len)))
				return (0);
		}
		reserv_bits--;
		bits_len++;
	}
	return (bits_len);
}
