/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 10:45:12 by etattevi          #+#    #+#             */
/*   Updated: 2022/08/31 20:45:26 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>

# define READ_BUFF 4096

typedef struct s_list
{
	struct s_list	*next;
	char			*buff;
}	t_list;

typedef struct s_map_data
{
	bool			is_valid;
	char			empty_ch;
	char			obstacle_ch;
	char			full_ch;
	int				height;
	int				width;
	unsigned short	**map;
	unsigned short	biggest_sq;
	int				map_start_i;
}	t_map_data;

// input.c

char			*get_content(int fd);
void			get_input(int *argc, char **argv);

// metadata.c

t_map_data		*get_height(char *map, t_map_data *data, int *i);
t_map_data		*get_metadata(char *map, t_map_data *data, int *i);
int				get_nl_pos(char *map, int i);

// map.c

t_map_data		*set_invalid(t_map_data *data);
int				handle_nl(char *map, t_map_data *data, int line_nb, int i);
t_map_data		*parse_map(char *map, t_map_data *data, int i);
t_map_data		*get_map_data(char *map);

// algo.c

unsigned short	grow_sq(t_map_data *data, int y, int x);
void			grow_squares(t_map_data *data);
void			locate_biggest_sq(t_map_data *data, int *y, int *x);
void			paint_sq(t_map_data *data, char *map);

// list.c

t_list			*new_node(char *buff);
void			append_node(t_list **list, char *buff);
int				get_list_len(t_list *list);
void			free_list(t_list *list);
void			cat_list(char *out, t_list *list);

// utils.c

void			putstr(char *str);
char			*cpy_str(char *dest, char *src);
int				str_to_nb(char *str);
int				count_digits(int nb);
int				min_of_3(int a, int b, int c);

// main.c

void			parse_maps(char **maps, int nb_of_maps);
void			free_data(t_map_data *data, char *map);

#endif
