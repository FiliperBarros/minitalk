/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 19:16:03 by frocha-b          #+#    #+#             */
/*   Updated: 2025/06/23 17:57:15 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// char	*ft_strjoin_char(char *str, char c)
// {
// 	char *temp;

// 	temp = NULL;
// 	temp[0] = c;
// 	temp[1] = '\0';
// 	str = ft_strjoin(str, temp);
// 	free(temp);
// 	if (!str)
// 		return (NULL);
// 	return(str);
// }

char	*create_char_str(char c)
{
	char *str;
	
	str = malloc(2);
	if (!str)
		return (NULL);
	str[0] = c;
	str[1] = '\0';
	return (str);
}
void	print_message(char c)
{
	char *new_str;
	char *char_str;
	char *temp;
	
	new_str = NULL;
	char_str = create_char_str(c);
	if (!new_str)
		new_str = ft_strdup("");
	if (c == '\0')
	{
		ft_printf("%s", new_str);
		return ;
	}
	temp = new_str;
	new_str = ft_strjoin(new_str, char_str);
	free(temp);	
	if (!new_str)
		return ;
}
void	handler(int signal)
{	
	static int 	i = 0;
	static int 	c = 0;
	int 	bit = 0;
	
	if (signal == SIGUSR2)
		bit = 1;
	c = (c << 1) | bit;    
    i++;
	if (i == 8)
	{
		print_message(c);
		// ft_printf("%d\n", c);
		i = 0;
		c = 0;
	}
	usleep (250);
}
int main(void)
{
	int pid = getpid();
	ft_printf("PID: %d\n", pid);
	while (1)
	{
		signal(SIGUSR2, handler);
		signal(SIGUSR1, handler);
		pause();
	}
	return (0);
}