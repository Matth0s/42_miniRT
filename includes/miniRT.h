/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:55:00 by mmoreira          #+#    #+#             */
/*   Updated: 2022/02/17 19:25:04 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# define _USE_MATH_DEFINES
# define EPSILON 0.00001

# define SPHERE 1
# define PLANE 2
# define SQUARE 3
# define CYLINDER 4
# define TRIANGLE 5

# define C_ESPECULAR 100

# define LEFT_ARROW 65361
# define UP_ARROW 65362
# define RIGHT_ARROW 65363
# define DOWN_ARROW 65364
# define ESC_BUTTON 65307

# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <stdint.h>
# include "structs.h"

//___________________________Operações_Com_Vetores
t_vet	vet_create(double x, double y, double z);
t_vet	vet_sum(t_vet v1, t_vet v2);
t_vet	vet_sub(t_vet v1, t_vet v2);
t_vet	vet_mult(t_vet v1, double n);
t_vet	vet_div(t_vet v1, double n);

void	vet_norm(t_vet *vet);
double	vet_dot(t_vet v1, t_vet v2);
t_vet	vet_cross(t_vet v1, t_vet v2);
t_vet	mat_dot_vet(t_mat mat, t_vet vet);

t_vet	vet_color_mult(t_vet v1, t_vet v2);
void	vet_color_norm(t_vet *vet, int i);
double	mat_det(t_mat mat);
t_mat	mat_invert(t_mat mat);

//___________________________Criador_Do_Mundo
int		check_info(char **info, int n);
int		num_comma(char *info);
int		make_double(char *str, double *n);
int		make_vet(char *info, t_vet *vet);

int		set_cylinder(char **info, t_mundo *mundo);
int		set_triangle(char **info, t_mundo *mundo);
int		set_square(char **info, t_mundo *mundo);
int		set_sphere(char **info, t_mundo *mundo);
int		set_plane(char **info, t_mundo *mundo);
int		set_cams(char **info, t_mundo *mundo);
int		set_rotation(char **info, t_mundo *mundo);
int		set_lamps(char **info, t_mundo *mundo);
int		set_abnt(char **info, t_mundo *mundo);
int		set_screen(char **info, t_mundo *mundo);

int		make_mundo(char *file, t_mundo *mundo);

//___________________________Checador_Do_Mundo
int		check_obj_cy(t_cy *cylinder, int i);
int		check_obj_tr(t_tr *triangle, int i);
int		check_obj_sq(t_sq *square, int i);
int		check_obj_sp(t_sp *sphere, int i);
int		check_obj_pl(t_pl *plane, int i);
int		check_objs_i(t_mundo *mundo);
int		check_cams(t_mundo *mundo);
int		check_lamps(t_mundo *mundo);
int		check_screan_abnt(t_mundo *mundo);

int		check_color(t_vet vet);
int		error_print_ii(int indicator, int i);
int		error_print_i(int indicator, int i);
int		check_mundo(t_mundo *mundo);

//___________________________Calculadores_De_interseptação
void	cy_intersection( t_cy *cy, t_ray *ray);
void	tr_intersection( t_tr *tr, t_ray *ray);
void	sq_intersection(t_sq *sq, t_ray *ray);
void	sp_intersection( t_sp *sp, t_ray *ray);
void	pl_intersection(t_pl *pl, t_ray *ray);
void	set_intersection(t_list *objs, t_ray *ray);

//___________________________Criador_Da_Imagem
t_img	*make_image(t_mundo *mundo, t_cam *cam, void *mlx);

//___________________________Traçador_De_Raios
t_vet	color_ambiente(t_abnt abnt);
t_vet	color_difuse(t_ray *ray, t_ray light);
t_vet	color_especular(t_ray *ray, t_ray light);
t_vet	raytracer(t_mundo *mundo, t_view view, int x, int y);

//___________________________Iniciador_Da_Renderização
void	init_render(int argc, t_mundo *mundo);

//___________________________Controle_Da_Janela
int		windows_control(t_hook *loop, t_mundo *mundo);

//___________________________Controle_Do_Bitmap
void	bitmap_control(t_hook *loop, t_mundo *mundo);

//___________________________Uteis_Geral
void	free_mundo(t_mundo *mundo);

#endif