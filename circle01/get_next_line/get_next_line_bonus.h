/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdevove <zdevove@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:28:26 by zdevove           #+#    #+#             */
/*   Updated: 2022/11/29 09:45:43 by zdevove          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H

# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(const char *s);

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_strchr(const char *str, int c);

char	*ft_substr(char const *s, unsigned int start, size_t len);

size_t	ft_strlcpy(char *dst, const char *src, size_t size);

char	*get_rd_to_buffer(int fd, char *buffer);

char	*get_line(char *buffer);

char	*get_rest(char *buffer);

char	*get_next_line(int fd);

#endif
