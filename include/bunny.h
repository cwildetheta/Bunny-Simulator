#ifndef BUNNY_H_INCLUDED
#define BUNNY_H_INCLUDED
#include <iostream>

class bunny{
    private:
        bool radioactive_mutant_vampire_bunny;
        std::string name, gender, colour;
        int age;

    public:
        bunny();
        void increment_age(int);

        //VARIABLE INTERACTIONS//
        bool get_radioactive_mutant_vampire_bunny();
        void set_radioactive_mutant_vampire_bunny(bool);
        std::string get_name();
        //void set_name(std::string);
        std::string get_gender();
        //void set_gender(std::string);
        std::string get_colour();
        //void set_colour(std::string);
        int get_age();
        void set_age(int);
};

#endif //BUNNY_H_INCLUDED