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

void				ft_summ_hash()
{
	g_sh512.h0 += g_sh512.a;
	g_sh512.h1 += g_sh512.b;
	g_sh512.h2 += g_sh512.c;
	g_sh512.h3 += g_sh512.d;
	g_sh512.h4 += g_sh512.e;
	g_sh512.h5 += g_sh512.f;
	g_sh512.h6 += g_sh512.g;
	g_sh512.h7 += g_sh512.h;
}
