#ifndef SIMULATION_H
#define SIMULATION_H

#include <vector>
#include <iomanip>
#include <iostream>
#include "components.h"
#include "battery.h"

void Simulate(std::vector<Components*> circuit, int number_of_iterations, int number_of_lines, double time_step); 
void print_parameters(std::vector<Components*> circuit);
void print_header(std::vector<Components*> circuit);

#endif