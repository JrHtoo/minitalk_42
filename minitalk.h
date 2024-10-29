/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:05:57 by juhtoo-h          #+#    #+#             */
/*   Updated: 2024/10/29 14:54:00 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <asm-generic/signal-defs.h>
# include <asm-generic/signal-defs.h>

void	ft_putchar(char c);
void	ft_putnbr(int n);
int		ft_atoi(const char *nptr);
void	ft_error_handler(int i);

#endif