/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 12:57:41 by tvallee           #+#    #+#             */
/*   Updated: 2018/02/13 13:01:26 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/swap.h"

unsigned long		swap_long(unsigned long n)
{
	return (
			((n & 0xFF000000) >> 24) |
			((n & 0x00FF0000) >> 8) |
			((n & 0x0000FF00) << 8) |
			((n & 0x000000FF) << 24));
}
