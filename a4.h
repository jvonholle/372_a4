// Jimmy Von Holle
// CS 372
// Spring 2016
// Assignment 4 
//     Chain of Responsibilty header
//     for a simple text-adventure
#ifndef A4_H_INCLUDED
#define A4_H_INCLUDED

#include <string>
using std::string;
#include <map>
using std::map;
#include <memory>
using std::shared_ptr;

class Action{
public:
    // Constructors
    Request();
    
    // Accessor & Mutator Functions
    string get_choice() {return choice_;}
    // Member functions
    void turn();
private:
    string choice_;
}; // END CLASS REQUEST

class Handler{
public:
    Handler();
    virtual handle(Action & turn) = 0;
protected:
    shared_ptr<Handler> next_;
}; // END CLASS HANDLER


class Move_handler : public Handler{
public:
    Move_handler();
    handle(Action & turn);
private:
}; // END CLASS MOVE_HANDLER

class Look_handler : public Handler{
public:
    Look_handler();
    handle(Action & turn);
private:
}; // END CLASS LOOK_HANDLER

class Interact_handler : public Handler{
public:
    Interact_handler();
    handle(Action & turn);
private:
}; // END CLASS INTERACT_HANDLER

class Listen_handler : public Handler{
public:
    Listen_handler();
    handle(Action & turn);
private:
}; // END CLASS LISTEN_HANDLER

class Smell_handler : public Handler{
public:
    Smell_handler();
    handle(Action & turn);
private:
}; // END CLASS SMELL_HANDLER


#endif