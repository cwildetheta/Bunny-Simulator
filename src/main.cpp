#include "manager.h"
#include <iostream>
#include <ctime>

int main()
{
    system("cls");
    std::srand(time(0)); //Seeding the random number generation.
    manager controller(5); //Setting up the simulation with 5 initial bunnies.
    bool simulation = true; //The simulation tracker.
    while(simulation == true){ //The start of the simulation loop.
        simulation = controller.print_out(); //The print out and entry option.
        if(simulation == true){ //If the simulation is ongoing.
            controller.aging_mk2(); //Handles aging and dieing.
            if(controller.get_infected_total() > 0){ //If there are infected bunnies.
                controller.infect(); //Handles the infection spreading.
            }
            controller.breed(); //Handles the breeding.
            system("pause"); //A pause so the user can read the death and birth messages.
            if(controller.get_total() > 1000){ //If overpopulated.
                controller.cull_mk2(); //Handles the bunnies dieing from overpopulation.
            }
        }
    }
    return 0;
}