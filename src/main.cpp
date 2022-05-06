#include "manager.h"
#include <iostream>
#include <ctime>
#include <fstream>
#include <iomanip>

int main()
{
    system("cls");
    std::srand(time(0)); //Seeding the random number generation.
    std::ofstream testfile;
    testfile.open ("Test file.txt");
    testfile << "   Total     Males     Females   Infected" << std::endl;
    manager controller(5); //Setting up the simulation with 5 initial bunnies.
    bool simulation = true; //The simulation tracker.
    while(simulation == true){ //The start of the simulation loop.
        simulation = controller.print_out(); //The print out and entry option.
        testfile << std::setw(6) << controller.get_total() << std::setw(10) << controller.get_male() << std::setw(10) << controller.get_female() << std::setw(10) << controller.get_infected_total() << std::endl;
        if(simulation == true){ //If the simulation is ongoing.
            controller.aging(); //Handles aging and dieing.
            if(controller.get_infected_total() > 0){ //If there are infected bunnies.
                controller.infect(); //Handles the infection spreading.
            }
            controller.breed(); //Handles the breeding.
            system("pause"); //A pause so the user can read the death and birth messages.
            if(controller.get_total() > 1000){ //If overpopulated.
                controller.cull(); //Handles the bunnies dieing from overpopulation.
            }
        }
    }
    testfile.close();
    return 0;
}