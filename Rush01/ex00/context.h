/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:45:31 by tjaasalo          #+#    #+#             */
/*   Updated: 2022/08/21 23:18:16 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTEXT_H
# define CONTEXT_H
# include <stdbool.h>

typedef struct s_context {
	short	*rows;
	short	*cols;
	short	*sqrs;
}	t_context;

t_context	*new_context(void);
short		*context_array(void);
bool		set(t_context *ctx, int index, int value);

#endif
