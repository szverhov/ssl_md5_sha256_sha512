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
	ft_start_hashing512((unsigned char*)"", 0);
	(*i)++;
	g_s_word = "";
	ft_print_hash512();
}

static void		ft_inner1(unsigned int *buff_count,
	unsigned int *j, unsigned char *buff)
{
	(*buff_count)++;
	(*j)++;
	g_start_count++;
	if ((*buff_count) == 128)
	{
		ft_start_hashing512(buff, (*buff_count));
		(*buff_count) = 0;
	}	
}

static void		ft_inner2(unsigned int buff_count,
	unsigned char *buff, unsigned int *i, char **argv)
{
	if (buff_count > 0)
		ft_start_hashing512(buff, buff_count);
	else if (g_start_count == 0 || g_start_count % 128 == 0)
		ft_start_hashing512((unsigned char*)"", 0);
	g_s_word = argv[g_i_wrds[(*i)]];
	ft_print_hash512();
	(*i)++;	
}

void			ft_read_data_from_argv_sh512(char **argv)
{
	unsigned int	i;
	unsigned char	buff[128];
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
