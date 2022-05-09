#include "manager.h"

int main()
{
    system("cls");
    std::srand(time(0)); //Seeding the random number generation.
    manager controller(5); //Setting up the simulation with 5 initial bunnies.
    bool simulation = true; //The simulation tracker.
    while(simulation == true){ //The start of the simulation loop.
        simulation = controller.print_out(); //The print out and entry option.
        if(simulation == true){ //If the simulation is ongoing.
        controller.end_turn(); //Running the end turn functions
        }
    }
    return 0;
}