/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 19:16:09 by frocha-b          #+#    #+#             */
/*   Updated: 2025/07/01 11:58:03 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bit(pid_t pid, int bit)
{
	if (bit == 0)
	{
		if (kill(pid, SIGUSR1) == -1)
		
			return ((void)ft_printf("Invalid kill\n"));
	}
	else
	{
		if (kill(pid, SIGUSR2) == -1)
			return ((void)ft_printf("Invalid kill\n"));
	}
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
	pid_t pid;
	char *message;
	int	i = 0;
	int message_len;

	if (ac == 3)
	{
		message = argv[2];
		pid = (pid_t)ft_atoi(argv[1]);
		message_len = ft_strlen(message);
		if (!message_len)
			return(ft_printf("Please insert a message"));		
		if (pid < 0)
			return(ft_printf("Please insert an valid PID"));
		while (i <= message_len)
		{
			char_to_bit(pid,(int) message[i]);
			i++;
		}
		return (0);
	}
	else
		return(ft_printf("Please insert both PID and the Message"));
}