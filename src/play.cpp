// Jimmy Von Holle
// ######### FILENAME: play.cpp
// CS 372
// Spring 2016
// Assignemnt 4
//      Main game loop / main function
#include "a4.h"

int main(){
    bool go_on;
    Action game;
    Help_handler do_it;
    game.turn();
    while(!game.is_end()){
        game.turn(do_it.handle(game));
    }
    return 0;
}
