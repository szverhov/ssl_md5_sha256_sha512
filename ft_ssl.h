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

#ifndef FT_SSL_H
#define FT_SSL_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define A 1732584193
#define B 4023233417
#define C 2562383102
#define D 271733878

#define F(x,y,z) ((x & y) | (~x & z))
#define G(x,y,z) ((x & z) | (y & ~z))
#define H(x,y,z) (x^y^z)
#define I(x,y,z) (y ^ (x | ~z))
#define RTT_LFT(a,s) ((a << s) | (a >> (32 - s)))
#define RTT_RGHT(a,s) ((a >> s) | (a << (32 - s)))

#define RR_512(a,s) ((a >> s) | (a << (64 - s)))

#define FIRST(a,b,c,d,k,i,s){a+=F(b,c,d)+k+i;a=RTT_LFT(a,s);a+=b;}
#define SECOND(a,b,c,d,k,i,s){a+=G(b,c,d)+k+i;a=RTT_LFT(a,s);a+=b;}
#define THIRD(a,b,c,d,k,i,s){a+=H(b,c,d)+k+i;a=RTT_LFT(a,s);a+=b;}
#define FOURTH(a,b,c,d,k,i,s){a+=I(b,c,d)+k+i;a=RTT_LFT(a,s);a+=b;}

#define ECHO(str){write(1, str, ft_strlen(str));}

typedef	struct			s_s512
{
	unsigned long long	h0;
	unsigned long long	h1;
	unsigned long long	h2;
	unsigned long long	h3;
	unsigned long long	h4;
	unsigned long long	h5;
	unsigned long long	h6;
	unsigned long long	h7;
	unsigned long long	a;
	unsigned long long	b;
	unsigned long long	c;
	unsigned long long	d;
	unsigned long long	e;
	unsigned long long	f;
	unsigned long long	g;
	unsigned long long	h;
	unsigned long long	w[80];
	unsigned long long	w_i;
	unsigned char		*data;
	unsigned long long	data_len;
	unsigned long long	t2;
	unsigned long long	t1;
	unsigned long long	b_len;
	unsigned long long	b_reserv;
	unsigned long long	i;
	unsigned char		*tmp;
	unsigned long long	strt_ln;
	unsigned long long	zero;
	unsigned long long	s0;
	unsigned long long	s1;
	unsigned long long	flag;
}					t_s512;

typedef struct		s_rffs512
{
	int				rd;
	unsigned int	data_count;
	unsigned char	buff[128];
	unsigned char	data[128];
	unsigned int	j;	
}					t_rffs512;

typedef struct		s_rffs
{
	int				rd;
	unsigned int	data_count;
	unsigned char	buff[64];
	unsigned char	data[64];
	unsigned int	j;	
}					t_rffs;

typedef struct		s_m
{
	unsigned int	a;
	unsigned int	b;
	unsigned int	c;
	unsigned int	d;
	unsigned char	*final;
	unsigned int	x[16];
}					t_m;

typedef struct	s_md5
{
	unsigned int		a;
	unsigned int		b;
	unsigned int		c;
	unsigned int		d;
	unsigned long long	len;

}					t_md5;

typedef struct		s_encode_vars
{
	unsigned int h0;
	unsigned int h1;
	unsigned int h2;
	unsigned int h3;
	unsigned int h4;
	unsigned int h5;
	unsigned int h6;
	unsigned int h7;
	unsigned int s0;
	unsigned int s1;
}					t_encode_vars;

typedef struct		s_tmp
{
	unsigned int a;
	unsigned int b;
	unsigned int c;
	unsigned int d;
	unsigned int e;
	unsigned int f;
	unsigned int g;
	unsigned int h;
}					t_tmp;

typedef struct		s_s256
{
	unsigned int	w[64];
	unsigned int	w_i;
	unsigned int	t1;
	unsigned int	t2;
	unsigned int	blen;
	unsigned char	*data;

}					t_s256;



t_encode_vars		g_ev;
t_tmp				g_tmp;
unsigned long long	g_start_count;

unsigned int		g_flags;
unsigned int		g_argvi;
unsigned int		*g_i_wrds;
unsigned int		g_count_is;

t_md5				g_md5;
unsigned char		g_str[1000000];
unsigned int		g_str_i;
unsigned int		g_fl_or_str;
char				*g_s_word;
char				*g_f_name;
unsigned int		g_data_64;

t_rffs512			g_rffs512;
t_s512				g_sh512;


unsigned int		ft_strlen(char *str);
unsigned char		*ft_add_single_bit(unsigned char **data,
	unsigned long long data_len);
unsigned int		ft_add_zero_to_data(unsigned char **data,
	unsigned long long data_len);
unsigned long long	ft_add_zeros(unsigned char **data,
	unsigned long long data_len);
unsigned int		ft_append_len(unsigned char **data,
	unsigned long long app_count, unsigned int *bits_len);
void				ft_fill_x(unsigned int *x, unsigned char *data,
	unsigned int count);
int					ft_encoded_to_str(unsigned int a,
	unsigned int b, unsigned int c, unsigned int d);
unsigned char		*ft_cpy_data(unsigned char *data,
	unsigned int count);
int					ft_start_encode(unsigned char *data,
	unsigned int bits_len);
void				ft_init_globals();
void				ft_save_index_of_word(unsigned int index);
int					ft_strcmp(char *str1, char *str2);
void				ft_parse_flags(char **argv);
int					ft_read_from_fd(int fd);
void				ft_read_data_from_argv(char **argv);
void				ft_read_data_from_files(char **argv);
int					ft_md5encode(char **argv);
unsigned char		*ft_add_single_bit_sh256(unsigned char **data,
	unsigned long long data_len);
unsigned int		ft_add_zero_to_data_sh256(unsigned char **data,
	unsigned long long data_len);
unsigned long long	ft_add_zeros_sh256(unsigned char **data,
	unsigned long long data_len);
void				ft_print_hash();
void				ft_init_encode_vars();
void				ft_init_tmps();
unsigned int		ft_sha256_len(unsigned char **data,
	unsigned long long start_count, unsigned bits_len);
void				ft_fill_w(unsigned int *x, unsigned char *data,
	unsigned int count);
void				ft_start_256_encode(unsigned char *data,
	unsigned int data_len);
int					ft_read_from_fd_sh256(int fd);
void				ft_read_data_from_argv_sh256(char **argv);
void				ft_read_data_from_files_sh256(char **argv);
void				ft_sha256encode(char **argv);
void				ft_print_hexa_uchar(unsigned char c);
void				ft_sha512encode(char **argv);
void				ft_init_start_vars();
void				ft_cpy_data512(unsigned char *data,
	unsigned long long data_len);
void				ft_add_byte(unsigned long long byte, unsigned long long reserv);
void				ft_zeros_512();
void				ft_append_len512();
void				ft_pre_fill();
void				ft_fill_w0_15();
void				ft_fill_w16_79();
void				ft_init_tmp_wars();
void				ft_peresip();
void				ft_summ_hash();
void				ft_print_hash512();
void				ft_start_hashing512(unsigned char *data,
	unsigned long long data_len);
int					ft_read_from_fd_sh512(int fd);
void				ft_read_data_from_files_sh512(char **argv);
void				ft_read_data_from_argv_sh512(char **argv);

#endif
