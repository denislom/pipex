/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 16:15:18 by dlom              #+#    #+#             */
/*   Updated: 2023/09/03 21:54:54 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/wait.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

char	**ft_split(char const *s, char c);
char	*ft_strdup(char *src);
int	ft_strlen(const char	*str);
int	ft_strncmp(const char *s1, const char *s2, size_t n);

#endif