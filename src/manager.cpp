#include "manager.h"
#include "bunny.h"
#include <iostream>
#include <list>
#include <vector>
#include <memory>
#include <algorithm>
#include <iomanip>
#include <unistd.h>
#include <conio.h>
#include <time.h>

bool manager::bunny_sorter_internal(std::shared_ptr<bunny> object1, std::shared_ptr<bunny> object2) //Algorithm for sorting bunnies by age
{
    return object1->get_age() > object2->get_age();
}

manager::manager(int num_of_bunnies)
{
    for(int i = 0; i < num_of_bunnies; i++){ //Creates the entered number of starting bunnies
        bunny_list.push_back(std::make_shared<bunny>());
    }
    total = 0, male = 0, female = 0, infected_total = 0, turns = 0; //Initialising the stats
    std::list<std::shared_ptr<bunny>>::iterator i1 = bunny_list.begin();
    for(int i = 0; i < bunny_list.size(); i++){ //Calculating the initial stats.
        total++;
        if((*i1)->get_gender() == "Male"){
            male++;
        }
        else{
            female++;
        }
        if((*i1)->get_infected() == true){
            infected_total++;
        }
        ++i1;
    }
}
bool manager::print_out() //The UI print out, handles all inputs and outputs the bunny list
{
    total = 0, male = 0, female = 0, infected_total = 0; //Resetting the stats ready for recalculation
    turns++;
    bool simulation = true;
    if(bunny_list.size() > 0){
        bunny_list.sort(bunny_sorter_internal); //Makes sure the bunnies are sorted, bit redundant as they shouldn't be able to get unsorted, but good to make sure
        std::cout << "The current bunnies are: " << std::endl;
        std::list<std::shared_ptr<bunny>>::iterator i1 = bunny_list.begin();
        for(int i = 0; i < bunny_list.size(); i++){ //Outputting the bunny list, and counting the stats at the same time
            std::cout << std::setw(15) << (*i1)->get_name() << "  " << std::setw(8) << (*i1)->get_gender() << "  " << std::setw(9) << (*i1)->get_colour() << "  " << std::setw(4) << (*i1)->get_age() << "  ";
            if((*i1)->get_infected() == true){
                std::cout << std::setw(10) << "Infected" << std::endl;
            }
            else{
                std::cout << std::setw(10) << "Healthy" << std::endl;
            }
            total++;
            if((*i1)->get_gender() == "Male"){
                male++;
            }
            else{
                female++;
            }
            if((*i1)->get_infected() == true){
                infected_total++;
            }
            ++i1;
        }
        std::cout << "Total: " << total << "  Males: " << male << "  Females: " << female << "  Infected: " << infected_total << "     Current turn: " << turns << std::endl;
        std::cout << "Press q to quit, k to perform a cull, or any other key to continue: ";
        char input = 'e';
        clock_t start = clock();
        while(((clock() - start) / CLOCKS_PER_SEC) <= 2){
            if( _kbhit() ){
                std::cin >> input;
                break;
            }
        }
        if((input == 'q') || (input == 'Q')){ //Quitting the simulation
            simulation = false;
        }
        if((input == 'k') || (input == 'K')){ //Culling half the bunnies
            cull_mk2();
        }
    }
    else{
        std::cout << "All of the bunnies are dead." << std::endl;
        std::cout << "Simulation over." << std::endl;
        simulation = false;
    }
    return simulation;
}
void manager::aging() //Handles aging and bunnies dying, not in use; works but there's a simplified version now
{
    bunny_list.sort(bunny_sorter_internal); //Makes sure the bunnies are sorted, bit redundant as they shouldn't be able to get unsorted, but good to make sure, as I'm about to rely on it
    std::list<std::shared_ptr<bunny>>::iterator i1 = bunny_list.begin();
    std::unique_ptr<bool[]> is_dead = std::make_unique<bool[]>(bunny_list.size()); //Creating an array of booleans, of equal length to the bunny list
    for(int i = 0; i < bunny_list.size(); i++){ //If the death conditions of a bunny are met, the corresponding boolean is set to true
        if(((*i1)->get_age() >= 10) && ((*i1)->get_infected() == false)){
            is_dead[i] = true;
        }
        else if(((*i1)->get_age() >= 50) && ((*i1)->get_infected() == true)){
            is_dead[i] = true;
        }
        else{ //If the death conditions are not met the age is incremented
            is_dead[i] = false;
            (*i1)->increment_age(1);
        }
        ++i1;
    }
    std::cout << std::endl;
    int to_count_through = bunny_list.size();
    std::list<std::shared_ptr<bunny>>::iterator die = bunny_list.begin();
    for(int i = 0; i < to_count_through; i++){ //Iterating through the bunny list
        if(is_dead[i] == true){ //If the boolean is true
            if((*die)->get_infected() == false){ //Variable death message
                std::cout << "Bunny ";
            }
            else{
                std::cout << "Infected Bunny ";
            }
            std::cout << (*die)->get_name() << " has died." << std::endl; //Death message output
            die = bunny_list.erase(die); //Bunny is removed from the list
        }
        else{
            ++die; //Otherwise increment the iterator
        }
    }
    std::cout << std::endl;
}
void manager::aging_mk2() //Handles aging and bunnies dying, updated to be less needlessly convoluted
{
    std::cout << std::endl << std::endl;
    bunny_list.sort(bunny_sorter_internal); //Makes sure the bunnies are sorted, bit redundant as they shouldn't be able to get unsorted, but good to make sure
    std::list<std::shared_ptr<bunny>>::iterator i1 = bunny_list.begin();
    int to_count_through = bunny_list.size();
    for(int i = 0; i < to_count_through; i++){ //Checking through all the bunnies
        if(((*i1)->get_age() >= 10) && ((*i1)->get_infected() == false)){ //If the conditions for a normal bunny to die are met, it is removed from the list
            std::cout << "Bunny " << (*i1)->get_name() << " has died." << std::endl; //Death output message
            i1 = bunny_list.erase(i1);
            sleep(1);
        }
        else if(((*i1)->get_age() >= 50) && ((*i1)->get_infected() == true)){ //If the conditions for an infected bunny to die are met, it is removed from the list
            std::cout << "Infected Bunny " << (*i1)->get_name() << " has died." << std::endl; //Death output message
            i1 = bunny_list.erase(i1);
            sleep(1);
        }
        else{ //Else the age and iterator are incremented by 1
            (*i1)->increment_age(1);
            ++i1;
        }
    }
    std::cout << std::endl;
}
void manager::infect() //Handles the spread of the infection
{
    std::list<std::shared_ptr<bunny>>::iterator iv = bunny_list.begin();
    std::vector<std::shared_ptr<bunny>> infection_list; //Creates a mirror vector of bunny pointers
    for(int i = 0; i < bunny_list.size(); i++){
        if((*iv)->get_infected() == false){ //Adds bunnies to the mirror vector if they're not infected, and thus are candidates for infection
            infection_list.push_back(*iv);
        }
        ++iv;
    }
    std::random_shuffle(infection_list.begin(), infection_list.end()); //Shuffles the mirror vector, to randomise who's going to get infected
    int counted = 0;
    std::vector<std::shared_ptr<bunny>>::iterator iv2 = infection_list.begin();
    while((infected_total > 0) && (counted < infection_list.size())){ //Runs through the mirror vector infecting bunnies until either all are infected, or the number infected in the loop reaches the number infected already
        (*iv2)->set_infected(true);
        infected_total--;
        ++iv2;
        counted++;
    }
}
void manager::breed() //Handles breeding
{
    std::list<std::shared_ptr<bunny>>::iterator i2 = bunny_list.begin();
    int to_count_through_2 = bunny_list.size();
    bool is_adult_male = false;
    for(int i = 0; i < to_count_through_2; i++){ //Checks that there is an adult male bunny
        if(((*i2)->get_gender() == "Male") && ((*i2)->get_age() > 1) && ((*i2)->get_infected() == false)){
            is_adult_male = true;
        }
        ++i2;
    }
    std::list<std::shared_ptr<bunny>>::iterator i3 = bunny_list.begin();
    if(is_adult_male == true){ //If there is an adult male
        for(int i = 0; i < to_count_through_2; i++){ //Runs through each bunny to find out if they are a healthy adult female
            if(((*i3)->get_gender() == "Female") && ((*i3)->get_age() > 1) && ((*i3)->get_infected() == false)){
                bunny_list.push_back(std::make_shared<bunny>()); //For each such bunny, create a new bunny
                std::list<std::shared_ptr<bunny>>::iterator i4 = bunny_list.end();
                advance(i4, -1);
                (*i4)->set_colour((*i3)->get_colour()); //Set the colour of the new bunny to match the colour of the parent
                if((*i4)->get_infected() == false){
                    std::cout << "Bunny ";
                }
                else{
                    std::cout << "Infected Bunny ";
                }
                std::cout << (*i4)->get_name() << " was born." << std::endl; //Output birth message
                sleep(1);
            }
            ++i3;
        }
    }
    std::cout << std::endl;
}
void manager::cull() //Old cull code, no longer in use
{
    std::list<std::shared_ptr<bunny>>::iterator i4 = bunny_list.begin();
    std::unique_ptr<bool[]> to_die = std::make_unique<bool[]>(bunny_list.size()); //Creates a mirror array of booleans the same length as the bunny list
    int die = 0, survive = 0;
    for(int i = 0; i < bunny_list.size(); i++){ //Randomly allocates each boolean to true or false, 50/50 chance
        if(std::rand()%2 == 0){
            to_die[i] = true;
            die++;
        }
        else{
            to_die[i] = false;
            survive++;
        }
    }
    int difference = die - survive; //This section of code corrects the array to make the die and survive amounts equal, 
    int counter = 0;
    while(difference > 0){
        if(to_die[counter] == true){ //The problem is that it starts from the front of the array, which raises the probabilty of those bunnies, which isn't true random
            to_die[counter] = false;
            die--;
            survive++;
        }
        difference = die - survive;
        counter++;
    }
    while(difference < 0){
        if(to_die[counter] == false){
            to_die[counter] = true;
            die++;
            survive--;
        }
        difference = die - survive;
        counter++;
    }
    std::cout << "Culling " << die << " bunnies, " << survive << " survive." << std::endl;
    sleep(2);
    int to_count_through_2 = bunny_list.size();
    for(int i = 0; i < to_count_through_2; i++){ //Runs through the boolean array. If the boolean is true, the corresponding bunny in the bunny list is removed
        if(to_die[i] == true){
            i4 = bunny_list.erase(i4);
        }
        else{
            ++i4;
        }
    }
}
void manager::cull_mk2() //Handles culling, new and improved version, properly random this time
{
    std::list<std::shared_ptr<bunny>>::iterator i4 = bunny_list.begin();
    std::vector<bool> cull_list; //Creating a mirrow vector of booleans
    for(int i = 0; i < bunny_list.size(); i++){ //The end vector will be the same size as the bunny list
        if(i < bunny_list.size()/2){ //The first half of the array is set to true, the second half to false
            cull_list.push_back(true);
        }
        else{
            cull_list.push_back(false);
        }
    }
    std::random_shuffle(cull_list.begin(), cull_list.end()); //Shuffling the boolean vector. Randomness is in the hands of std now
    std::vector<bool>::iterator ic = cull_list.begin();
    std::cout << "Culling " << (bunny_list.size()/2) << " bunnies, " << (get_total()-(bunny_list.size()/2)) << " survive." << std::endl; //Culling output
    sleep(2);
    int to_count_through_2 = bunny_list.size();
    for(int i = 0; i < to_count_through_2; i++){ //Working through the boolean array and bunny list side by side
        if((*ic) == true){ //If the value is true, the corresponding bunny in the bunny list is deleted
            i4 = bunny_list.erase(i4);
        }
        else{
            ++i4;
        }
        ++ic;
    }
}

//VARIABLE INTERACTIONS//

int manager::get_infected_total() const
{
    return infected_total;
}
int manager::get_male()
{
    std::list<std::shared_ptr<bunny>>::iterator imale = bunny_list.begin();
    male = 0;
    for(int i = 0; i < bunny_list.size(); i++){
        if((*imale)->get_gender() == "Male"){
            male++;
        }
        ++imale;
    }
    return male;
}
int manager::get_female()
{
    std::list<std::shared_ptr<bunny>>::iterator ifemale = bunny_list.begin();
    female = 0;
    for(int i = 0; i < bunny_list.size(); i++){
        if((*ifemale)->get_gender() == "Female"){
            female++;
        }
        ++ifemale;
    }
    return female;
}
int manager::get_total()
{
    total = bunny_list.size();
    return total;
}