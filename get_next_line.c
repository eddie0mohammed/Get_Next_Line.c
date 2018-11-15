/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:59:05 by medun             #+#    #+#             */
/*   Updated: 2018/11/10 16:04:10 by medun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/includes/libft.h"

int		get_next_line(const int fd, char **line)
{
	static char	*s[4864];
	char		buf[BUFF_SIZE + 1];
	int			ret;
	char		*ptr;

	while ((!(!(line)) || (ret != -1)) &&
			(ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		ptr = s[fd];
		if (!(s[fd] = ft_strjoin(s[fd], buf)))
			s[fd] = ft_strdup(buf);
		ft_strdel(&ptr);
	}
	if ((ret == -1 || !ft_strlen(s[fd])) && (!line || (*line = ft_strnew(0))))
		return (ret);
	ptr = ft_strchr(s[fd], '\n');
	if (ptr && !(*ptr = '\0'))
		ptr = ft_strdup(ptr + 1);
	else
		ptr = ft_strnew(0);
	*line = ft_strdup(s[fd]);
	free(s[fd]);
	s[fd] = ptr;
	return (1);
}
