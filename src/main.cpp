#include "bunny.h"
#include <iostream>
#include <list>
#include <memory>
#include <ctime>
#include <iomanip>

void purge_unique_bool_pointer(std::unique_ptr<bool[]> object){}

int main()
{
    system("cls");
    std::srand(time(0));

    std::list<std::shared_ptr<bunny>> bunny_list;
    for(int i = 0; i < 5; i++){
        bunny_list.push_back(std::make_shared<bunny>());
    }
    bool simulation = true;
    int turns = 0;
    while(simulation == true){
        //Print Out -------------------------------------------------------------------------------
        turns++;
        if(bunny_list.size() > 0){
            std::cout << "The current bunnies are: " << std::endl;
            int total = 0, male = 0, female = 0, radioactive_mutant_vampire = 0;
            std::list<std::shared_ptr<bunny>>::iterator i1 = bunny_list.begin();
            for(int i = 0; i < bunny_list.size(); i++){
                std::cout << (*i1)->get_name() << "  " << (*i1)->get_gender() << "  " << (*i1)->get_colour() << "  " << (*i1)->get_age() << "  " << std::boolalpha << (*i1)->get_radioactive_mutant_vampire_bunny() << std::noboolalpha << std::endl;
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
        }
        else{
            std::cout << "All of the bunnies are dead." << std::endl;
            std::cout << "Simulation over." << std::endl;
            simulation = false;
        }
        //End of Print Out ------------------------------------------------------------------------
        std::cout << "Press any key: ";
        char input;
        std::cin >> input;
        if(input == 'q'){
            simulation = false;
        }
        //Aging or Dieing -------------------------------------------------------------------------
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
                bunny_list.pop_front();
            }
        }
        purge_unique_bool_pointer(move(is_dead));
        //End of Aging or Dieing ------------------------------------------------------------------
        //Breeding --------------------------------------------------------------------------------
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
            for(int i = 0; i < to_count_through_2; i++){
                if(((*i3)->get_gender() == "Female") && ((*i3)->get_age() > 1) && ((*i3)->get_radioactive_mutant_vampire_bunny() == false)){
                    bunny_list.push_back(std::make_shared<bunny>());
                    std::list<std::shared_ptr<bunny>>::iterator i4 = bunny_list.end();
                    advance(i4, -1);
                    (*i4)->set_colour((*i3)->get_colour());
                }
                i3++;
            }
        }
        //End of Breeding -------------------------------------------------------------------------
    }

    return 0;
}