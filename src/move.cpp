// Jimmy Von Holle
// ######### FILENAME: move.cpp
// CS 372
// Spring 2016
// Assignemnt 4
//      Chain of Responisbility source file
//      handler for moving
//      Has all function definitions
//      Descriptions in header file a4.h
#include "a4.h"

#include <sstream> // for std::istringstream
#include <iostream> // for std::cout && std::endl

// ****************
// * CONSTRUCTORS *
// ****************
Move_handler::Move_handler(){ 
    std::shared_ptr<Handler> temp = std::make_shared<Look_handler>();
    next_ = temp;
}
  
// ********************
// * MEMBER FUNCTIONS *
// ********************  
bool Move_handler::handle(Action & turn){
    std::string pos;
    std::istringstream work_desc(turn.get_input());
    work_desc >> pos;
    
    while(true){
        if(pos == "move" || pos == "walk" || pos == "Move" || pos == "Walk"){
            work_desc >> pos;
            if(pos == "towards" || pos == "to")
                work_desc >> pos;
            for(auto & i : turn.get_current()->get_next()["<Move>"]){
                if(i.first == pos){
                    turn.move_up("<Move>", pos);
                    return true;
                }
            }
            work_desc >> pos;
        }else{
            return next_->handle(turn);
        }
    }
}
