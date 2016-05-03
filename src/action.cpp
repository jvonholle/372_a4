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
Action::Action(){
    current_ = std::make_shared<Level>(); 
    current_->load();
}

Action::Action(const std::string & other_than_start){
    current_ = std::make_shared<Level>(other_than_start);
    current_->load();
}

// *******************
// * A & M FUNCTIONS *
// *******************
std::string Action::get_input(){
    return input_;
}

std::shared_ptr<Level> Action::get_current(){
    return current_;
}

bool Action::is_bad(){
    return current_->is_bad();
}

// ********************
// * MEMBER FUNCTIONS *
// ********************
void Action::prompt_player(){
    std::cout << "What do you do? \n> ";
    std::getline(std::cin, input_);
}

void Action::turn(const bool & can_do){
    for(int i = 0; i < 100; ++i)
        std::cout << std::endl;
    if(can_do){
        current_->print();
        if(current_->is_bad()){
            std::cout <<
                           "oooooo   oooo   .oooooo.   ooooo     ooo      oooooooooo.   ooooo oooooooooooo oooooooooo."    << std::endl
                        << " `888.   .8'   d8P'  `Y8b  `888'     `8'      `888'   `Y8b  `888' `888'     `8 `888'   `Y8b"   << std::endl
                        << "  `888. .8'   888      888  888       8        888      888  888   888          888      888"  << std::endl
                        << "   `888.8'    888      888  888       8        888      888  888   888oooo8     888      888"  << std::endl
                        << "    `888'     888      888  888       8        888      888  888   888    \"     888      888" << std::endl
                        << "     888      `88b    d88'  `88.    .8'        888     d88'  888   888       o  888     d88'"  << std::endl
                        << "    o888o      `Y8bood8P'     `YbodP'         o888bood8P'   o888o o888ooooood8 o888bood8P'"    << std::endl;// ascii art from http://www.patorjk.com/software/taag/#p=display&f=Graffiti&t=Type%20Something%20
                                                                                                                      //  Looked into FIGlet, but didn't have time to compile for my system. This website does use FIGlet fonts though
                                                                             

            return;
        }
        prompt_player();
    }else{
        std::cout << std::endl 
                  << "I don't know how to " << input_ << std::endl
                  << "***********************************" << std::endl
                  << std::endl;
    }
}

void Action::move_up(const std::string & tag, const std::string & move_to){
    current_ = current_->move(tag, move_to);
    current_->load();
}
