#include "simulation.h"
#include "battery.h"
#include "resistor.h"
#include "capacitor.h"


#include <iostream>
#include <string>
#include <vector>

using namespace std;

void circuit1(int const iterations, double const time_step, double const voltage, int const lines);
void circuit2(int const iterations, double const time_step, double const voltage, int const lines);
void circuit3(int const iterations, double const time_step, double const voltage, int const lines);
void deallocate_components(std::vector<Components*> v);

void circuit1(int const iterations, double const time_step, double const voltage, int const lines)
{
    Node p, n, r124, r23;
    std::vector<Components*> circuit;
    circuit.push_back(new Battery("Bat", &p, &n, voltage));  
    circuit.push_back(new Resistor("R1", &p, &r124, 6.0));
    circuit.push_back(new Resistor("R2", &r124, &r23, 4.0));
    circuit.push_back(new Resistor("R3", &r23, &n, 8.0));
    circuit.push_back(new Resistor("R4", &r124,&n, 12.0));
    Simulate(circuit, iterations, lines, time_step);
    deallocate_components(circuit);
}

void circuit2(int const iterations, double const time_step, double const voltage, int const lines)
{
    Node p, n, l, r;
    std::vector<Components*> circuit;
    circuit.push_back(new Battery("Bat", &p, &n, voltage));  
    circuit.push_back(new Resistor("R1", &p, &l, 150.0));
    circuit.push_back(new Resistor("R2", &p, &r, 50.0));
    circuit.push_back(new Resistor("R3", &l, &r, 100.0));
    circuit.push_back(new Resistor("R4", &l, &n, 300.0));
    circuit.push_back(new Resistor("R5", &r, &n, 250.0));
    Simulate(circuit, iterations, lines, time_step);
    deallocate_components(circuit);
}

void circuit3(int const iterations, double const time_step, double const voltage, int const lines)
{
    Node p, n, l, r;
    std::vector<Components*> circuit;
    circuit.push_back(new Battery("Bat", &p, &n, voltage));  
    circuit.push_back(new Resistor("R1", &p, &l, 150.0));
    circuit.push_back(new Resistor("R2", &p, &r, 50.0));
    circuit.push_back(new Capacitor("C3", &l, &r, 1.0));
    circuit.push_back(new Resistor("R4", &l, &n, 300.0));
    circuit.push_back(new Capacitor("C5", &r, &n, 0.75));
    Simulate(circuit, iterations, lines, time_step);
    deallocate_components(circuit);
}

void deallocate_components(std::vector<Components*> v)
{
  for(Components* elements : v)
  {
      delete elements;
  }
}

int main(int argc, char** argv) 
{
    if (argc == 5) 
    {
        try
        {
            int iterations{stoi(argv[1])}; 
            int lines{stoi(argv[2])};
            double time_step{stod(argv[3])};
            double voltage{stod(argv[4])};

            circuit1(iterations, time_step, voltage, lines);
            circuit2(iterations, time_step, voltage, lines);
            circuit3(iterations, time_step, voltage, lines);
        }
        catch(invalid_argument& e)
        {
            cerr << "Invaild arguments. Please correct and run the program again." << endl;
        }
    }
    else
    {
        cerr << argc << endl;
        cerr << "Invalid number of arguments. Please correct and run the program again." << endl;
        return-1;
    } 
}