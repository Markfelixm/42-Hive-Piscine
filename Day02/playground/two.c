/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmulle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 12:11:19 by marmulle          #+#    #+#             */
/*   Updated: 2022/08/10 13:21:07 by marmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int main(void) {
	char first_letter = 'a';
	char last_letter = 'z';
	for (char i = first_letter; i <= last_letter; i++){	
		printf("%c", i);
	}
	printf("\n");
	return 0;
}
