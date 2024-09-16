/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ducnguye <ducnguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 19:24:31 by ducnguye          #+#    #+#             */
/*   Updated: 2024/09/16 19:29:33 by ducnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/display_map.h"
#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		write(2, "File name missing.\n", 19);
		return (1);
	}
	if (argc > 2)
	{
		write(2, "Too many arguments.\n", 20);
		return (1);
	}
	display_map(argv[1]);
	return (0);
}
