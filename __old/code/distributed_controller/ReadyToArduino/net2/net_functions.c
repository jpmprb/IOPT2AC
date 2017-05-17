/* Net simples_without_net - IOPT */
/* Automatic code generated by IOPT2C XSLT transformation. */


#include <string.h>
#include "net_types.h"


#define ABS(x) (((x)>=0)?(x):-(x))


/* Array implementation: */


void createInitial_simples_without_net_NetMarking( simples_without_net_NetMarking* init_marking )
{
    memset( init_marking, 0, sizeof(*init_marking) );
    init_marking->p_3 = 0; /* Place Place2 */
}

void createEmpty_simples_without_net_NetMarking( simples_without_net_NetMarking* empty_marking )
{
    empty_marking->p_3 = 0; /* Place Place2 */
}

void add_simples_without_net_NetMarkings(
    simples_without_net_NetMarking* dest_marking,
    simples_without_net_NetMarking* source_marking )
{
    dest_marking->p_3 += source_marking->p_3; /* Place Place2 */
}

void init_simples_without_net_OutputSignals(
    simples_without_net_PlaceOutputSignals* place_out,
    simples_without_net_EventOutputSignals* ev_out )
{
    memset( place_out, 0, sizeof(*place_out) );
    memset( ev_out, 0, sizeof(*ev_out) );
    ev_out->led1 = 0;
    place_out->led2 = 0;
}

/* Transition 8 - tr_8 */
int t_8_enabled( simples_without_net_NetMarking* prev,
                    simples_without_net_NetMarking* avail )
{
    return ( avail->p_3 >= 1 );
}

int t_8_events( simples_without_net_InputSignalEvents* events )
{
    return ( events->net2E );
}

int t_8_guards( simples_without_net_NetMarking* marking,
                   simples_without_net_InputSignals* inputs,
                   simples_without_net_PlaceOutputSignals* place_out,
                   simples_without_net_EventOutputSignals* ev_out )
{
    return (  1  );
}

void t_8_remove_marks( simples_without_net_NetMarking* marking )
{
    marking->p_3--;
}

void t_8_add_marks( simples_without_net_NetMarking* marking )
{
}

void t_8_generate_output_events( simples_without_net_OutputSignalEvents* ev_out )
{
    ev_out->event20 = 1;
}


/* Transition 10 - tr_10 */
int t_10_enabled( simples_without_net_NetMarking* prev,
                    simples_without_net_NetMarking* avail )
{
    return ( 1 );
}

int t_10_events( simples_without_net_InputSignalEvents* events )
{
    return ( events->event19 );
}

int t_10_guards( simples_without_net_NetMarking* marking,
                   simples_without_net_InputSignals* inputs,
                   simples_without_net_PlaceOutputSignals* place_out,
                   simples_without_net_EventOutputSignals* ev_out )
{
    return (  1  );
}

void t_10_remove_marks( simples_without_net_NetMarking* marking )
{
}

void t_10_add_marks( simples_without_net_NetMarking* marking )
{
    marking->p_3++;
}

void t_10_generate_output_events( simples_without_net_OutputSignalEvents* ev_out )
{
}


/* Input event processing: */
void simples_without_net_GenerateInputSignalEvents(
        simples_without_net_InputSignals *old_values,
        simples_without_net_InputSignals *new_values,
        simples_without_net_InputSignalEvents *events )
{
    events->net1E = ( old_values->net1<=0 && new_values->net1>0 );
    events->net2E = ( old_values->net2<=0 && new_values->net2>0 );
}

/* Output event processing: */
void simples_without_net_GenerateEventOutputSignals(
    simples_without_net_OutputSignalEvents *events,
    simples_without_net_EventOutputSignals *signals )
{
}

/* Transition action processing: */
void simples_without_net_GenerateTransitionActionOutputSignals(
    simples_without_net_TransitionFiring *tfired,
    simples_without_net_NetMarking *marking,
    simples_without_net_EventOutputSignals *ev_out )
{
}

/* Place Output Processing */
void simples_without_net_GeneratePlaceOutputSignals(
    simples_without_net_NetMarking *marking,
    simples_without_net_InputSignals *inputs,
    simples_without_net_PlaceOutputSignals *place_out,
    simples_without_net_EventOutputSignals *ev_out )
{
    int exp_res, new_val, n_writes;
    simples_without_net_PlaceOutputSignals new_out = *place_out;
    
    /* Signal led2 */
    new_val = 0;
    if( marking->p_3 > 0 ) { /* Place Place2 */
        exp_res = 1;
        if( (marking->p_3 == 1) )
            new_val = exp_res;
    }
    if( new_val > 1 ) new_out.led2 = 1;
    else if( new_val < 0 ) new_out.led2 = 0;
    else new_out.led2 = new_val;

    *place_out = new_out;
}
