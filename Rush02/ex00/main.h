/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 13:32:34 by marmulle          #+#    #+#             */
/*   Updated: 2022/08/30 15:42:52 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# define BUFFER_SIZE 128000

typedef struct s_input
{
	char	*data;
	int		read_size;
	int		rows;
	int		cols;
}			t_input;

typedef struct s_rushes
{
	char	*rush00;
	char	*rush01;
	char	*rush02;
	char	*rush03;
	char	*rush04;
}			t_rushes;

typedef struct s_pos
{
	int		l;
	int		w;
	int		x;
	int		y;
}			t_pos;

t_input		*parse_input(void);
void		compare_input(t_input *input, t_rushes *rushes);
void		write_result(t_input *input, int variant);

void		ft_putnbr(int nb);
void		ft_putchar(char c);
int			ft_strcmp(char *s1, char *s2);

t_rushes	*gen_rushes(t_input *input);
t_rushes	*init_rushes(int read_size);
char		*gen_rush(t_input *input, int variant);
char		parse_variant(t_pos *pos, int variant);

char		rush00_parse_pos(t_pos *pos);
char		rush01_parse_pos(t_pos *pos);
char		rush02_parse_pos(t_pos *pos);
char		rush03_parse_pos(t_pos *pos);
char		rush04_parse_pos(t_pos *pos);

#endif
