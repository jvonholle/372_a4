// Jimmy Von Holle
// ######### FILENAME: level.cpp
// CS 372
// Spring 2016
// Assignemnt 4
//      Chain of Responisbility source file
//      for Level class
//      Has all function definitions
//      Descriptions in header file a4.h
#include "a4.h"

#include <fstream> // for std::ifstream
#include <string> // for std::string
#include <stdexcept> // for std::runtime_error
#include <memory> // for std::shared_ptr
#include <iostream> // for std::cout

Level::Level(){
    Level("start.map");
}

Level::Level(const std::string & path){
    std::string w_path = "boards/" + path;
    std::string temp_input;
    std::ifstream load(w_path.c_str());
    if(!load)
        throw std::runtime_error("file not found: " + w_path);
    load >> temp_input;
    if(temp_input != "<Description>")
        throw std::runtime_error("invalid file syntax in " + w_path + " expected <Description> got " + temp_input);
                
    while(true){
        load >> temp_input;
        if(temp_input == "</Description>")
            break;
        description_ += temp_input;
        description_ += " ";
        if(load.bad())
            throw std::runtime_error("invalid file syntax in " + w_path + " expected </Description> but file ended. ");
            
    }
    load >> temp_input;
    if(temp_input != "<Next>")
        throw std::runtime_error("invalid file syntax in " + w_path + " expected <Next> got " + temp_input);
    std::string temp_storage;
    while(true){
        load >> temp_input;
        temp_storage = temp_input;
        if(temp_input == "</Next>")
            break;
        load >> temp_input;
       if(temp_input == "</Next>")
             throw std::runtime_error("invalid file syntax in " + w_path + " expected target file got " + temp_input);
        next_[temp_storage] = std::make_shared<Level>(temp_input);
        if(load.bad())
             throw std::runtime_error("invalid file syntax in " + w_path + " expected </Next> but file ended. ");
    }
}

std::string Level::get_description(){
    return description_;
}
std::map<std::string, std::shared_ptr<Level>> Level::get_next(){
    return next_;
}

void Level::print(){
    std::cout << description_;
}
