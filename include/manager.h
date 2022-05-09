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
        manager(int);
        static bool bunny_sorter_internal(std::shared_ptr<bunny>, std::shared_ptr<bunny>);
        bool print_out(std::ofstream&);
        void aging(std::ofstream&);
        void infect();
        void breed(std::ofstream&);
        void cull(std::ofstream&);

        //VARIABLE INTERACTIONS//
        int get_infected_total();
        int get_male();
        int get_female();
        int get_total();
};

#endif //MANAGER_H_INCLUDED