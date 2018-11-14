/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouhaddo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 11:08:49 by nouhaddo          #+#    #+#             */
/*   Updated: 2018/10/16 19:36:50 by nouhaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lst				*ft_creat_cerclelst(int fd)
{
	t_lst			*fresh;

	if (!(fresh = (t_lst*)malloc(sizeof(t_lst))))
		return (NULL);
	fresh->rd = NULL;
	fresh->fd = fd;
	fresh->next = fresh;
	return (fresh);
}

t_lst				*add_o_return(t_lst *content, int fd)
{
	t_lst			*head;

	head = content;
	if (content->fd == fd)
		return (content);
	content = content->next;
	while (content != head)
	{
		if (content->fd == fd)
			return (content);
		content = content->next;
	}
	if (!(content = (t_lst*)malloc(sizeof(t_lst))))
		return (NULL);
	content->rd = NULL;
	content->fd = fd;
	content->next = head->next;
	head->next = content;
	return (content);
}

char				*ft_linestring(char *s, char *line)
{
	size_t			i;

	i = 0;
	while (s[i] != '\n' && s[i])
		i++;
	line = ft_strnew(i);
	i = 0;
	while (s[i] != '\n' && s[i])
	{
		line[i] = s[i];
		i++;
	}
	return (line);
}

int					get_next_line(const int fd, char **line)
{
	static t_lst	*fdc;
	char			buffer[BUFF_SIZE + 1];
	char			*copy;
	int				r;

	if (line == NULL || fd < 0)
		return (-1);
	fdc = (!fdc) ? ft_creat_cerclelst(fd) : add_o_return(fdc, fd);
	while ((r = read(fd, buffer, BUFF_SIZE)))
	{
		if (r < 0)
			return (-1);
		buffer[r] = '\0';
		copy = fdc->rd;
		fdc->rd = ft_strjoin(copy, buffer);
		free(copy);
		if (ft_ischarin(buffer, '\n'))
			break ;
	}
	copy = fdc->rd;
	if (!ft_strcmp(copy, ""))
		return (0);
	*line = ft_strdup(ft_linestring(copy, *line));
	fdc->rd = (ft_ischarin(copy, '\n')) ?\
		ft_strdup(ft_strchr(copy, '\n') + 1) : ft_strdup("");
	free(copy);
	return (1);
}
