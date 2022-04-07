/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbombur <hbombur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:01:39 by hbombur           #+#    #+#             */
/*   Updated: 2022/04/07 15:28:35 by hbombur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./minilibft/ft_printf/libftprintf.a"

typedef struct s_struct
{
	int	width;
	int	height;
	int	**z_matrix;

	void	*mlx_ptr;
	void	*win_ptr
}	fdf

#endif
