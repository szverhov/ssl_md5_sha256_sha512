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

void	ft_print_hexa_uchar(unsigned char c)
{
	unsigned char tmp;

	tmp = c >> 4;
	if (tmp > 9)
		tmp += 87;
	else
		tmp += 48;
	write(1, &tmp, 1);

	tmp = c << 4;
	tmp = tmp >> 4;
	if (tmp > 9)
		tmp += 87;
	else
		tmp += 48;
	write(1, &tmp, 1);
}
