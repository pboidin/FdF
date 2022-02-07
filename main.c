/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piboidin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:52:04 by piboidin          #+#    #+#             */
/*   Updated: 2022/02/04 11:52:06 by piboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	s_fdf	*data;

	(void)argc;
	data = (s_fdf *)malloc(sizeof(s_fdf));
	if (!data)
		return (0);
	ft_file_reader(argv[1], data);
	return (0);
}
