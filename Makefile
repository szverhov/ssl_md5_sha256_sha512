# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: szverhov <szverhov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/07 09:08:03 by szverhov          #+#    #+#              #
#    Updated: 2017/11/06 12:25:29 by szverhov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ssl_md5

CC = gcc

CFLAGS = -Wall -Wextra -Werror

FILES = ft_add_single_bit.c ft_fill_w.c ft_read_data_from_argv.c ft_add_single_bit_sh256.c \
        ft_fill_x.c ft_read_data_from_argv_sh256.c ft_start_256_encode.c ft_add_zero_to_data.c \
        ft_init_encode_vars.c ft_read_data_from_files.c ft_start_encode.c ft_add_zero_to_data_sh256.c \
        ft_init_globals.c ft_read_data_from_files_sh256.c ft_strcmp.c ft_add_zeros.c ft_init_tmps.c \
        ft_read_from_fd.c ft_strlen.c ft_add_zeros_sh256.c ft_md5encode.c ft_read_from_fd_sh256.c \
        main.c ft_append_len.c ft_parse_flags.c ft_save_index_of_word.c ft_cpy_data.c ft_print_hash.c \
        ft_sha256_len.c ft_encoded_to_str.c ft_print_hexa_uchar.c ft_sha256encode.c ft_sha512encode.c \
        ft_init_start_vars.c ft_cpy_data512.c ft_add_byte.c ft_zeros_512.c ft_append_len512.c \
        ft_pre_fill.c ft_fill_w0_15.c ft_fill_w16_79.c ft_init_tmp_wars.c ft_peresip.c ft_summ_hash.c \
        ft_print_hash512.c ft_start_hashing512.c ft_read_from_fd_sh512.c ft_read_data_from_files_sh512.c \
        ft_read_data_from_argv_sh512.c 

OBJ = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
