/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 01:47:22 by morishitash       #+#    #+#             */
/*   Updated: 2023/12/06 04:37:42 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mini_ls.h"

void	swap_files(t_file *file1, t_file *file2)
{
	t_file	*tmp;

	tmp = (t_file *)malloc(sizeof(t_file));
	tmp->name = file1->name;
	tmp->tv_sec = file1->tv_sec;
	tmp->tv_nsec = file1->tv_nsec;
	file1->name = file2->name;
	file1->tv_sec = file2->tv_sec;
	file1->tv_nsec = file2->tv_nsec;
	file2->name = tmp->name;
	file2->tv_sec = tmp->tv_sec;
	file2->tv_nsec = tmp->tv_nsec;
	free(tmp);
}

void	sort_files(t_file *file)
{
	t_file	*tmp;
	t_file	*head;

	head = file;
	while (file != NULL)
	{
		tmp = head;
		while (tmp != NULL)
		{
			if (tmp->tv_sec > file->tv_sec)
				swap_files(tmp, file);
			else if (tmp->tv_sec == file->tv_sec)
			{
				if (tmp->tv_nsec > file->tv_nsec)
					swap_files(tmp, file);
				else if (tmp->tv_nsec == file->tv_nsec)
				{
					if (ft_strcmp(tmp->name, file->name) > 0)
						swap_files(tmp, file);
				}
			}
			tmp = tmp->next;
		}
		file = file->next;
	}
}

void	print_files(t_file *files)
{
	while (files != NULL)
	{
		ft_putstr_fd(files->name, 1);
		ft_putstr_fd("\n", 1);
		files = files->next;
	}
}

int	main(int argc, char **argv)
{
	t_file	*files;

	(void)argv;
	if (check_arg(argc) == INVALID)
		return (1);
	files = init_files(count_files());
	put_list_segment(files);
	if (files == NULL)
	{
		free_files(files);
		put_err("Error: Failed to allocate memory\n");
		return (1);
	}
	sort_files(files);
	print_files(files);
	free_files(files);
	return (0);
}

#ifdef DEBUG

__attribute__((destructor))
static void	destructor(void)
{
	printf("---------------------------\n");
	system("leaks -q ft_mini_ls");
}

#endif