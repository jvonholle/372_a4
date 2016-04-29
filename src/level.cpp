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

Level::Level(){
    Level("start.map");
}

Level::Level(const string & path){
    std::string w_path = "boards/" + path;
    std::string temp_input;
    std::ifstream load(w_path.c_str());
    if(!load)
        throw std::runtime_error("file not found: " + w_path);
    load >> temp_input;
    if(temp_input != "<Description>")
        throw std::runtime_error("invalid file syntax in " + w_path);
    while(true){
        load >> temp_input;
        if(temp_input == "</Description>")
            break;
        description_ += temp_input;
    }
    if(temp_input != "<Next>")
        throw std::runtime_error("invalid file syntax in " + w_path);
    std::string temp_storage;
    while(true){
        load >> temp_input;
        temp_storage = temp_input;
        if(temp_input == "</Next>")
            break;
        load >> temp_input;
        if(temp_input == "</Next>")
             throw std::runtime_error("invalid file syntax in " + w_path);
        options_[temp_storage] = new Level(temp_input);
    }
}

std::shared_ptr Level::move(std::string & choice){
    std::shared_ptr<int> place_holder = new int 0;
    return place_holder;
}
