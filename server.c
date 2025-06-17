/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 19:16:03 by frocha-b          #+#    #+#             */
/*   Updated: 2025/06/17 16:57:41 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


char	*ft_strjoin_char(char *str, char c)
{
	char *temp;

	temp = NULL;
	temp[0] = c;
	temp[1] = '\0';
	str = ft_strjoin(str, temp);
	free(temp);
	if (!str)
		return (NULL);
	return(str);
}	
char	*bits_to_char(char c)
{
	char *str;
	char *temp;

	while (c != '\0')
	{
		temp = str;
		str = ft_strjoin_char(str, c);
		free(temp);
		if (!str)
			return (NULL);
	}
	return (str);
}
void	handler(int signal)
{	
	static int 	i = 0;
	static int 	c = 0;
	int 	bit = 0;
	
	while (i < 8)
	{
		if (signal == SIGUSR1)
			bit = 1;
		c |= (bit << 1);
        i++;
	}
	if (i == 8)
	{
		i = 0;
		bits_to_char((char) c);
	}
}
int main(void)
{
	int pid = getpid();
	ft_printf("PID: %d\n", pid);
	while (1)
	{
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
		pause();
	}
	return (0);
}