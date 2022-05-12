#include "manager.h"
#include <iostream>
#include <ctime>
#include <fstream>
#include <iomanip>

int main()
{
    system("cls");
    std::srand(time(0)); //Seeding the random number generation.
    std::ofstream stats, output;
    stats.open ("Turn stats.txt");
    output.open ("Output.txt");
    stats << "Total Males Females Infected";
    manager controller(5); //Setting up the simulation with 5 initial bunnies.
    bool simulation = true; //The simulation tracker.
    while(simulation == true){ //The start of the simulation loop.
        simulation = controller.print_out(output); //The print out and entry option.
        stats << std::endl << controller.get_total() << " " << controller.get_male() << " " << controller.get_female() << " " << controller.get_infected_total();
        if(simulation == true){ //If the simulation is ongoing.
            controller.aging(output); //Handles aging and dieing.
            if(controller.get_infected_total() > 0){ //If there are infected bunnies.
                controller.infect(); //Handles the infection spreading.
            }
            controller.breed(output); //Handles the breeding.
            system("pause"); //A pause so the user can read the death and birth messages.
            if(controller.get_total() > 1000){ //If overpopulated.
                controller.cull(output); //Handles the bunnies dieing from overpopulation.
            }
        }
    }
    stats.close();
    output.close();
    //std::string filename = "C:/msys64/home/Connor/Bunny Simulator/graph.py";
    std::string filename = "graph.py";
    std::string command = "python ";
    command += filename;
    system(command.c_str());
    return 0;
}