#include "bunny.h"
#include <iostream>

bunny::bunny(std::string gender_input, std::string name_input, int age_input, std::string colour_input, bool infected_input) : gender(gender_input), name(name_input), age(age_input), colour(colour_input), infected(infected_input)
{}

void bunny::increment_age(int int_input) //Adds the input to the bunnies age; an easier to increment than a get and set pair
{
    age = age + int_input;
}

//VARIABLE INTERACTIONS//
bool bunny::get_infected() const
{
    return infected;
}
void bunny::set_infected(bool bool_input)
{
    infected = bool_input;
}
std::string bunny::get_name() const
{
    return name;
}
std::string bunny::get_gender() const
{
    return gender;
}
std::string bunny::get_colour() const
{
    return colour;
}
void bunny::set_colour(std::string string_input)
{
    colour = string_input;
}
int bunny::get_age() const
{
    return age;
}
void bunny::set_age(int int_input)
{
    age = int_input;
}