// Jimmy Von Holle
// ######### FILENAME: listen.cpp
// CS 372
// Spring 2016
// Assignemnt 4
//      Chain of Responisbility source file
//      handler for listen option
//      Descriptions in header file a4.h
#include "a4.h"

#include <sstream> // for std::istringstream

// ****************
// * CONSTRUCTORS *
// ****************
Listen_handler::Listen_handler(){ 
    std::shared_ptr<Handler> temp = std::make_shared<Lick_handler>();
    next_ = temp;
}

// ********************
// * MEMBER FUNCTIONS *
// ******************** 
bool Listen_handler::handle(Action & turn){
    std::string pos;
    std::istringstream work_desc(turn.get_input());
    work_desc >> pos;
    
    return next_->handle(turn);
}
