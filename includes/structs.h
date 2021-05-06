/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 01:38:01 by mmoreira          #+#    #+#             */
/*   Updated: 2021/04/26 18:25:37 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "./../libft/libft.h"

//_____Structs_Dos_Operadores
typedef struct s_vet
{
	double	x;
	double	y;
	double	z;

}			t_vet;
typedef struct s_mat
{
	t_vet	c1;
	t_vet	c2;
	t_vet	c3;

}			t_mat;

//_____Structs_Dos_Elementos
typedef struct s_abnt
{
	double	forc;
	t_vet	color;
}			t_abnt;
typedef struct s_lamp
{
	t_vet	orig;
	double	forc;
	t_vet	color;
}			t_lamp;
typedef struct s_cam
{
	t_vet	orig;
	t_vet	drct;
	double	ang;
}			t_cam;

typedef struct s_pl
{
	int		type;
	t_vet	orig;
	t_vet	norm;
	t_vet	color;
}			t_pl;
typedef struct s_sp
{
	int		type;
	t_vet	orig;
	double	diam;
	t_vet	color;
}			t_sp;
typedef struct s_sq
{
	int		type;
	t_vet	orig;
	t_vet	norm;
	double	side;
	t_vet	color;
}			t_sq;
typedef struct s_cy
{
	int		type;
	t_vet	orig;
	t_vet	norm;
	double	diam;
	double	heig;
	t_vet	color;
}			t_cy;
typedef struct s_tr
{
	int		type;
	t_vet	p1;
	t_vet	p2;
	t_vet	p3;
	t_vet	norm;
	t_vet	color;
}			t_tr;

//_____Structs_Das_Imagens_Do_RayTracer
typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		bits_pixel;
	int		line_len;
	int		endian;
}				t_img;
typedef struct s_view
{
	t_mat	mat;
	t_cam	cam;
	t_vet	init;
}			t_view;
typedef struct s_ray
{
	double	t;
	t_vet	orig;
	t_vet	drct;
	t_vet	hit;
	t_vet	norm;
	double	forc;
	t_vet	color;
}			t_ray;

//_____Struct_De_Controle_Da_Janela_De_Exibição
typedef struct s_hook
{
	void	*mlx;
	void	*wind;
	t_list	*imgs;
}			t_hook;

//_____Struct_Para_Salvar_O_Bitmap
typedef struct s_bitmap
{
	uint16_t	type;
	uint32_t	size;
	uint16_t	reserved1;
	uint16_t	reserved2;
	uint32_t	offset;
	uint32_t	dib_header_size;
	int32_t		width_px;
	int32_t		height_px;
	uint16_t	num_planes;
	uint16_t	bits_per_pixel;
	uint32_t	compression;
	uint32_t	image_size_bytes;
	int32_t		x_resolution_ppm;
	int32_t		y_resolution_ppm;
	uint32_t	num_colors;
	uint32_t	important_colors;
}				t_bitmap;

//_____Struct_Principal_Do_Programa
typedef struct s_mundo
{
	int		R[3];
	int		a;
	t_abnt	A;
	int		c;
	t_list	*cams;
	int		l;
	t_list	*lamps;
	int		o;
	t_list	*objs;
}			t_mundo;

#endif