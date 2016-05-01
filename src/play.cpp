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
    Move_handler do_it;
    game.turn();
    while(!game.is_bad()){
        go_on = do_it.handle(game);
        if(go_on)
            game.turn();
        else{
            game.turn(go_on);
            game.turn();
        }
    }
    return 0;
}
