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

void			ft_init_globals()
{
	g_argvi = 2;
	g_flags = 0;
	g_i_wrds = (unsigned int*)malloc(sizeof(unsigned int));
	g_count_is = 0;
	g_md5.a = A;
	g_md5.b = B;
	g_md5.c = C;
	g_md5.d = D;
	g_md5.len = 0;
	g_str_i = 0;
	g_fl_or_str = 0;
	g_data_64 = 0;
}
