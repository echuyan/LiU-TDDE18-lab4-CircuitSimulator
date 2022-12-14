#include "resistor.h"
#include "components.h"


Resistor::Resistor(std::string const comp_name, Node* const anode, Node* const bnode, double const resistance_)
: Components(comp_name, anode, bnode), resistance{resistance_}
{
}

double Resistor :: get_current() 
{
     return (abs(a_node->q - b_node->q) / resistance);
}

void Resistor::simulation_step(double const time_step)
{   
    double charge_moving = ( (abs(a_node->q - b_node->q) / resistance) * time_step );
    
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
}