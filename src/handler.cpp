// Jimmy Von Holle
// ######### FILENAME: handler.cpp
// CS 372
// Spring 2016
// Assignemnt 4
//      Chain of Responisbility source file
//      handler base class
//      Has all function definitions
//      Descriptions in header file a4.h
#include "a4.h"

#include <sstream> // for std::istringstream
#include <iostream> // for std::cout && std::endl
#include <string> // for std::getline

Help_handler::Help_handler(){ 
    std::shared_ptr<Handler> temp = std::make_shared<Quit_handler>();
    next_ = temp;
}

bool Help_handler::handle(Action & turn){
    std::string pos;
    std::istringstream work_desc(turn.get_input());
    work_desc >> pos;
    
    if(pos == "help" || pos == "Help"){
        std::cout << "Hello, and welcome to this short demo. The actual story is not completed, so please bear that" << std::endl
                  << "in mind. However, the engine is working as intended. To take an action, all you need to do is type it in." << std::endl
                  << "the types of actions you can perform depend on the author's design. Often times they are hinted at in the description" << std::endl
                  << "however, the keywords used to complete these actions stay the same, examples of keywords you may use in a scene are:" << std::endl
                  << "walk, move, listen to, listen for, look at, inspect, pick up, smell, lick, etc. " << std::endl
                  << "Other hints and help will be offered at the author's discretion. Enjoy!" << std::endl
                  << "Press enter to continue." << std::endl;
        std::getline(std::cin, pos);
        return true;
    }else
        return next_->handle(turn);
}

Quit_handler::Quit_handler(){ 
    std::shared_ptr<Handler> temp = std::make_shared<Move_handler>();
    next_ = temp;
}

bool Quit_handler::handle(Action & turn){
    std::string pos;
    std::istringstream work_desc(turn.get_input());
    work_desc >> pos;
    
    if(pos == "quit" || pos == "exit" || pos == "Quit" || pos == "Exit"){
        for(int i = 0; i < 100; ++i)
            std::cout << "\n";
        std::cout << "Bye!" << std::endl;
        turn.end();
        return true;
    }else
        return next_->handle(turn);
}