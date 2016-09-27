/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 16:54:11 by mde-la-t          #+#    #+#             */
/*   Updated: 2016/09/20 17:54:08 by mde-la-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# define I 255
# define I1 0
# define I2 1
# define I3 2
# define R e->c_red
# define G e->c_gre
# define B e->c_blu
# define C1(I3, I) e->data_img[(e->s_l * e->y) + (4 * e->x) + I3] = I;
# define C2(I3) e->data_img[(e->s_l * e->y) + (4 * e->x) + I3] = (e->i * I / e->i_max)
# define C3(I3)	e->data_img[(e->s_l * e->y) + (4 * e->x) + I3] = (e->i / I * e->i_max)

# define WHITE	C1(I3, I) C1(I2, I) C1(I1, I)
# define BLACK	C1(I3, I1) C1(I2, I1) C1(I1, I1)
# define C1BR	C2(I3) + R; C1(I2, I1) C2(I1) * B
# define C1BR1	C2(I3) * R; C1(I2, I1) C2(I1) + B
# define C1BG	C1(I3, I1) C2(I2) * G + G; C2(I1) * B
# define C1RG	C2(I3) * R; C2(I2) * G * G; C2(I1) * B * B * B
# define CRAD	C2(I3) * R * R ; C2(I2) * G * G * G; C1(I1, I)
# define CRAD1	C2(I3) * R * R * R; C1(I2, I) C2(I1) * B
# define CRAD2	C3(I3) * R; C3(I2) * G * G; C3(I1) * B * B * B
# define CRAD3	C3(I3) * R * R; C2(I2) * G * G * G; C2(I1) * B
# define CDBR	C2(I3) * R * R * R; C3(I2) * G; C3(I1) * B * B

#endif
