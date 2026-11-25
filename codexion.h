#ifndef CODEXION_H
# define CODEXION_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

int	ft_atoi(const char *str);

typedef struct s_sim	t_sim;

typedef struct s_node
{
	int		coder_id;
	long	priority;
}	t_node;

typedef struct s_dongle
{
	int				is_taken;
	long			available_at;
	pthread_mutex_t	mutex;
	pthread_cond_t	cond;
	t_node			*heap;
	int				heap_size;
}	t_dongle;

typedef struct s_coder
{
	int			id;
	pthread_t	thread;
	int			compile_count;
	long		last_compile;
	t_dongle	*left;
	t_dongle	*right;
	t_sim		*sim;
}	t_coder;

struct s_sim
{
	int				num_coders;
	long			burnout_time;
	long			compile_time;
	long			debug_time;
	long			refactor_time;
	int				must_compile;
	long			cooldown;
	int				is_edf;
	long			start_time;
	int				is_over;
	pthread_mutex_t	sim_mutex;
	pthread_mutex_t	print_mutex;
	t_dongle		*dongles;
	t_coder			*coders;
};

#endif