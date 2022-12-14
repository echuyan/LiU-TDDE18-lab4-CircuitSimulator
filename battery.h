#ifndef BATTERY_H
#define BATTERY_H

#include "components.h"

class Battery : public Components 
{
    public:  
        Battery(std::string const comp_name, Node* const anode, Node* const bnode, double const battery_voltage); 
        ~Battery() = default;
        double get_current() override; 
        void simulation_step(double const time_step) override;
    
    private:
        double const voltage;   
};

#endif
