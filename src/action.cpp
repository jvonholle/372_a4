// Jimmy Von Holle
// ######### FILENAME: action.cpp
// CS 372
// Spring 2016
// Assignemnt 4
//      Chain of Responisbility source file
//      for class Action
//      Descriptions in header file a4.h
#include "a4.h"

#include <string> // for std::string && std::getline()
#include <iostream> // for std::cin used with std::getline()

// ****************
// * CONSTRUCTORS *
// ****************
Action::Action()
    { current_ = std::make_shared<Level>(); }

Action::Action(const std::string & other_than_start)
    { current_ = std::make_shared<Level>(other_than_start); }

// *******************
// * A & M FUNCTIONS *
// *******************
std::string Action::get_input(){
    return input_;
}

std::shared_ptr<Level> Action::get_current(){
    return current_;
}

// ********************
// * MEMBER FUNCTIONS *
// ********************
void Action::prompt_player(){
    std::cout << "What do you do? \n> ";
    std::getline(std::cin, input_);
}

void Action::turn(){
    current_->print();
    if(!current_->is_bad())
        prompt_player();
}

void Action::move_up(const std::string & move_to){
    current_ = current_->move(move_to);
}
