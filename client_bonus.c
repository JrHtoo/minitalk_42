/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:46:52 by juhtoo-h          #+#    #+#             */
/*   Updated: 2024/11/01 15:39:41 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_terminator(int pid)
{
	static int	i;

	if (i <= 8)
		if (kill(pid, SIGUSR1) == -1)
			ft_error_handler(0);
	i++;
}

void	ft_send_signal(int pid, char *str)
{
	static int	bit;
	static char	*str_bit = 0;

	if (str)
		str_bit = str;
	if (*str_bit)
	{
		if ((((unsigned char)*str_bit >> bit) % 2) == 0)
			if (kill(pid, SIGUSR1) == -1)
				ft_error_handler(0);
		if ((((unsigned char)*str_bit >> bit) % 2) == 1)
			if (kill(pid, SIGUSR2) == -1)
				ft_error_handler(0);
		bit++;
		if (bit == 8)
		{
			str_bit++;
			bit = 0;
		}
	}
	if (!(*str_bit))
		ft_send_terminator(pid);
}

void	ft_reception(int sig, siginfo_t *info, void *context)
{
	(void)context;
	if (sig == SIGUSR1)
		ft_send_signal(info->si_pid, NULL);
	else if (sig == SIGUSR2)
	{
		write(1, "Message received\n", 17);
		exit(EXIT_SUCCESS);
	}
}

int	main(int ac, char **av)
{
	struct sigaction	action;

	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = ft_reception;
	if (sigaction(SIGUSR1, &action, NULL) == -1
		|| sigaction(SIGUSR2, &action, NULL) == -1)
		ft_error_handler(1);
	if (ac != 3)
	{
		write(1, "Use the format: ./client <PID> <String>\n", 44);
		exit(EXIT_FAILURE);
	}
	ft_send_signal(ft_atoi(av[1]), av[2]);
	while (1)
		pause();
	return (0);
}
