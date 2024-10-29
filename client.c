/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:10:44 by juhtoo-h          #+#    #+#             */
/*   Updated: 2024/10/29 16:21:28 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "stdio.h"

void	ft_sendsignal(int pid, char *str)
{
	int	bit;

	bit = 0;
	while (*str)
	{
		if (((char)*str >> bit) % 2 == 0)
			if (kill(pid, SIGUSR1) == -1)
				ft_error_handler(0);
		if (((char)*str >> bit) % 2 == 1)
			if (kill(pid, SIGUSR2) == -1)
				ft_error_handler(0);
		bit++;
		if (bit == 8)
		{
			str++;
			bit = 0;
		}
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		write(1, "Use the format: ./client <PID> <string>\n", 40);
		exit(EXIT_FAILURE);
	}
	ft_sendsignal(ft_atoi(argv[1]), argv[2]);
	return (0);
}
