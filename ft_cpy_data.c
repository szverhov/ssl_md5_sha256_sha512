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

unsigned char *ft_cpy_data(unsigned char *data, unsigned int count)
{
	unsigned char	*res;
	unsigned int	i;

	i = 0;
	res = (unsigned char*)malloc(sizeof(unsigned char) * count);
	while (count)
	{
		res[i] = data[i];
		count--;
		i++;
	}
	return (res);
}
