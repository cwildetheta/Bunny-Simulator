#ifndef MANAGER_H_INCLUDED
#define MANAGER_H_INCLUDED
#include "bunny.h"
#include <list>
#include <memory>
#include <fstream>

class manager{
    private:
        std::list<std::shared_ptr<bunny>> bunny_list;
        int total, male, female, infected_total, turns;

    public:
        explicit manager(int);
        static bool bunny_sorter_internal(std::shared_ptr<bunny>, std::shared_ptr<bunny>);
        bool print_out(std::ofstream&);
        void aging(std::ofstream&);
        void infect();
        void breed(std::ofstream&);
        void cull(std::ofstream&);

        void calculate_infected_total();
        void calculate_male();
        void calculate_female();
        void calculate_total();

        //VARIABLE INTERACTIONS//
        int get_infected_total() const;
        int get_male() const;
        int get_female() const;
        int get_total() const;
};

#endif //MANAGER_H_INCLUDED