// Jimmy Von Holle
// ######### FILENAME: interact.cpp
// CS 372
// Spring 2016
// Assignemnt 4
//      Chain of Responisbility source file
//      for interaction handler
//      Descriptions in header file a4.h
#include "a4.h"

#include <sstream> // for std::istringstream

// ****************
// * CONSTRUCTORS *
// ****************
Interact_handler::Interact_handler(){ 
    std::shared_ptr<Handler> temp = std::make_shared<Listen_handler>();
    next_ = temp;
}

// ********************
// * MEMBER FUNCTIONS *
// ******************** 
bool Interact_handler::handle(Action & turn){
    std::string pos;
    std::istringstream work_desc(turn.get_input());
    work_desc >> pos;
    
    return next_->handle(turn);
}