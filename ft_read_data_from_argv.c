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

static void		ft_inner(unsigned int *i)
{
	ft_start_encode((unsigned char*)"", 0);
	(*i)++;
	g_s_word = "";
	ft_encoded_to_str(g_md5.a, g_md5.b , g_md5.c , g_md5.d);
}

static void		ft_inner1(unsigned int *buff_count,
	unsigned int *j, unsigned char *buff)
{
	(*buff_count)++;
	(*j)++;
	g_md5.len++;
	if ((*buff_count) == 64)
	{
		ft_start_encode(buff, 512);
		(*buff_count) = 0;
	}	
}

static void		ft_inner2(unsigned int buff_count,
	unsigned char *buff, unsigned int *i, char **argv)
{
	if (buff_count > 0)
		ft_start_encode(buff, buff_count * 8);
	else if (g_md5.len == 0 || g_md5.len % 64 == 0)
		ft_start_encode((unsigned char*)"", 0);
	g_s_word = argv[g_i_wrds[(*i)]];
	ft_encoded_to_str(g_md5.a, g_md5.b , g_md5.c , g_md5.d);
	(*i)++;	
}

void			ft_read_data_from_argv(char **argv)
{
	unsigned int	i;
	unsigned char	buff[64];
	unsigned int	j;
	unsigned int	buff_count;

	i = 0;
	g_fl_or_str = 1;
	while (i < g_count_is)
	{
		j = 0;
		buff_count = 0;
		if (argv[g_i_wrds[i]][j] == 0)
		{
			ft_inner(&i);
			continue ;
		}
		while (argv[g_i_wrds[i]][j])
		{
			buff[buff_count] = argv[g_i_wrds[i]][j];
			ft_inner1(&buff_count, &j, buff);
		}
		ft_inner2(buff_count, buff, &i, argv);
	}
}
