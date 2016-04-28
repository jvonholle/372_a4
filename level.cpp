#include "a4.h"

#include <fstream> // for std::ifstream
#include <string> // for std::string
#include <stdexcept> // for std::runtime_error
#include <memory> // for std::shared_ptr

Level::Level()

Level::Level(const string & path){
    std::string temp_input;
    std::ifstream load(path.c_str());
    if(!load)
        throw std::runtime_error("file not found: " + path);
    load >> temp_input;
    if(temp_input != "<Description>")
        throw std::runtime_error("invalid file syntax in " + path);
    while(true){
        load >> temp_input;
        if(temp_input == "</Description>")
            break;
        description_ += temp_input;
    }
    if(temp_input != "<Next>")
        throw std::runtime_error("invalid file syntax in " + path);
    std::string temp_storage;
    while(true){
        load >> temp_input;
        temp_storage = temp_input;
        if(temp_input == "</Next>")
            break;
        load >> temp_input;
        if(temp_input == "</Next>")
             throw std::runtime_error("invalid file syntax in " + path);
        options_[temp_storage] = new Level(temp_input);
    }
}

std::shared_ptr Level::move(std::string & choice)