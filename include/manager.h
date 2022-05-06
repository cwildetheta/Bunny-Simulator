#ifndef MANAGER_H_INCLUDED
#define MANAGER_H_INCLUDED
#include "bunny.h"
#include <list>
#include <memory>

class manager{
    private:
        std::list<std::shared_ptr<bunny>> bunny_list;
        int total, male, female, radioactive_mutant_vampire, turns;

    public:
        manager(int);
        static bool bunny_sorter_internal(std::shared_ptr<bunny>, std::shared_ptr<bunny>);
        bool print_out();
        void aging();
        void vampire();
        void breed();
        void cull();

        //VARIABLE INTERACTIONS//
        int get_radioactive_mutant_vampire();
        int get_total();
};

#endif //MANAGER_H_INCLUDED