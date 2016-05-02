// Jimmy Von Holle
// ######### FILENAME: smell.cpp
// CS 372
// Spring 2016
// Assignemnt 4
//      Chain of Responisbility source file
//      handler for smell option
//      Descriptions in header file a4.h
#include "a4.h"

#include <sstream> // for std::istringstream

// ****************
// * CONSTRUCTORS *
// ****************
Smell_handler::Smell_handler(){ 
    std::shared_ptr<Handler> temp = std::make_shared<Lick_handler>();
    next_ = temp;
}

// ********************
// * MEMBER FUNCTIONS *
// ******************** 
bool Smell_handler::handle(Action & turn){
    std::string pos;
    std::istringstream work_desc(turn.get_input());
    work_desc >> pos;

    if(pos == "smell" || pos == "Smell"){
        work_desc >> pos;
        for(auto & i : turn.get_current()->get_next()["<Smell>"]){
            if(i.first == pos){
                turn.move_up("<Smell>", pos);
                return true;
            }
        }
        work_desc >> pos;
    }else{
        return next_->handle(turn);
    }
}