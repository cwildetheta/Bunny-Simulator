#include "bunny.h"
#include <iostream>

std::string colour_list[4] = {"White", "Black", "Brown", "Spotted"};
std::string gender_list[2] = {"Male", "Female"};
std::string male_name_list[5] = {"Spots", "Hopper", "Thumper", "Bump", "Arcturus"};
std::string female_name_list[5] = {"Dotty", "Sarah", "Fluffy" , "Heather", "Heaps"};

bunny::bunny() : gender(gender_list[std::rand()%2]), name((gender == gender_list[0]) ? (male_name_list[std::rand()%5]) : (female_name_list[std::rand()%5]))
{
    age = 0;
    int rand = std::rand()%2;
    /*if(rand == 0){
        gender = "Male";
    }
    else{
        gender = "Female";
    }*/
    int rand2 = std::rand()%4;
    colour = colour_list[rand2];
    int rand3 = std::rand()%5;
    /*if(gender == "Male"){
        name = male_name_list[rand3];
    }
    else{
        name = female_name_list[rand3];
    }*/
    int rand4 = std::rand()%50;
    if(rand4 == 0){
        radioactive_mutant_vampire_bunny = true;
    }
    else{
        radioactive_mutant_vampire_bunny = false;
    }
}

void bunny::increment_age(int int_input)
{
    age = age + int_input;
}

//VARIABLE INTERACTIONS//
bool bunny::get_radioactive_mutant_vampire_bunny()
{
    return radioactive_mutant_vampire_bunny;
}
void bunny::set_radioactive_mutant_vampire_bunny(bool bool_input)
{
    radioactive_mutant_vampire_bunny = bool_input;
}
std::string bunny::get_name()
{
    return name;
}
/*void bunny::set_name(std::string string_input)
{
    name = string_input;
}*/
std::string bunny::get_gender()
{
    return gender;
}
/*void bunny::set_gender(std::string string_input)
{
    gender = string_input;
}*/
std::string bunny::get_colour()
{
    return colour;
}
void bunny::set_colour(std::string string_input)
{
    colour = string_input;
}
int bunny::get_age()
{
    return age;
}
void bunny::set_age(int int_input)
{
    age = int_input;
}