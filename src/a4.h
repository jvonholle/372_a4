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
#include <memory> // for std::shared_ptr

class Level{
public:
    // Constructors
    Level();
    Level(const std::string & path);
    // Accessor & Mutator Functions
    std::string get_description();
    std::map<std::string, std::shared_ptr<Level>> get_next();
    // Member Functions
    std::shared_ptr<Level> move(std::string & choice);
    void print();
private:
    std::string description_;
    std::map<std::string, std::shared_ptr<Level>> next_;
};

class Action{
public:
    // Constructors
    Action();
    Action(Level & other_than_start);
    ~Action();
    // Accessor & Mutator Functions
    std::string get_input();
    // Member functions
    void prompt_player();
    void turn();
private:
    std::string input_;
    Level * current_ = nullptr;
}; // END CLASS REQUEST

class Handler{
public:
    Handler();
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
