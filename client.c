/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 19:16:09 by frocha-b          #+#    #+#             */
/*   Updated: 2025/06/09 19:47:06 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bit(pid_t pid, int bit)
{
	if (bit == 0)
	{
		kill(pid, SIGUSR1);
		ft_printf("sigusr1\n\n");
	}
	else
	{
		kill(pid, SIGUSR2);
		ft_printf("sigurs2\n");
	}	
}
void char_to_bit(pid_t pid, char c)
{
	
	int bit;
	int i = 7;
	while (i >= 0)
	{
		bit = (c >> i) & 1;
		ft_printf("bit: %d\n", bit);
		send_bit(pid, bit);
		i--;
		usleep(250);
	}
}
int main(int ac, char ** argv)
{
	int	i = 0;
	if (ac == 3)
	{
		// e se o Pid nao for o correto 
		pid_t pid = (pid_t)ft_atoi(argv[1]);
		// e se a mensagem for nula
		char *message = argv[2];
		while (message[i])
		{
			char_to_bit(pid, message[i]);
			i++;
		}
	}
	else
	{
		ft_printf("Please insert the PID and the Message");
	}
}