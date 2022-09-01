/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 12:17:44 by marmulle          #+#    #+#             */
/*   Updated: 2022/08/18 12:24:34 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_generic(void)
{
	char	*melody;

	melody = "Tu tu tu tu ; Tu tu tu tu";
	write(1, melody, 25);
	write(1, "\n", 1);
}
