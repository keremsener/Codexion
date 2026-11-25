static int is_higher(t_node a, t_node b)
{
    if (a.priority < b.priority)
        return 1;
    if (a.priority == b.priority)
    {
        if(a.coder_id < b.coder_id)
            return (1);
    }
    return 0;
}
static void	swap_nodes(t_node *a, t_node *b)
{
	t_node	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
void heap_push(t_dongle *dongle, int coder_id, long priority)
{
    int i;
    int parent;


    dongle->heap[dongle->heap_size].coder_id = coder_id;
    dongle->heap[dongle->heap_size].priority = priority;
    dongle->heap_size++;
    i = dongle->heap_size - 1;
    while(i > 0)
    {
        parent = (i - 1) / 2;
        if(is_higher(dongle->heap[i], dongle->heap[parent]))
        {
            swap_nodes(&dongle->heap[i], &dongle->heap[parent]);
            i = parent;
        }
        else
            break;
    }
}