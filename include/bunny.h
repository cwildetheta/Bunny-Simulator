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

        bunny(std::string, std::string, int, std::string, bool);
        void increment_age(int);

        //VARIABLE INTERACTIONS//
        bool get_infected() const;
        void set_infected(bool);
        std::string get_name() const;
        std::string get_gender() const;
        std::string get_colour() const;
        void set_colour(std::string);
        int get_age() const;
        void set_age(int);
};

#endif //BUNNY_H_INCLUDED