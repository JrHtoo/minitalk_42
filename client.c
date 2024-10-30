/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:10:44 by juhtoo-h          #+#    #+#             */
/*   Updated: 2024/10/30 11:46:32 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

void	ft_send_signal(int pid, char *str)
{
	static int	bit;

	if (*str)
	{
		if (((*str >> bit) % 2) == 0)
			kill(pid, SIGUSR1);
		if (((*str >> bit) % 2) == 1)
			kill(pid, SIGUSR2);
		bit++;
		if (bit == 8)
		{
			printf("%s\n", str);
			str++;
			bit = 1;
			usleep(50);
		}
	}
}

void	ft_receipt(int sig)
{
	if (sig == SIGUSR1)
		return ;
	if (sig == SIGUSR2)
		exit(EXIT_SUCCESS);
}


int	main(int ac, char **av)
{
	if (ac != 3)
	{
		write(1, "Utilisez le format: ./client <PID> <String>\n", 44);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		ft_send_signal(ft_atoi(av[1]), av[2]);
		signal(SIGUSR1, ft_receipt);
		signal(SIGUSR2, ft_receipt);
		pause();
	}
	return (0);
}
