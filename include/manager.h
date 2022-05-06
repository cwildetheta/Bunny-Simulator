#ifndef MANAGER_H_INCLUDED
#define MANAGER_H_INCLUDED
#include "bunny.h"
#include <list>
#include <memory>

class manager{
    private:
        std::list<std::shared_ptr<bunny>> bunny_list;
        int total, male, female, radioactive_mutant_vampire;

    public:
        manager(int);
        bool bunny_sorter_internal(std::shared_ptr<bunny>, std::shared_ptr<bunny>);
        bool print_out(int);
        void aging();
        void vampire();
        void breed();
        void cull();
};

#endif //MANAGER_H_INCLUDED