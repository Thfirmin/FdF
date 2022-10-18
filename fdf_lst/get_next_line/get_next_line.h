/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 06:26:16 by thfirmin          #+#    #+#             */
/*   Updated: 2022/10/15 09:02:22 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <stdlib.h>
# include <unistd.h>

typedef struct s_file
{
	int				f_fd;
	char			*f_str;
	struct s_file	*newfile;
}					t_file;

char	*get_next_line(int fd);
char	*read_line(int fd, char *str);
char	*take_line(char *str);
char	*ft_ftstrchr(char *str, int c);
char	*ft_ftstrjoin(char *s1, char *s2);
size_t	ft_ftstrlen(char *str);
char	*take_line(char *str);
char	*clean_buffer(char *buffer);
t_file	*backup_line(int fd, t_file *list);
t_file	*addnew_list(int fd, t_file *list);
t_file	*ft_free(t_file *list, t_file *node);

#endif
