/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 04:33:06 by morishitash       #+#    #+#             */
/*   Updated: 2023/12/06 04:38:10 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mini_ls.h"

void	free_files(t_file *file)
{
	t_file	*tmp;

	while (file != NULL)
	{
		tmp = file->next;
		free(file->name);
		file->name = NULL;
		free(file);
		file = tmp;
	}
}
