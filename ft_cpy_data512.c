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

void				ft_cpy_data512(unsigned char *data, unsigned long long data_len)
{
	g_sh512.data_len = data_len;
	g_sh512.strt_ln += data_len;
	g_sh512.i = -1;
	g_sh512.data = (unsigned char*)malloc(sizeof(unsigned char) * data_len);
	while (++(g_sh512.i) < data_len)
		g_sh512.data[g_sh512.i] = data[g_sh512.i];
}
