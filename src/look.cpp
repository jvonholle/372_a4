// Jimmy Von Holle
// ######### FILENAME: look.cpp
// CS 372
// Spring 2016
// Assignemnt 4
//      Chain of Responisbility source file
//      handler for look option
//      Descriptions in header file a4.h
#include "a4.h"

#include <sstream> // for std::istringstream

// ****************
// * CONSTRUCTORS *
// ****************
Look_handler::Look_handler(){ 
    std::shared_ptr<Handler> temp = std::make_shared<Interact_handler>();
    next_ = temp;
}

// ********************
// * MEMBER FUNCTIONS *
// ******************** 
bool Look_handler::handle(Action & turn){
    std::string pos;
    std::istringstream work_desc(turn.get_input());
    work_desc >> pos;

    if(pos == "look" || pos == "inspect" || pos == "check" || pos == "Look" || pos == "Inspect" || pos == "Check"){
        work_desc >> pos;
        if(pos == "at")
            work_desc >> pos;
        for(auto & i : turn.get_current()->get_next()["<Look>"]){
            if(i.first == pos){
                turn.move_up("<Look>", pos);
                return true;
            }
        }
        work_desc >> pos;
    }else{
        return next_->handle(turn);
    }
}
