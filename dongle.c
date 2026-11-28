#include "codexion.h"

long priority_calculate(t_sim *sim, t_coder *coder)
{
    if (sim->is_edf == 1)
    {
        coder->last_compile + sim->burnout_time;
    	pthread_mutex_lock(&sim->sim_mutex);
    }
    else if (sim->is_edf == 0)
    {
        return (get_time_ms());
    }
    return (-1);
}