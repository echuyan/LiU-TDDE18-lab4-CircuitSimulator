#ifndef COMPONENTS_H
#define COMPONENTS_H
#include "node.h"
#include <string>

// Comment: getter should usually always be const because you never modify
// anything inside the class.

class Components 
{

    public:  
        Components(std::string const comp_name, Node* const anode, Node* const bnode);
        virtual ~Components()=default;
        virtual double get_current() = 0;
        double get_voltage() const; 
        virtual void simulation_step(double const time_step) = 0;
        std::string name;

    protected:
        Node *a_node;
        Node *b_node;           
};

#endif