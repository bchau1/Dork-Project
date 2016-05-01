resu: display.o main.o better_game.o play.o banner.o loadsave.o
	g++  display.o main.o better_game.o play.o banner.o loadsave.o -o resu -lncurses

display.o: display.cpp
	g++ -c -std=c++11 display.cpp -lncurses
main.o: main.cpp
	g++ -c -std=c++11 main.cpp -lncurses
better_game.o: better_game.cpp
	g++ -c -std=c++11 better_game.cpp -lncurses

banner.o: banner.cpp
	g++ -c -std=c++11 banner.cpp -lncurses
play.o: play.cpp
	g++ -c -std=c++11 play.cpp -lncurses
loadsave.o: loadsave.cpp
	g++ -c -std=c++11 loadsave.cpp -lncurses
run:
	./resu
clean:
	rm -f resu
	rm -f *.o
dclean:
	rm -f *.dat
