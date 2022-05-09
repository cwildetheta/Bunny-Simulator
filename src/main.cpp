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
    stats << "   Total     Males     Females   Infected" << std::endl;
    manager controller(5); //Setting up the simulation with 5 initial bunnies.
    bool simulation = true; //The simulation tracker.
    while(simulation == true){ //The start of the simulation loop.
        simulation = controller.print_out(output); //The print out and entry option.
        stats << std::setw(6) << controller.get_total() << std::setw(10) << controller.get_male() << std::setw(10) << controller.get_female() << std::setw(10) << controller.get_infected_total() << std::endl;
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
    return 0;
}