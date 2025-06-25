/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 19:16:09 by frocha-b          #+#    #+#             */
/*   Updated: 2025/06/18 15:48:01 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bit(pid_t pid, int bit)
{
	if (bit == 0)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
}	
void char_to_bit(pid_t pid, int c)
{
	
	int bit;
	int i = 7;
	while (i >= 0)
	{
		bit = (c >> i) & 1;
		send_bit(pid, bit);
		i--;
		usleep(250);
	}
}
int main(int ac, char ** argv)
{
	int	i = 0;
	int message_len;

	// e se a mensagem for nula
	if (ac == 3 && argv[2][0])
	{
		char *message = argv[2];
		message_len = ft_strlen(message);
		// e se o Pid nao for o correto 
		pid_t pid = (pid_t)ft_atoi(argv[1]);
		while (i <message_len)
		{
			char_to_bit(pid,(int) message[i]);
			ft_printf("\n");
			i++;
		}
	}
	else
	{
		ft_printf("Please insert the PID and the Message");
	}
}