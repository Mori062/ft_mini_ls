/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 01:47:31 by morishitash       #+#    #+#             */
/*   Updated: 2023/12/06 04:37:18 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINI_LS_H
# define FT_MINI_LS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <dirent.h>
# include <sys/stat.h>
# include <time.h>
# include <errno.h>
# include "../libft/includes/libft.h"

# define RED "\033[31m"
# define RESET "\033[0m"

# define VALID 0
# define INVALID 1

typedef struct s_file
{
	char			*name;
	time_t			tv_sec;
	long			tv_nsec;
	struct s_file	*next;
}					t_file;

int		put_err(char *str);
int		check_arg(int argc);
int		count_files(void);
void	put_list_segment(t_file *file);
t_file	*init_files(int files_num);
void	free_files(t_file *file);

#endif