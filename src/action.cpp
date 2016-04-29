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

Action::Action(){
    current_ = new Level;
}

Action::Action(Level & other_than_start){
    current_ = new Level(other_than_start);
}

void Action::turn(){
    current_.print();
    prompt_player();
}
