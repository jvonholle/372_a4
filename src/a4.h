// Jimmy Von Holle
// ######### FILENAME: a4.h
// CS 372
// Spring 2016
// Assignment 4 
//     Chain of Responsibilty header
//     for a simple text-adventure
#ifndef A4_H_INCLUDED
#define A4_H_INCLUDED

#include <string> // for std::string
#include <map> // for std::map
#include <memory> // for std::shared_ptr and std::make_shared

// Class Level
//   Deals with loading and display of current scenario
//   Invariants:
//       Map files cannot backtrack, program crashes as a result of ensuing loop 
//   Used by Class Action
class Level{
public:
    // Constructors
    
    //Default Ctor
    //  Calls one param ctor with "start.map"
    //  used to start the game
    Level();
    
    //One param Ctor
    //  Loads map at given path
    //  Will close file and throw if file cannot be found, or is not formated correctly
    //  Strong Guarantee
    Level(const std::string & path);
    
    // Accessor & Mutator Functions
    std::string get_description();
    std::map<std::string, std::shared_ptr<Level>> get_next();
    bool is_bad();
    // Member Functions
    
    // move
    //   Takes a string, uses string as key in map next_
    //   returns value stored there
    std::shared_ptr<Level> move(const std::string & choice);
    
    // print
    //   Takes and returns nothing
    //   prints current description
    void print();
private:

    // description_
    //   holds string loaded from map file, describes current level
    std::string description_;
    
    // next_
    //   map of strings and pointers to new Levels
    //   loaded from map file, it what can happen next
    std::map<std::string, std::shared_ptr<Level>> next_;
    bool bad_end_ = false;
};


class Action{
public:
    // Constructors
    Action();
    Action(const std::string & other_than_start);
    // Accessor & Mutator Functions
    std::string get_input();
    std::shared_ptr<Level> get_current();
    // Member functions
    void prompt_player();
    void turn();
    void move_up(const std::string & move_to);
private:
    std::string input_;
    std::shared_ptr<Level> current_ = nullptr;
}; // END CLASS REQUEST

class Handler{
public:
    virtual ~Handler() {}
    virtual bool handle(Action & turn) = 0;
protected:
    std::shared_ptr<Handler> next_;
}; // END CLASS HANDLER


class Move_handler : public Handler{
public:
    Move_handler();
    bool handle(Action & turn);
private:
}; // END CLASS MOVE_HANDLER

class Look_handler : public Handler{
public:
    Look_handler();
    bool handle(Action & turn);
private:
}; // END CLASS LOOK_HANDLER

class Interact_handler : public Handler{
public:
    Interact_handler();
    bool handle(Action & turn);
private:
}; // END CLASS INTERACT_HANDLER

class Listen_handler : public Handler{
public:
    Listen_handler();
    bool handle(Action & turn);
private:
}; // END CLASS LISTEN_HANDLER

class Smell_handler : public Handler{
public:
    Smell_handler();
    bool handle(Action & turn);
private:
}; // END CLASS SMELL_HANDLER

class Lick_handler : public Handler{
public:
    Lick_handler();
    bool handle(Action & turn);
private:
}; // END CLASS LICK_HANDLER


#endif
