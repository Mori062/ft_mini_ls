/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 03:28:43 by morishitash       #+#    #+#             */
/*   Updated: 2023/12/06 04:38:05 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mini_ls.h"

int	put_err(char *str)
{
	write(2, RED, 5);
	write(2, str, ft_strlen(str));
	write(2, RESET, 4);
	return (1);
}

int	check_arg(int argc)
{
	DIR	*dir;

	if (argc != 1)
	{
		put_err("Error: Too many arguments\n");
		return (INVALID);
	}
	dir = opendir("./");
	if (dir == NULL)
	{
		put_err("Error: Permission denied\n");
		return (INVALID);
	}
	closedir(dir);
	return (VALID);
}

t_file	*init_files(int files_num)
{
	t_file	*files;
	t_file	*head;
	t_file	*prev;
	int		i;

	i = 0;
	while (i < files_num)
	{
		files = (t_file *)malloc(sizeof(t_file));
		if (files == NULL)
			return (NULL);
		files->next = NULL;
		files->name = NULL;
		if (i == 0)
			head = files;
		else
			prev->next = files;
		prev = files;
		i++;
	}
	return (head);
}

int	count_files(void)
{
	DIR				*dir;
	int				files_num;
	struct dirent	*entry;

	files_num = 0;
	dir = opendir("./");
	entry = readdir(dir);
	while (entry != NULL)
	{
		if (entry->d_name[0] == '.')
		{
			entry = readdir(dir);
			continue ;
		}
		files_num++;
		entry = readdir(dir);
	}
	closedir(dir);
	return (files_num);
}

void	put_list_segment(t_file *files)
{
	DIR				*dir;
	struct dirent	*entry;
	struct stat		stat;

	dir = opendir("./");
	entry = readdir(dir);
	while (entry != NULL)
	{
		if (entry->d_name[0] == '.')
		{
			entry = readdir(dir);
			continue ;
		}
		files->name = ft_strdup(entry->d_name);
		lstat(files->name, &stat);
		files->tv_sec = stat.st_mtimespec.tv_sec;
		files->tv_nsec = stat.st_mtimespec.tv_nsec;
		files = files->next;
		entry = readdir(dir);
	}
	closedir(dir);
}
