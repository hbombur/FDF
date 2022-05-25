/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbombur <hbombur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:01:39 by hbombur           #+#    #+#             */
/*   Updated: 2022/05/25 20:59:57 by hbombur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./minilibft/ft_printf/ft_printf.h"
# include "./lib_ft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_struct
{
	int		width;
	int		height;
	int		**z_matrix;

	void	*mlx_ptr;
	void	*win_ptr;
}			fdf;

fdf	*get_params(char *file_name);
int	read_file(char *file_name);

#endif
