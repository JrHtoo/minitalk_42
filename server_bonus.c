/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:46:05 by juhtoo-h          #+#    #+#             */
/*   Updated: 2024/11/01 15:43:58 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_signal_handler(int sig, siginfo_t *info, void *context)
{
	static unsigned char	letter = 0;
	static int				bit;

	(void)context;
	if (bit == 0)
		bit++;
	if (sig == SIGUSR1)
		letter += 0;
	else if (sig == SIGUSR2)
		letter += bit;
	bit <<= 1;
	if (bit == 256)
	{
		bit = 1;
		if (letter == 0)
			if (kill(info->si_pid, SIGUSR2) == -1)
				ft_error_handler(0);
		if (letter != 0)
			write(1, &letter, 1);
		letter = 0;
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
