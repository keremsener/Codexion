#include "codexion.h"

long priority_calculate(t_sim *sim, t_coder *coder)
{
    long    value;

    if (sim->is_edf == 1)
    {
    	pthread_mutex_lock(&sim->sim_mutex);
        value = coder->last_compile + sim->burnout_time;
        pthread_mutex_unlock(&sim->sim_mutex);
        return (value);
    }
    return (get_time_ms());
}