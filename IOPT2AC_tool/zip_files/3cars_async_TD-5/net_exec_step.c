/* Net N_3carros_TD - IOPT */
/* Automatic code generated by IOPT2C XSLT transformation. */


#include <stdlib.h>
#include <string.h>
#include "net_types.h"


static N_3carros_TD_TransitionFiring tfired;
    

void N_3carros_TD_ExecutionStep(
     N_3carros_TD_NetMarking *prev_marking,
     N_3carros_TD_InputSignals *inputs,
     N_3carros_TD_InputSignals *prev_in,
     N_3carros_TD_PlaceOutputSignals *place_out,
     N_3carros_TD_EventOutputSignals *ev_out )
{
    N_3carros_TD_NetMarking add_marking;
    N_3carros_TD_NetMarking avail_marking = *prev_marking;
    N_3carros_TD_InputSignalEvents input_events;
    N_3carros_TD_OutputSignalEvents output_events;

    memset( &output_events, 0, sizeof(output_events) );
    memset( &tfired, 0, sizeof(tfired) );

    createEmpty_N_3carros_TD_NetMarking( &add_marking );
    N_3carros_TD_GetInputSignals( inputs, &input_events );
    N_3carros_TD_GenerateInputSignalEvents( prev_in, inputs, &input_events );
    *prev_in = *inputs;

    /* Transition BACK_copy5 */
    if( t_93_enabled( prev_marking, &avail_marking ) &&
        t_93_events( &input_events ) &&
        t_93_guards( prev_marking, inputs, place_out, ev_out ) ) {
        tfired.t_93 = 1;
        t_93_remove_marks( &avail_marking );
        t_93_add_marks( &add_marking );
        t_93_generate_output_events( &output_events );
    }

    /* Transition B5 */
    if( t_94_enabled( prev_marking, &avail_marking ) &&
        t_94_events( &input_events ) &&
        t_94_guards( prev_marking, inputs, place_out, ev_out ) ) {
        tfired.t_94 = 1;
        t_94_remove_marks( &avail_marking );
        t_94_add_marks( &add_marking );
        t_94_generate_output_events( &output_events );
    }

    /* Transition GO_copy5 */
    if( t_95_enabled( prev_marking, &avail_marking ) &&
        t_95_events( &input_events ) &&
        t_95_guards( prev_marking, inputs, place_out, ev_out ) ) {
        tfired.t_95 = 1;
        t_95_remove_marks( &avail_marking );
        t_95_add_marks( &add_marking );
        t_95_generate_output_events( &output_events );
    }

    /* Transition A5 */
    if( t_97_enabled( prev_marking, &avail_marking ) &&
        t_97_events( &input_events ) &&
        t_97_guards( prev_marking, inputs, place_out, ev_out ) ) {
        tfired.t_97 = 1;
        t_97_remove_marks( &avail_marking );
        t_97_add_marks( &add_marking );
        t_97_generate_output_events( &output_events );
    }

    add_N_3carros_TD_NetMarkings( &avail_marking, &add_marking );

    N_3carros_TD_GenerateTransitionActionOutputSignals( &tfired, &avail_marking, ev_out );
    N_3carros_TD_GeneratePlaceOutputSignals( &avail_marking, inputs, place_out, ev_out );
    N_3carros_TD_GenerateEventOutputSignals( &output_events, ev_out );
    N_3carros_TD_PutOutputSignals( place_out, ev_out, &output_events );
    *prev_marking = avail_marking;
}

N_3carros_TD_TransitionFiring* get_N_3carros_TD_TransitionFiring()
{
    return &tfired;
}
