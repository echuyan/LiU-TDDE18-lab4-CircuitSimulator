#include "simulation.h"

void Simulate(std::vector<Components*> circuit, int number_of_iterations, int number_of_lines, double time_step)
{
    std::cout << std::fixed << std::setprecision(2); 
    std::cout << std::setfill(' ');
    print_header(circuit);
    print_parameters(circuit);
    for(int i{0}; i <= number_of_iterations; i++)
    {
       for(Components* elements: circuit)
      { 
         elements->simulation_step(time_step);
      } 
      if (i % (number_of_iterations / number_of_lines) == 0)
      {
         print_parameters(circuit);
      }
    }
    std::cout << std::endl; 
}
void print_header(std::vector<Components*> circuit)
{
   int count = -1;
   for(Components* elements: circuit) 
   {
      std::cout << std::setw(14) << elements->name;
      count++;
   }
   std::cout << std::endl;
   for(int i = 0; i <= count; i++) 
   {
      std::cout << std::setw(7);
      std::cout << "Volt";
      std::cout << std::setw(7);
      std::cout << "Curr";
   }
   std::cout << std::endl;
}

void print_parameters(std::vector<Components*> circuit)
{
   for(Components* elements: circuit)
   {
      std::cout << std::setw(7);
      std::cout<< elements->get_voltage();
      std::cout << std::setw(7);
      std::cout << elements->get_current();
   }
   std::cout << std::endl; 
}
