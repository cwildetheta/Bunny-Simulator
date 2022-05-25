#include "manager.h"
#include <iostream>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <vector>
#include <thread>

int main()
{
    system("cls");
    std::srand(time(0)); //Seeding the random number generation.
    std::string delete_command = R"(del .\output\*.txt)";
    system(delete_command.c_str());
    std::vector<manager> manager_vector;
    std::vector<std::thread> thread_vector;
    for(int i = 0; i < 10; i++){
        manager_vector.push_back(manager(5));
    }

    std::vector<manager>::iterator i1 = manager_vector.begin();
    //manager controller(5); //Setting up the simulation with 5 initial bunnies.
    std::thread thread1(&manager::run, i1, R"(output\output_1.txt)", R"(output\run_1_stats.txt)");
    thread1.join();
    ++i1;
    //manager controller2(5);
    std::thread thread2(&manager::run, i1, R"(output\output_2.txt)", R"(output\run_2_stats.txt)");
    thread2.join();
    //i1->run(R"(output\output_2.txt)", R"(output\run_2_stats.txt)");
    std::string filename = "./src/graph.py";
    std::string command = "python ";
    command += filename;
    char input;
    std::cout << "Would you like a graph of the simulation stats to be produced? Press y for yes, or any other key for no." << std::endl;
    std::cout << "WARNING: The graph program was built with Python 2.7.13. A compatible version must be installed for the graph to be produced." << std::endl;
    std::cout << "Input: ";
    std::cin >> input;
    if((input == 'y') || (input == 'Y')){
        system(command.c_str());
    }
    return 0;
}