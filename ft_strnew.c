/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouhaddo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 19:05:25 by nouhaddo          #+#    #+#             */
/*   Updated: 2018/10/09 13:46:18 by nouhaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*str;
	int		i;

	str = (char*)malloc((size + 1) * sizeof(char));
	if (str == 0)
		return (0);
	i = (int)size;
	while (i >= 0)
		str[i--] = '\0';
	return (str);
}
