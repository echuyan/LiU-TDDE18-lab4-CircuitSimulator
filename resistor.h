#ifndef RESISTOR_H
#define RESISTOR_H

#include "components.h"

class Resistor : public Components 
{
    public:  
        Resistor(std::string const comp_name, Node* const anode, Node* const bnode, double resistance_);
        ~Resistor() = default;
        double get_current() override; 
        void simulation_step(double const time_step) override;

    private:
        double const resistance;
};

#endif
