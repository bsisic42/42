/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permissions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsisic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 15:35:43 by bsisic            #+#    #+#             */
/*   Updated: 2015/01/21 15:35:44 by bsisic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				print_permissions(t_data *file)
{
	char			rights[12];

	if (!has_extended_attr(file->path))
		rights[9] = ' ';
	else
		rights[9] = '@';
	rights[10] = '\0';
	print_file_type(file);
	rights[0] = (file->stat->st_mode & S_IRUSR) ? 'r' : '-';
	rights[1] = (file->stat->st_mode & S_IWUSR) ? 'w' : '-';
	if (file->stat->st_mode & S_IXUSR)
		rights[2] = 'x';
	else
		rights[2] = '-';
	if (file->stat->st_mode & S_ISUID)
	{
		if (file->stat->st_mode & 0100)
			rights[2] = 's';
		else
			rights[2] = 'S';
	}
	print_more_permissions(file, rights);
}

void				print_more_permissions(t_data *file, char *rights)
{
	rights[3] = (file->stat->st_mode & S_IRGRP) ? 'r' : '-';
	rights[4] = (file->stat->st_mode & S_IWGRP) ? 'w' : '-';
	if (file->stat->st_mode & S_IXGRP)
		rights[5] = 'x';
	else
		rights[5] = '-';
	if (file->stat->st_mode & S_ISGID)
	{
		if (file->stat->st_mode & 0010)
			rights[5] = 's';
		else
			rights[5] = 'S';
	}
	rights[6] = (file->stat->st_mode & S_IROTH) ? 'r' : '-';
	rights[7] = (file->stat->st_mode & S_IWOTH) ? 'w' : '-';
	print_moar_permissions(file, rights);
}

void				print_moar_permissions(t_data *file, char *rights)
{
	if (file->stat->st_mode & S_IXOTH)
		rights[8] = 'x';
	else
		rights[8] = '-';
	if (file->stat->st_mode & S_ISVTX)
	{
		if (file->stat->st_mode & 0100)
			rights[8] = 't';
		else
			rights[8] = 'T';
	}
	ft_putstr(rights);
}
