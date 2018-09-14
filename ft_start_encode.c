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

static	void	ft_inner0(t_m *m5)
{
	m5->a = g_md5.a;
	m5->b = g_md5.b;
	m5->c = g_md5.c;
	m5->d = g_md5.d;
	FIRST(m5->a, m5->b, m5->c, m5->d, m5->x[0], 3614090360, 7);
	FIRST(m5->d, m5->a, m5->b, m5->c, m5->x[1], 3905402710, 12);
	FIRST(m5->c, m5->d, m5->a, m5->b, m5->x[2], 606105819, 17);
	FIRST(m5->b, m5->c, m5->d, m5->a, m5->x[3], 3250441966, 22);
	FIRST(m5->a, m5->b, m5->c, m5->d, m5->x[4], 4118548399, 7);
	FIRST(m5->d, m5->a, m5->b, m5->c, m5->x[5], 1200080426, 12);
	FIRST(m5->c, m5->d, m5->a, m5->b, m5->x[6], 2821735955, 17);
	FIRST(m5->b, m5->c, m5->d, m5->a, m5->x[7], 4249261313, 22);
	FIRST(m5->a, m5->b, m5->c, m5->d, m5->x[8], 1770035416, 7);
	FIRST(m5->d, m5->a, m5->b, m5->c, m5->x[9], 2336552879, 12);
	FIRST(m5->c, m5->d, m5->a, m5->b, m5->x[10], 4294925233, 17);
	FIRST(m5->b, m5->c, m5->d, m5->a, m5->x[11], 2304563134, 22);
	FIRST(m5->a, m5->b, m5->c, m5->d, m5->x[12], 1804603682, 7);
	FIRST(m5->d, m5->a, m5->b, m5->c, m5->x[13], 4254626195, 12);
	FIRST(m5->c, m5->d, m5->a, m5->b, m5->x[14], 2792965006, 17);
	FIRST(m5->b, m5->c, m5->d, m5->a, m5->x[15], 1236535329, 22);
}

static	void	ft_inner1(t_m *m5)
{
	SECOND(m5->a, m5->b, m5->c, m5->d, m5->x[1], 4129170786, 5);
	SECOND(m5->d, m5->a, m5->b, m5->c, m5->x[6], 3225465664, 9);
	SECOND(m5->c, m5->d, m5->a, m5->b, m5->x[11], 643717713, 14);
	SECOND(m5->b, m5->c, m5->d, m5->a, m5->x[0], 3921069994, 20);
	SECOND(m5->a, m5->b, m5->c, m5->d, m5->x[5], 3593408605, 5);
	SECOND(m5->d, m5->a, m5->b, m5->c, m5->x[10], 38016083, 9);
	SECOND(m5->c, m5->d, m5->a, m5->b, m5->x[15], 3634488961, 14);
	SECOND(m5->b, m5->c, m5->d, m5->a, m5->x[4], 3889429448, 20);
	SECOND(m5->a, m5->b, m5->c, m5->d, m5->x[9], 568446438, 5);
	SECOND(m5->d, m5->a, m5->b, m5->c, m5->x[14], 3275163606, 9);
	SECOND(m5->c, m5->d, m5->a, m5->b, m5->x[3], 4107603335, 14);
	SECOND(m5->b, m5->c, m5->d, m5->a, m5->x[8], 1163531501, 20);
	SECOND(m5->a, m5->b, m5->c, m5->d, m5->x[13], 2850285829, 5);
	SECOND(m5->d, m5->a, m5->b, m5->c, m5->x[2], 4243563512, 9);
	SECOND(m5->c, m5->d, m5->a, m5->b, m5->x[7], 1735328473, 14);
	SECOND(m5->b, m5->c, m5->d, m5->a, m5->x[12], 2368359562, 20);
}

static	void	ft_inner2(t_m *m5)
{
	THIRD(m5->a, m5->b, m5->c, m5->d, m5->x[5], 4294588738, 4);
	THIRD(m5->d, m5->a, m5->b, m5->c, m5->x[8], 2272392833, 11);
	THIRD(m5->c, m5->d, m5->a, m5->b, m5->x[11], 1839030562, 16);
	THIRD(m5->b, m5->c, m5->d, m5->a, m5->x[14], 4259657740, 23);
	THIRD(m5->a, m5->b, m5->c, m5->d, m5->x[1], 2763975236, 4);
	THIRD(m5->d, m5->a, m5->b, m5->c, m5->x[4], 1272893353, 11);
	THIRD(m5->c, m5->d, m5->a, m5->b, m5->x[7], 4139469664, 16);
	THIRD(m5->b, m5->c, m5->d, m5->a, m5->x[10], 3200236656, 23);
	THIRD(m5->a, m5->b, m5->c, m5->d, m5->x[13], 681279174, 4);
	THIRD(m5->d, m5->a, m5->b, m5->c, m5->x[0], 3936430074, 11);
	THIRD(m5->c, m5->d, m5->a, m5->b, m5->x[3], 3572445317, 16);
	THIRD(m5->b, m5->c, m5->d, m5->a, m5->x[6], 76029189, 23);
	THIRD(m5->a, m5->b, m5->c, m5->d, m5->x[9], 3654602809, 4);
	THIRD(m5->d, m5->a, m5->b, m5->c, m5->x[12], 3873151461, 11);
	THIRD(m5->c, m5->d, m5->a, m5->b, m5->x[15], 530742520, 16);
	THIRD(m5->b, m5->c, m5->d, m5->a, m5->x[2], 3299628645, 23);
}

static	void	ft_inner3(t_m *m5)
{
	FOURTH(m5->a, m5->b, m5->c, m5->d, m5->x[0], 4096336452, 6);
	FOURTH(m5->d, m5->a, m5->b, m5->c, m5->x[7], 1126891415, 10);
	FOURTH(m5->c, m5->d, m5->a, m5->b, m5->x[14], 2878612391, 15);
	FOURTH(m5->b, m5->c, m5->d, m5->a, m5->x[5], 4237533241, 21);
	FOURTH(m5->a, m5->b, m5->c, m5->d, m5->x[12], 1700485571, 6);
	FOURTH(m5->d, m5->a, m5->b, m5->c, m5->x[3], 2399980690, 10);
	FOURTH(m5->c, m5->d, m5->a, m5->b, m5->x[10], 4293915773, 15);
	FOURTH(m5->b, m5->c, m5->d, m5->a, m5->x[1], 2240044497, 21);
	FOURTH(m5->a, m5->b, m5->c, m5->d, m5->x[8], 1873313359, 6);
	FOURTH(m5->d, m5->a, m5->b, m5->c, m5->x[15], 4264355552, 10);
	FOURTH(m5->c, m5->d, m5->a, m5->b, m5->x[6], 2734768916, 15);
	FOURTH(m5->b, m5->c, m5->d, m5->a, m5->x[13], 1309151649, 21);
	FOURTH(m5->a, m5->b, m5->c, m5->d, m5->x[4], 4149444226, 6);
	FOURTH(m5->d, m5->a, m5->b, m5->c, m5->x[11], 3174756917, 10);
	FOURTH(m5->c, m5->d, m5->a, m5->b, m5->x[2], 718787259, 15);
	FOURTH(m5->b, m5->c, m5->d, m5->a, m5->x[9], 3951481745, 21);
	g_md5.a += m5->a;
	g_md5.b += m5->b;
	g_md5.c += m5->c;
	g_md5.d += m5->d;
}

int				ft_start_encode(unsigned char *data, unsigned int bits_len)
{
	t_m m5;

	m5.final = 0;
	if (bits_len < 512)
	{
		m5.final = ft_cpy_data(data, bits_len / 8);
		m5.final = ft_add_single_bit(&(m5.final), bits_len / 8);
		bits_len = ft_add_zeros(&(m5.final), (bits_len + 1) / 8);
		ft_append_len(&(m5.final), g_md5.len * 8, &bits_len);
		ft_fill_x(m5.x, m5.final, 64);
	}
	else
		ft_fill_x(m5.x, data, 64);
	while (bits_len)
	{
		ft_inner0(&m5);
		ft_inner1(&m5);
		ft_inner2(&m5);
		ft_inner3(&m5);
		if (bits_len > 512)
			ft_fill_x(m5.x, (m5.final + (g_data_64 += 64)), 64);	
		bits_len -= 512;
	 }
	free(m5.final);
	return (1);
}
