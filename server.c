/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:10:41 by juhtoo-h          #+#    #+#             */
/*   Updated: 2024/10/30 14:50:01 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

void	ft_signal_handler(int sig)
{
	static unsigned char	val;
	static int				bit;

	if (bit == 0)
		bit++;
	if (sig == SIGUSR1)
		val += 0;
	if (sig == SIGUSR2)
		val += bit;
	bit <<= 1;
	if (bit == 256)
	{
		bit = 1;
		write(1, &val, 1);
		val = 0;
	}
}

int	main(void)
{
	write(1, "PID = ", 6);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	signal(SIGUSR1, ft_signal_handler);
	signal(SIGUSR2, ft_signal_handler);
	while (1)
		pause();
	return (0);
}
