#include "push_swap.h"

void push_to(t_stack **dest, t_stack **src) {
    if (!src || !(*src)->head) return; 

    t_node *node = (*src)->head; 

    
    if (node->next == node) { 
        (*src)->head = NULL;
    } else {
        (*src)->head = node->next;
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }

    
    node->next = node->prev = NULL; 

    
    if (!(*dest) || !(*dest)->head) { 
        (*dest)->head = node;
        node->next = node->prev = node; 
    } else {
        
        node->next = (*dest)->head;
        node->prev = (*dest)->head->prev;
        (*dest)->head->prev->next = node; 
        (*dest)->head->prev = node; 
        (*dest)->head = node;
    }
}


void pa(t_stack **a, t_stack **b) {
    push_to(a, b); 
    write(1, "pa\n", 3);
}

void pb(t_stack **a, t_stack **b) {
    push_to(b, a); 
    write(1, "pb\n", 3);
}