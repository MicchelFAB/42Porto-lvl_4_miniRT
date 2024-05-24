/**
 * @file threads_fun.c
 * @author Michel Batista (michel_fab@outlook.com)
 * @brief File containing the functions to handle the threads.
 * @version 0.1
 * @date 2024-05-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "minirt_bonus.h"
/**
 * @brief Function to handle the threads.
 * 
 * @param arg 
 * @return void* 
 */
void	*ft_routine(void *arg)
{
	t_context	*scene;

	scene = (t_context *)arg;
	ft_render_bonus_thread(scene);
	return (NULL);
}
/**
 * @brief Function to create a new context.
 * 
 * @param id 
 * @param image 
 * @param initial_height 
 * @param final_height 
 * @return t_context 
 */
t_context	ft_create_context(int id, t_world *image,
		int initial_height, int final_height)
{
	t_context	context;

	context.num_threads = id;
	context.image = image;
	context.initial_height = initial_height;
	context.final_height = final_height;
	return (context);
}
/**
 * @brief Function to loop the context.
 * 
 * @param scene 
 * @return t_context* 
 */
t_context	*ft_loop_context(t_world *scene)
{
	int			i;
	t_context	*context;

	i = -1;
	context = (t_context *)malloc(sizeof(t_context) * THREADS);
	while (++i < THREADS)
		context[i] = ft_create_context(i, scene, i * (WIDTH_B / RATIO)
				/ THREADS, (i + 1) * (WIDTH_B / RATIO) / THREADS);
	return (context);
}
/**
 * @brief Function to start the threads.
 * 
 * @param scene 
 */
void	ft_start_thread(t_world *scene)
{
	int			i;
	pthread_t	*thread;
	t_context	*context;
	int			done;

	done = 1;
	thread = (pthread_t *)malloc(sizeof(pthread_t) * THREADS);
	while (done)
	{
		context = ft_loop_context(scene);
		i = -1;
		while (++i < THREADS)
			pthread_create(&thread[i], NULL, ft_routine, &context[i]);
		i = -1;
		while (++i < THREADS)
		{
			pthread_join(thread[i], NULL);
			done = 0;
		}
	}
	scene = context->image;
	free(thread);
	free(context);
}
