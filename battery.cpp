#include "battery.h"
#include "components.h"

Battery::Battery(std::string const comp_name, Node* const anode, Node* const bnode, double const battery_voltage)
    : Components(comp_name, anode, bnode), voltage{ battery_voltage }
{
   
}

double Battery::get_current() 
{
    return 0; 
}

void Battery::simulation_step(double const time_step)
{
    a_node->q = 0;
    b_node->q = voltage;
}