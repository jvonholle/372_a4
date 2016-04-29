// Jimmy Von Holle
// ######### FILENAME: play.cpp
// CS 372
// Spring 2016
// Assignemnt 4
//      Main game loop / main function
#include "a4.h"

int main(){
    Action game;
    Move_handler do_it;
    while(true){
        game.turn();
        if(!do_it.handle(game)){
            break;
        }
    }
    return 0;
}