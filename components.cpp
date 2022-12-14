#include "components.h"
#include <string>


Components :: Components(std::string const comp_name, Node* const anode, Node* const bnode)
: name{comp_name}, a_node{anode}, b_node{bnode} 
{
}

double Components::get_voltage() const{
 
    return abs(a_node->q - b_node->q);
}



