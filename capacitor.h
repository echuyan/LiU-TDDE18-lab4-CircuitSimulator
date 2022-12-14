#ifndef CAPACITOR_H
#define CAPACITOR_H

#include "components.h"

class Capacitor : public Components 
{
    public:  
        Capacitor(std::string const comp_name, Node* const anode, Node* const bnode, double const capacitance);
        ~Capacitor() = default;
        double get_current() override; 
        void simulation_step(double const time_step) override;
    
    private: 
        double const C;
        double stored_charge;   
};
#endif