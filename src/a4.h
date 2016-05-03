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
#include <fstream> // for std::ifstream
#include <vector> // for std::vector

// Class Level
//   Deals with loading and display of current scenario
//   Invariants:
//       none 
//   Used by Class Action
class Level{
public:
    // Constructors
    
    // Default Ctor
    //   Calls one param ctor with "start.map"
    //   used to start the game
    Level();
    
    // One param Ctor
    //   Stores given string in path_ to be loaded later
    Level(const std::string & path);
    
    // Accessor & Mutator Functions
    std::string get_description();
    std::map<std::string, std::map<std::string, std::shared_ptr<Level>>> get_next();
    bool is_end();
    bool is_bad();
    void set_end(bool b);
    // Member Functions
    
    // load
    //   Takes & returns nothing
    //   loads file stored at path_
    //   Will close file and throw if file cannot be found, or is not formated correctly
    //   Strong Guarantee
    void load();
    
    // move
    //   Takes a string, uses string as key in map next_
    //   returns value stored there
    std::shared_ptr<Level> move(const std::string & tag, const std::string & choice);

    // print
    //   Takes and returns nothing
    //   prints current description
    void print();
private:
    // path_
    //   holds file path, so that not all levels can be loaded when actiaved, not at init
    std::string path_;
    // description_
    //   holds string loaded from map file, describes current level
    std::string description_;
    
    // next_
    //   map of strings and pointers to new Levels
    //   loaded from map file, it what can happen next
    std::map<std::string, std::map<std::string, std::shared_ptr<Level>>> next_;

    // bad_end_
    //   is true if level loaded is a bad end eg, the player dies
    bool bad_end_ = false;
    // end_
    //   is true if level loaded is end eg, player wins or end of demo
    bool end_ = false;

    // check_tag
    //   takes an ifstream and a string
    //   ifstream is map file being read in
    //   strings in vector are tag in map file its looking for
    //   has to be formatted as follows:
    //      <TAG_NAME>
    //   it will find the matching closing tag of
    //      </TAG_NAME>
    //   will close file and throw if file is incorrectly formated
    //   Strong Guarantee
    //   CURRENTLY NOT IN USE - IFSTREAMS ARE HARD
    void check_tag(std::ifstream & load, const std::vector<std::string> & tags);
};


class Action{
public:
    // Constructors
    
    // Default Ctor
    //   Sets current level to start
    //   used to start game fresh.
    Action();
    
    // One Param Ctor
    //   Takes string
    //   loads map at given string by calling one param Level ctor
    Action(const std::string & other_than_start);
    
    // Accessor & Mutator Functions
    std::string get_input();
    std::shared_ptr<Level> get_current();
    bool is_end();
    void end();
    // Member functions
    
    // Prompt_player
    //   Takes and returns nothing
    //   Prints a message to the player, asking what they want to do,
    //   then uses std::getline() to save input to member input_
    void prompt_player();
    
    // Turn
    //   Takes a bool, based on if the last input was valid
    //   determines if it prints a prompt or a "I don't know how to XXX" message
    //   where XXX is invalid input from the player
    void turn(const bool & can_do = true);
    
    // Move_up
    //   takes two strings
    //     tag is the tag that the input corresponds to
    //     move_to is the level to use next
    void move_up(const std::string & tag, const std::string & move_to);
private:

    // input_
    //   stored input from player to handle with handler classes
    std::string input_;
    
    // current_
    //   shared pointer to the currently loaded level
    std::shared_ptr<Level> current_ = nullptr;
}; // END CLASS REQUEST


// class Handler
//   Base class for handlers, which handle specific inputs
//   Invariants:
//     none
class Handler{
public:
    // Dtor
    //   Virtual
    virtual ~Handler() {}
    
    // Handle
    //   Takes action
    //   returns bool
    //   returns true if current handler matches input in action
    //   returns next handler's handle if not
    virtual bool handle(Action & turn) = 0;
protected:

    // next_
    //   Pointer to next handler
    std::shared_ptr<Handler> next_;
}; // END CLASS HANDLER

// Handler classes
//   XX_handler
//     deals with specific inputs from player
//     last chain returns false if user input is invalid
//   All but Help & Quit handlers have their own source file
//   Quit & Help are in handler.cpp
class Help_handler : public Handler{
public:
    Help_handler();
    bool handle(Action & turn);
private:
}; // END CLASS HELP_HANDLER
class Quit_handler : public Handler{
public:
    Quit_handler();
    bool handle(Action & turn);
private:
}; // END CLASS QUIT_HANDLER
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

// ***********************
// * END HANDLER CLASSES *
// ***********************

#endif
