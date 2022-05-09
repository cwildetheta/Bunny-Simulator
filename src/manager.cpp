#include "manager.h"
#include "bunny.h"
#include <iostream>
#include <list>
#include <vector>
#include <memory>
#include <algorithm>
#include <iomanip>


bool manager::bunny_sorter_internal(std::shared_ptr<bunny> object1, std::shared_ptr<bunny> object2)
{
    return object1->get_age() > object2->get_age();
}

manager::manager(int num_of_bunnies)
{
    for(int i = 0; i < num_of_bunnies; i++){
        bunny_list.push_back(std::make_shared<bunny>());
    }
    total = 0, male = 0, female = 0, infected_total = 0, turns = 0;
    std::list<std::shared_ptr<bunny>>::iterator i1 = bunny_list.begin();
    for(int i = 0; i < bunny_list.size(); i++){
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
        i1++;
    }
}
bool manager::print_out()
{
    total = 0, male = 0, female = 0, infected_total = 0;
    turns++;
    bool simulation = true;
    if(bunny_list.size() > 0){
        bunny_list.sort(bunny_sorter_internal);
        std::cout << "The current bunnies are: " << std::endl;
        std::list<std::shared_ptr<bunny>>::iterator i1 = bunny_list.begin();
        for(int i = 0; i < bunny_list.size(); i++){
            std::cout << std::setw(15) << (*i1)->get_name() << "  " << std::setw(6) << (*i1)->get_gender() << "  " << std::setw(7) << (*i1)->get_colour() << "  " << std::setw(2) << (*i1)->get_age() << "  " << std::boolalpha << std::setw(5) << (*i1)->get_infected() << std::noboolalpha << std::endl;
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
            i1++;
        }
        std::cout << "Total: " << total << "  Males: " << male << "  Females: " << female << "  RMV: " << infected_total << "     Current turn: " << turns << std::endl;
        std::cout << "Press q to quit, k to perform a cull, or any other key to continue: ";
        char input;
        std::cin >> input;
        if((input == 'q') || (input == 'Q')){
            simulation = false;
        }
        if((input == 'k') || (input == 'K')){
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
void manager::aging()
{
    std::list<std::shared_ptr<bunny>>::iterator i1 = bunny_list.begin();
    std::unique_ptr<bool[]> is_dead = std::make_unique<bool[]>(bunny_list.size());
    for(int i = 0; i < bunny_list.size(); i++){
        if(((*i1)->get_age() >= 10) && ((*i1)->get_infected() == false)){
            is_dead[i] = true;
        }
        else if(((*i1)->get_age() >= 50) && ((*i1)->get_infected() == true)){
            is_dead[i] = true;
        }
        else{
            is_dead[i] = false;
            (*i1)->increment_age(1);
        }
        i1++;
    }
    std::cout << std::endl;
    int to_count_through = bunny_list.size();
    for(int i = 0; i < to_count_through; i++){
        if(is_dead[i] == true){
            std::list<std::shared_ptr<bunny>>::iterator die = bunny_list.begin();
            if((*die)->get_infected() == false){
                std::cout << "Bunny ";
            }
            else{
                std::cout << "Infected Bunny ";
            }
            std::cout << (*die)->get_name() << " has died." << std::endl;
            bunny_list.pop_front();
        }
    }
    std::cout << std::endl;
}
void manager::infect()
{
    std::list<std::shared_ptr<bunny>>::iterator iv = bunny_list.begin();
    std::vector<std::shared_ptr<bunny>> infection_list;
    for(int i = 0; i < bunny_list.size(); i++){
        if((*iv)->get_infected() == false){
            infection_list.push_back(*iv);
        }
        advance(iv, 1);
    }
    std::random_shuffle(infection_list.begin(), infection_list.end());
    int counted = 0;
    std::vector<std::shared_ptr<bunny>>::iterator iv2 = infection_list.begin();
    while((infected_total > 0) && (counted < infection_list.size())){
        (*iv2)->set_infected(true);
        infected_total--;
        advance(iv2, 1);
        counted++;
    }
}
void manager::breed()
{
    std::list<std::shared_ptr<bunny>>::iterator i2 = bunny_list.begin();
    int to_count_through_2 = bunny_list.size();
    bool is_adult_male = false;
    for(int i = 0; i < to_count_through_2; i++){
        if(((*i2)->get_gender() == "Male") && ((*i2)->get_age() > 1) && ((*i2)->get_infected() == false)){
            is_adult_male = true;
        }
        i2++;
    }
    std::list<std::shared_ptr<bunny>>::iterator i3 = bunny_list.begin();
    if(is_adult_male == true){
        std::cout << std::endl;
        for(int i = 0; i < to_count_through_2; i++){
            if(((*i3)->get_gender() == "Female") && ((*i3)->get_age() > 1) && ((*i3)->get_infected() == false)){
                bunny_list.push_back(std::make_shared<bunny>());
                std::list<std::shared_ptr<bunny>>::iterator i4 = bunny_list.end();
                advance(i4, -1);
                (*i4)->set_colour((*i3)->get_colour());
                if((*i4)->get_infected() == false){
                    std::cout << "Bunny ";
                }
                else{
                    std::cout << "Infected Bunny ";
                }
                std::cout << (*i4)->get_name() << " was born." << std::endl;
            }
            i3++;
        }
    }
}
void manager::cull()
{
    std::list<std::shared_ptr<bunny>>::iterator i4 = bunny_list.begin();
    std::unique_ptr<bool[]> to_die = std::make_unique<bool[]>(bunny_list.size());
    int die = 0, survive = 0;
    for(int i = 0; i < bunny_list.size(); i++){
        if(std::rand()%2 == 0){
            to_die[i] = true;
            die++;
        }
        else{
            to_die[i] = false;
            survive++;
        }
    }
    int difference = die - survive;
    int counter = 0;
    while(difference > 0){
        if(to_die[counter] == true){
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
    system("pause");
    int to_count_through_2 = bunny_list.size();
    for(int i = 0; i < to_count_through_2; i++){
        if(to_die[i] == true){
            i4 = bunny_list.erase(i4);
        }
        else{
            advance(i4, 1);
        }
    }
}
void manager::cull_mk2()
{
    std::list<std::shared_ptr<bunny>>::iterator i4 = bunny_list.begin();
    std::vector<bool> cull_list;
    for(int i = 0; i < bunny_list.size(); i++){
        if(i < bunny_list.size()/2){
            cull_list.push_back(true);
        }
        else{
            cull_list.push_back(false);
        }
    }
    std::random_shuffle(cull_list.begin(), cull_list.end());
    std::vector<bool>::iterator ic = cull_list.begin();
    std::cout << "Culling " << (bunny_list.size()/2) << " bunnies, " << (get_total()-(bunny_list.size()/2)) << " survive." << std::endl;
    system("pause");
    int to_count_through_2 = bunny_list.size();
    for(int i = 0; i < to_count_through_2; i++){
        if((*ic) == true){
            i4 = bunny_list.erase(i4);
        }
        else{
            advance(i4, 1);
        }
        advance(ic, 1);
    }
}

//VARIABLE INTERACTIONS//

int manager::get_infected_total()
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
        imale++;
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
        ifemale++;
    }
    return female;
}
int manager::get_total()
{
    total = bunny_list.size();
    return total;
}