#include "manager.h"
#include "base_functions.h"
#include <iostream>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <vector>
#include <thread>

int main()
{
    system("cls");
    std::srand(time(NULL)); //Seeding the random number generation.
    std::string delete_command = R"(del .\output\*.txt)";
    system(delete_command.c_str());
    std::vector<manager> manager_vector;
    std::vector<std::thread> thread_vector;
    std::cout << "How many instances of the program would you like to run?" << std::endl;
    int number_of_threads = int_value_checker("Enter a number between 1 and 100: ", 1, 100);
    for(int i = 0; i < number_of_threads; i++){
        manager_vector.push_back(manager(5));
    }

    std::vector<manager>::iterator i1 = manager_vector.begin();
    for(int i = 0; i < number_of_threads; i++){
        std::string output_name = "output\\output_" + std::to_string(i+1) + ".txt";
        std::string stats_name = "output\\run_" + std::to_string(i+1) + "_stats.txt";
        //std::cout << output_name << "  " << stats_name << std::endl;
        thread_vector.push_back(std::thread(&manager::run, i1, output_name, stats_name));
        ++i1;
    }
    for(auto &elem : thread_vector){
        elem.join();
    }
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