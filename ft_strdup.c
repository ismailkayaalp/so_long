/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikayaalp <ikayaalp@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 21:26:30 by ikayaalp          #+#    #+#             */
/*   Updated: 2022/08/11 21:26:30 by ikayaalp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

char	*ft_strdup(const char *str)
{
	size_t	i;
	char	*p1;
	size_t	index;

	index = 0;
	i = ft_strlen(str);
	p1 = malloc(sizeof(char) * (i + 1));
	if (!p1)
		return (NULL);
	while (str[index])
	{
		p1[index] = str[index];
		index++;
	}
	p1[index] = '\0';
	return (p1);
}

//yeni bir dizin açıp ona mallocla yer açıp kopyalar
