/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 19:16:03 by frocha-b          #+#    #+#             */
/*   Updated: 2025/09/16 10:55:32 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	signal_handler(int signal, siginfo_t *info, void *context)
{
	int			bit;
	static int	i;
	static int	chr;

	(void) context;
	bit = 0;
	if (signal == SIGUSR2)
		bit = 1;
	chr = (chr << 1) | bit;
	i++;
	if (i == 8)
	{
		if (chr == '\0')
			ft_printf("\n");
		else
			ft_printf("%c", chr);
		i = 0;
		chr = 0;
	}
	if (kill(info->si_pid, SIGUSR1) == -1)
	{
		i = 0;
		chr = 0;
	}
}

int	main(void)
{
	int					server_pid;
	struct sigaction	s_sa;

	server_pid = getpid();
	ft_printf("Server PID: %d\n", server_pid);
	s_sa.sa_sigaction = signal_handler;
	sigemptyset(&s_sa.sa_mask);
	s_sa.sa_flags = SA_SIGINFO | SA_RESTART;
	if (sigaction(SIGUSR1, &s_sa, NULL) == -1)
		exit_error("Error setting SIGUSR1 handler\n");
	if (sigaction(SIGUSR2, &s_sa, NULL) == -1)
		exit_error("Error setting SIGUSR2 handler\n");
	while (1)
		pause();
	return (0);
}
