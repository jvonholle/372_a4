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
#include <cstdlib> // for std::system
#include <vector> // for std::vector

// DEBUG INCLUDES
     using std::cout;
     using std::endl;
// END DEBUG

// ****************
// * CONSTRUCTORS *
// ****************
Level::Level() : Level("start.map")
    {}
    
Level::Level(const std::string & path)
    { path_ = path; }

void Level::load(){
    std::vector<std::string> tags = {"<Move>", "<Look>", "<Listen>", "<Interact>", "<Lick>", "<Smell>"};
    std::string w_path = "boards/" + path_;
    std::string temp_input;
    std::ifstream load(w_path.c_str());
    if(!load){
        load.close();
        throw std::runtime_error("file not found: " + w_path);
    }
        
    load >> temp_input;
    if(temp_input != "<Description>"){
        load.close();
        throw std::runtime_error("invalid file syntax in " + w_path + " expected <Description> got " + temp_input);
    }
    int temp_count = 0;
    while(true){
        load >> temp_input;
        if(temp_input == "</Description>")
            break;
        description_ += temp_input;
        description_ += " ";
        if(temp_count >= 20){
            temp_count = 0;
            description_+= "\n";
        }
        if(load.bad()){
            load.close();
            throw std::runtime_error("invalid file syntax in " + w_path + " expected </Description> but file ended. ");
        }
        temp_count++;    
    }
    load >> temp_input;
    if(temp_input != "<Next>"){
        load.close();
        throw std::runtime_error("invalid file syntax in " + w_path + " expected <Next> got " + temp_input);
    }
       
    std::string end_tag = "</"; 
    std::string temp_storage;
    while(true){
        load >> temp_input;
        temp_storage = temp_input;
        if(temp_input == "<Dead></Dead>"){
            bad_end_ = true;
            break;
        }
        if(temp_input == "</Next>")
            break;
        for(auto i : tags){
            if(i == temp_input){
                    end_tag = "</";
                for(int j = 1; j < i.size(); ++j)
                    end_tag += i[j];
                while(true){
                    load >> temp_input;
                    if(temp_input == end_tag)
                        break;
                    temp_storage = temp_input;
                    load >> temp_input;
                    if(temp_input == "</Next>")
                        throw std::runtime_error("invalid file syntax in " + w_path + " expected "+end_tag +" but got </Next>. ");
                    if(load.bad()){
                        throw std::runtime_error("invalid file syntax in " + w_path + " expected </Next> but file ended. ");
                    }
                    next_[i][temp_storage] = std::make_shared<Level>(temp_input);
            }
        }
    } 
    /*    try{
            check_tag(load, tags);
        }catch( ... ){
             throw std::runtime_error("invalid file syntax in " + w_path + " while checking tags.");
        }*/
        if(load.bad()){
             throw std::runtime_error("invalid file syntax in " + w_path + " expected </Next> but file ended. ");
        }
    }
    load.close();
}

// *******************
// * A & M FUNCTIONS *
// *******************
std::string Level::get_description(){
    return description_;
}
std::map<std::string, std::map<std::string, std::shared_ptr<Level>>> Level::get_next(){
    return next_;
}

bool Level::is_bad(){
    return bad_end_;
}

// ********************
// * MEMBER FUNCTIONS *
// ********************
std::shared_ptr<Level> Level::move(const std::string & tag, const std::string & choice){
    return next_[tag][choice];
}

void Level::print(){
    std::cout << description_ << std::endl;
}

void Level::check_tag(std::ifstream & load, const std::vector<std::string> & tag){
    std::string end_tag = "</";
    std::string temp_input;
    std::string temp_storage;

    load >> temp_input;

    cout << temp_input << endl;

    for(auto i : tag){
        if(temp_input == "</Next>")
            return;
        if(i == temp_input){
            for(int j = 1; j < i.size(); ++j)
                end_tag += i[j];
            while(true){
                load >> temp_input;
                temp_storage = temp_input;
                load >> temp_input;
                if(temp_input == end_tag)
                    return;
                if(temp_input == "</Next>")
                    throw;
                if(load.bad())
                    throw;

                next_[i][temp_storage] = std::make_shared<Level>(temp_input);
            }
        }
    } 

}
