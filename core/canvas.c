/**
 * @file canvas.c
 * @author Michel Batista (michel_fab@outlook.com)
 * @brief File containing functions to create, write and free a canvas.
 * @version 0.1
 * @date 2024-05-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "core.h"
/**
 * @brief Initialize a canvas with the given width and height.
 * 
 * @param width The width of the canvas.
 * @param height The height of the canvas.
 * @return t_canvas The created canvas.
 */
t_canvas	ft_create_aperture(int width, int height)
{
	int			i;
	int			j;
	t_canvas	c;

	i = 0;
	c.width = width;
	c.height = height;
	c.pixels = (t_color **)malloc(sizeof(t_color *) * height);
	while (i < height)
	{
		j = 0;
		c.pixels[i] = (t_color *)malloc(sizeof(t_color) * width);
		while (j < width)
		{
			c.pixels[i][j] = ft_color(0, 0, 0);
			j++;
		}
		i++;
	}
	return (c);
}
/**
 * @brief Free the memory allocated for the canvas.
 * 
 * @param canvas The canvas to be freed.
 */
void	ft_free_canvas(t_canvas canvas)
{
	int	i;

	i = 0;
	if (canvas.width == 0 || canvas.height == 0)
		return ;
	while (i < canvas.height)
	{
		free(canvas.pixels[i]);
		i++;
	}
	free(canvas.pixels);
}
/**
 * @brief Write a color to a pixel in the canvas.
 * 
 * @param canvas The canvas to write the pixel.
 * @param x The x coordinate of the pixel.
 * @param y The y coordinate of the pixel.
 * @param color The color to be written.
 */
void	ft_write_pixel(t_canvas canvas, int x, int y, t_color color)
{
	if (x < 0 || x >= canvas.width || y < 0 || y >= canvas.height)
		return ;
	canvas.pixels[y][x] = color;
}
/**
 * @brief Get the color of a pixel in the canvas.
 * 
 * @param canvas The canvas to get the pixel color.
 * @param x The x coordinate of the pixel.
 * @param y The y coordinate of the pixel.
 * @return t_vec3 The color of the pixel.
 */
t_vec3	ft_pixel_at(t_canvas canvas, int x, int y)
{
	if (x < 0 || x >= canvas.width || y < 0 || y >= canvas.height)
		return (ft_color(0, 0, 0));
	return (canvas.pixels[y][x]);
}
/**
 * @brief Clamp a value between 0 and 255.
 * 
 * @param value The value to be clamped.
 * @return int The clamped value.
 */
int	ft_clamp(int value)
{
	if (value < 0)
		return (0);
	if (value > 255)
		return (255);
	return (value);
}
