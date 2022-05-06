#ifndef BUNNY_H_INCLUDED
#define BUNNY_H_INCLUDED
#include <iostream>

class bunny{
    private:
        bool infected;
        std::string colour;
        const std::string gender, name;

    public:
        int age;

        bunny();
        void increment_age(int);

        //VARIABLE INTERACTIONS//
        bool get_infected();
        void set_infected(bool);
        std::string get_name();
        //void set_name(std::string);
        std::string get_gender();
        //void set_gender(std::string);
        std::string get_colour();
        void set_colour(std::string);
        int get_age();
        void set_age(int);
};

#endif //BUNNY_H_INCLUDED