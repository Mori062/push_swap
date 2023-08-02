/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmorish <shmorish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 03:17:45 by shmorish          #+#    #+#             */
/*   Updated: 2023/08/03 03:43:08 by shmorish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int    sort(int *args, int num)
{
    if (num = 1)
        return (0);
    else if (num == 2)
        return (sort2(args));
    else if (num == 3)
        return (sort3(args));
    else if (num == 4)
        return (sort4(args));
    else if (num == 5)
        return (sort5(args));
    else
        return (sort_many(args));
}
// 座標圧縮
int compress_num(int *args)
{

}
