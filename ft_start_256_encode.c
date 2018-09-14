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

unsigned int	g_k[64] = {
	0x428A2F98, 0x71374491, 0xB5C0FBCF, 0xE9B5DBA5, 0x3956C25B, 0x59F111F1, 0x923F82A4, 0xAB1C5ED5,
	0xD807AA98, 0x12835B01, 0x243185BE, 0x550C7DC3, 0x72BE5D74, 0x80DEB1FE, 0x9BDC06A7, 0xC19BF174,
	0xE49B69C1, 0xEFBE4786, 0x0FC19DC6, 0x240CA1CC, 0x2DE92C6F, 0x4A7484AA, 0x5CB0A9DC, 0x76F988DA,
	0x983E5152, 0xA831C66D, 0xB00327C8, 0xBF597FC7, 0xC6E00BF3, 0xD5A79147, 0x06CA6351, 0x14292967,
	0x27B70A85, 0x2E1B2138, 0x4D2C6DFC, 0x53380D13, 0x650A7354, 0x766A0ABB, 0x81C2C92E, 0x92722C85,
	0xA2BFE8A1, 0xA81A664B, 0xC24B8B70, 0xC76C51A3, 0xD192E819, 0xD6990624, 0xF40E3585, 0x106AA070,
	0x19A4C116, 0x1E376C08, 0x2748774C, 0x34B0BCB5, 0x391C0CB3, 0x4ED8AA4A, 0x5B9CCA4F, 0x682E6FF3,
	0x748F82EE, 0x78A5636F, 0x84C87814, 0x8CC70208, 0x90BEFFFA, 0xA4506CEB, 0xBEF9A3F7, 0xC67178F2
};

static void		ft_inner0(t_s256 *sha)
{
	g_ev.s0 = RTT_RGHT(sha->w[sha->w_i - 15], 7) ^
	RTT_RGHT(sha->w[sha->w_i - 15], 18) ^ (sha->w[sha->w_i - 15] >> 3);
	g_ev.s1 = RTT_RGHT(sha->w[sha->w_i - 2], 17) ^
	RTT_RGHT(sha->w[sha->w_i - 2], 19) ^ (sha->w[sha->w_i - 2] >> 10);
	sha->w[sha->w_i] = sha->w[sha->w_i - 16] +
	g_ev.s0 + sha->w[sha->w_i - 7] + g_ev.s1;
	sha->w_i++;
}

static void		ft_inner1(t_s256 *sha)
{
	sha->t2 = (RTT_RGHT(g_tmp.a, 2) ^ RTT_RGHT(g_tmp.a, 13)
	^ RTT_RGHT(g_tmp.a, 22)) +
	((g_tmp.a & g_tmp.b) ^ (g_tmp.a & g_tmp.c)
	^ (g_tmp.b & g_tmp.c));
	sha->t1 = g_tmp.h +
	(RTT_RGHT(g_tmp.e, 6) ^ RTT_RGHT(g_tmp.e, 11)
	^ RTT_RGHT(g_tmp.e, 25)) +
	((g_tmp.e & g_tmp.f) ^ ((~g_tmp.e) & g_tmp.g))
	+ g_k[sha->w_i] + sha->w[sha->w_i];
	g_tmp.h = g_tmp.g;
	g_tmp.g = g_tmp.f;
	g_tmp.f = g_tmp.e;
	g_tmp.e = g_tmp.d + sha->t1;
	g_tmp.d = g_tmp.c;
	g_tmp.c = g_tmp.b;
	g_tmp.b = g_tmp.a;
	g_tmp.a = sha->t1 + sha->t2;
	sha->w_i++;
}

static void		ft_inner2()
{
	g_ev.h0 += g_tmp.a;
	g_ev.h1 += g_tmp.b;
	g_ev.h2 += g_tmp.c;
	g_ev.h3 += g_tmp.d;
	g_ev.h4 += g_tmp.e;
	g_ev.h5 += g_tmp.f;
	g_ev.h6 += g_tmp.g;
	g_ev.h7 += g_tmp.h;	
}

static void		ft_inner3(t_s256 *sha, int *flag_c)
{
	while (sha->blen)
	{
		ft_fill_w(sha->w, sha->data, 64);
		ft_init_tmps();
		sha->w_i = 16;
		while (sha->w_i < 64)
			ft_inner0(sha);
		sha->w_i = 0;
		while (sha->w_i < 64)
			ft_inner1(sha);
		ft_inner2();
		sha->blen -= 512;
		sha->data += sha->blen == 0 ? 0 : 64;
		(*flag_c) += sha->blen == 0 ? 0 : 1;
	}	
}

void			ft_start_256_encode(unsigned char *data, unsigned int data_len)
{
	t_s256	sha;
	int		flag;
	int		flag_c;

	flag = 0;
	flag_c = 0;
	sha.blen = data_len * 8;
	if (data_len < 64)
	{
		sha.data = ft_add_single_bit_sh256(&data, data_len);
		sha.blen = ft_add_zeros_sh256(&sha.data, data_len);
		sha.blen = ft_sha256_len(&sha.data, g_start_count * 8, sha.blen);
		flag = 1;
	}
	else
		sha.data = data;
	ft_inner3(&sha, &flag_c);
	sha.data -= flag_c * 64;
	if (flag)
		free(sha.data);
}
