all: play

#Test
test: test.o level.o action.o look.o interact.o listen.o smell.o lick.o move.o handler.o
	g++ -std=c++11 move.o test.o level.o action.o look.o interact.o listen.o handler.o smell.o lick.o src/a4.h test/catch.hpp -o run_test

#Play
play: play.o level.o action.o look.o interact.o listen.o smell.o lick.o move.o handler.o
	g++ -std=c++11 play.o move.o level.o action.o look.o interact.o listen.o handler.o smell.o lick.o src/a4.h -o play

# *.o
play.o: src/play.cpp
	g++ -std=c++11 -c src/play.cpp

test.o: test/test.cpp
	g++ -std=c++11 -c test/test.cpp

level.o: src/level.cpp
	g++ -std=c++11 -c src/level.cpp 

action.o: src/action.cpp
	g++ -std=c++11 -c src/action.cpp

look.o: src/look.cpp
	g++ -std=c++11 -c src/look.cpp

interact.o: src/interact.cpp
	g++ -std=c++11 -c src/interact.cpp

listen.o: src/listen.cpp
	g++ -std=c++11 -c src/listen.cpp

smell.o: src/smell.cpp
	g++ -std=c++11 -c src/smell.cpp

lick.o: src/lick.cpp
	g++ -std=c++11 -c src/lick.cpp
	
move.o: src/move.cpp
	g++ -std=c++11 -c src/move.cpp
	
handler.o: src/handler.cpp
	g++ -std=c++11 -c src/handler.cpp

clean:
	rm *o play run_test
