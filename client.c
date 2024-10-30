/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:10:44 by juhtoo-h          #+#    #+#             */
/*   Updated: 2024/10/30 16:12:05 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

void	ft_send_signal(int pid, char *str)
{
	static int	bit;

	while (*str)
	{
		if ((((unsigned char)*str >> bit) % 2) == 0)
			if(kill(pid, SIGUSR1) == -1)
				ft_error_handler(0);

		if ((((unsigned char)*str >> bit) % 2) == 1)
			if(kill(pid, SIGUSR2) == -1)
				ft_error_handler(0);
		usleep(200));
		bit++;
		if (bit == 8)
		{
			str++;
			bit = 0;
		}
	}
}

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		write(1, "Use the format: ./client <PID> <String>\n", 44);
		exit(EXIT_FAILURE);
	}
	ft_send_signal(ft_atoi(av[1]), av[2]);
	return (0);
}
