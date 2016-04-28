// Jimmy Von Holle
// CS 372
// Spring 2016
// Assignment 4 
//     Chain of Responsibilty header for base classes
//     for a simple text-adventure
#ifndef A4_BASE_H_INCLUDED
#define A4_BASE_H_INCLUDED

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
private:
    string 
}; // END CLASS REQUEST

class Move{
    
};

class Handler{
public:
    virtual Handler() = 0;
    virtual handle(Action & turn) = 0;
    virtual handle(Move & scene) = 0;
protected:
    shared_ptr<Handler> next_;
}; // END CLASS HANDLER

#endif