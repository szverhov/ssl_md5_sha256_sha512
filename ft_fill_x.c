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

void			ft_fill_x(unsigned int *x, unsigned char *data, unsigned int count)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	while (j < count)
	{
		x[i] = (data[j]) | (data[j + 1] << 8) |
		(data[j + 2] << 16) | (data[j + 3] << 24);
		i++;
		j += 4;
	}
}
