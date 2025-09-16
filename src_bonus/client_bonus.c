/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 19:16:09 by frocha-b          #+#    #+#             */
/*   Updated: 2025/09/16 11:00:20 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static volatile sig_atomic_t	g_ack_received = 0;

static void	ft_ack_handler(int sig)
{
	(void) sig;
	g_ack_received = 1;
}

static void	bit_sender(pid_t pid, int bit)
{
	int	time_limit;

	g_ack_received = 0;
	if (bit == 0)
	{
		if (kill(pid, SIGUSR1) == -1)
			exit_error("Error:\nSignal was not sent\n");
	}
	else
	{
		if (kill(pid, SIGUSR2) == -1)
			exit_error("Error:\nSignal was not sent\n");
	}
	time_limit = 0;
	while (g_ack_received == 0)
	{
		if (time_limit > 10000)
			exit_error("\nError: \nNo response from server (timeout).\n\n");
		usleep(100);
		time_limit++;
	}
}

static void	message_sender(pid_t pid, char *message)
{
	int		i;
	int		bit_pos;
	char	current_char;

	i = 0;
	while (1)
	{
		current_char = message[i];
		bit_pos = 8;
		while (bit_pos--)
			bit_sender(pid, (current_char >> bit_pos) & 1);
		if (current_char == '\0')
			break ;
		i++;
	}
}

void	error_handler(int ac, char **argv)
{
	if (ac != 3)
		exit_error("Insert <PID> and <message>\n");
	if (ft_atoi(argv[1]) <= 0 || ft_atoi(argv[1]) > MAX_PID)
		exit_error("Insert a valid PID\n");
}

int	main(int ac, char **argv)
{
	pid_t				pid;
	struct sigaction	s_sa;

	error_handler(ac, argv);
	pid = ft_atoi(argv[1]);
	s_sa.sa_handler = ft_ack_handler;
	sigemptyset(&s_sa.sa_mask);
	s_sa.sa_flags = 0;
	if (sigaction(SIGUSR1, &s_sa, NULL) == -1)
		exit_error("\nError: \nFailed to set signal handler.\n\n");
	message_sender(pid, argv[2]);
	ft_printf("\nMessage has been delivered.\n\n");
}
