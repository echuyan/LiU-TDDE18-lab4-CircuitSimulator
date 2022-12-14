#include "capacitor.h"
#include "components.h"

Capacitor::Capacitor(std::string const comp_name, Node* const anode, Node* const bnode, double const capacitance)
: Components(comp_name, anode, bnode), C{capacitance},stored_charge{0}
{
}

double Capacitor::get_current() 
{
    return (C)*(abs(a_node->q - b_node->q) - stored_charge);
}

void Capacitor::simulation_step(double const time_step)
{
    double charge_moving = ( C *(abs(a_node->q - b_node->q) - stored_charge)* (time_step) );
    if (a_node->q < b_node->q)
    {
        a_node->q += charge_moving;
        b_node->q -= charge_moving;
    }
    else 
    {
        a_node->q -= charge_moving;
        b_node->q += charge_moving;
    }
    stored_charge += charge_moving;
}