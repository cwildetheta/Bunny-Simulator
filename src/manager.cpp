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
    total = 0, male = 0, female = 0, radioactive_mutant_vampire = 0, turns = 0;
    std::list<std::shared_ptr<bunny>>::iterator i1 = bunny_list.begin();
    for(int i = 0; i < bunny_list.size(); i++){
        total++;
        if((*i1)->get_gender() == "Male"){
            male++;
        }
        else{
            female++;
        }
        if((*i1)->get_radioactive_mutant_vampire_bunny() == true){
            radioactive_mutant_vampire++;
        }
        i1++;
    }
}
bool manager::print_out()
{
    total = 0, male = 0, female = 0, radioactive_mutant_vampire = 0;
    turns++;
    bool simulation = true;
    if(bunny_list.size() > 0){
        bunny_list.sort(bunny_sorter_internal);
        std::cout << "The current bunnies are: " << std::endl;
        std::list<std::shared_ptr<bunny>>::iterator i1 = bunny_list.begin();
        for(int i = 0; i < bunny_list.size(); i++){
            std::cout << std::setw(15) << (*i1)->get_name() << "  " << std::setw(6) << (*i1)->get_gender() << "  " << std::setw(7) << (*i1)->get_colour() << "  " << std::setw(2) << (*i1)->get_age() << "  " << std::boolalpha << std::setw(5) << (*i1)->get_radioactive_mutant_vampire_bunny() << std::noboolalpha << std::endl;
            total++;
            if((*i1)->get_gender() == "Male"){
                male++;
            }
            else{
                female++;
            }
            if((*i1)->get_radioactive_mutant_vampire_bunny() == true){
                radioactive_mutant_vampire++;
            }
            i1++;
        }
        std::cout << "Total: " << total << "  Males: " << male << "  Females: " << female << "  RMV: " << radioactive_mutant_vampire << "     Current turn: " << turns << std::endl;
        std::cout << "Press any key: ";
        char input;
        std::cin >> input;
        if(input == 'q'){
            simulation = false;
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
        if(((*i1)->get_age() >= 10) && ((*i1)->get_radioactive_mutant_vampire_bunny() == false)){
            is_dead[i] = true;
        }
        else if(((*i1)->get_age() >= 50) && ((*i1)->get_radioactive_mutant_vampire_bunny() == true)){
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
            if((*die)->get_radioactive_mutant_vampire_bunny() == false){
                std::cout << "Bunny ";
            }
            else{
                std::cout << "Radioactive Mutant Vampire Bunny ";
            }
            std::cout << (*die)->get_name() << " has died." << std::endl;
            bunny_list.pop_front();
        }
    }
    std::cout << std::endl;
}
void manager::vampire()
{
    std::list<std::shared_ptr<bunny>>::iterator iv = bunny_list.begin();
    std::vector<std::shared_ptr<bunny>> infection_list;
    for(int i = 0; i < bunny_list.size(); i++){
        if((*iv)->get_radioactive_mutant_vampire_bunny() == false){
            infection_list.push_back(*iv);
        }
        advance(iv, 1);
    }
    std::random_shuffle(infection_list.begin(), infection_list.end());
    int counted = 0;
    std::vector<std::shared_ptr<bunny>>::iterator iv2 = infection_list.begin();
    while((radioactive_mutant_vampire > 0) && (counted < infection_list.size())){
        (*iv2)->set_radioactive_mutant_vampire_bunny(true);
        radioactive_mutant_vampire--;
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
        if(((*i2)->get_gender() == "Male") && ((*i2)->get_age() > 1) && ((*i2)->get_radioactive_mutant_vampire_bunny() == false)){
            is_adult_male = true;
        }
        i2++;
    }
    std::list<std::shared_ptr<bunny>>::iterator i3 = bunny_list.begin();
    if(is_adult_male == true){
        std::cout << std::endl;
        for(int i = 0; i < to_count_through_2; i++){
            if(((*i3)->get_gender() == "Female") && ((*i3)->get_age() > 1) && ((*i3)->get_radioactive_mutant_vampire_bunny() == false)){
                bunny_list.push_back(std::make_shared<bunny>());
                std::list<std::shared_ptr<bunny>>::iterator i4 = bunny_list.end();
                advance(i4, -1);
                (*i4)->set_colour((*i3)->get_colour());
                if((*i4)->get_radioactive_mutant_vampire_bunny() == false){
                    std::cout << "Bunny ";
                }
                else{
                    std::cout << "Radioactive Mutant Vampire Bunny ";
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

//VARIABLE INTERACTIONS//

int manager::get_radioactive_mutant_vampire()
{
    return radioactive_mutant_vampire;
}
int manager::get_total()
{
    total = bunny_list.size();
    return total;
}