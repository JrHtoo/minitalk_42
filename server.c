/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:10:41 by juhtoo-h          #+#    #+#             */
/*   Updated: 2024/10/29 16:21:48 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

void	ft_signal_handler(int sig, siginfo_t *info, void *context)
{
	static int		bit;
	static char		word;

	(void)context;
	bit = 1;
	if (sig == SIGUSR1)
		word += 0;
	else if (sig == SIGUSR2)
		word += bit;
	bit <<= 1;
	if (bit == 256)
	{
		bit = 1;
		word = 0;
		write(1, &word, 1);
	}
	if (kill(info->si_pid, SIGUSR1) == -1)
		ft_error_handler(0);
}

int	main(void)
{
	struct sigaction	action;

	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = ft_signal_handler;
	if (sigaction(SIGUSR1, &action, NULL) == -1
		|| sigaction(SIGUSR2, &action, NULL) == -1)
	{
		ft_error_handler(1);
		return (1);
	}
	write(1, "PID = ", 6);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
