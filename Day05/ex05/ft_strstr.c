/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marmulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 10:36:34 by marmulle          #+#    #+#             */
/*   Updated: 2022/08/16 19:26:02 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char	*match;
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		if (to_find[k] == str[i])
		{
			match = &str[i];
			k++;
		}
		else
			k = 0;
		if (to_find[k] == '\0')
			return (match - k + 1);
		i++;
	}
	return ((void *)0);
}
