// Jimmy Von Holle
// ######### FILENAME: lick.cpp
// CS 372
// Spring 2016
// Assignemnt 4
//      Chain of Responisbility source file
//      handler for lick option
//      last link in responisbility chain,
//      any new options get added here.
//      Descriptions in header file a4.h
#include "a4.h"

#include <sstream> // for std::istringstream

// ****************
// * CONSTRUCTORS *
// ****************
Lick_handler::Lick_handler()
    { next_ = nullptr; }
    
// ********************
// * MEMBER FUNCTIONS *
// ******************** 
bool Lick_handler::handle(Action & turn){
    std::string pos;
    std::istringstream work_desc(turn.get_input());
    work_desc >> pos;

    if(pos == "lick" || pos == "taste" || pos == "Lick" || pos == "Taste"){
        work_desc >> pos;
        if(pos == "the")
            work_desc >> pos;
        for(auto & i : turn.get_current()->get_next()["<Lick>"]){
            if(i.first == pos){
                turn.move_up("<Lick>", pos);
                return true;
            }
        }
        work_desc >> pos;
    }else{
        return false;
    }
}
