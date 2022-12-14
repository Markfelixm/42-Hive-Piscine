/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot42.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 19:38:31 by marmulle          #+#    #+#             */
/*   Updated: 2022/08/18 22:06:50 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_rot42(char *str)
{
	char	*start;

	start = str;
	while (*str)
	{
		*str += 42 - 26;
		if (!((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z')))
			*str -= 26;
		str++;
	}
	return (start);
}
