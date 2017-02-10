/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blakcjack_ct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nengle- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 14:43:25 by nengle-           #+#    #+#             */
/*   Updated: 2017/01/27 09:18:40 by nengle-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			black_jack_hand(char *hand)
{
	int		count;
	int		i;
	int		add;

	count = 0;
	i = 0;
	add = 0;
	while (hand[i])
	{
		if (hand[i] >= '2' && hand[i] <= '9')
			count = count + (hand[i] - '0');
		else if (count == 'J' || count == 'Q' || count == 'K' || count == 'T')
			count = count + 10;
		else if (hand[i] == 'A')
		{
			add++;
			count++;
		}
		i++;
	}
	if (add > 0 && count + 10 <= 21)
		count = count + 10;
	return (count);
}
