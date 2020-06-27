LIBS=-lsfml-graphics -lsfml-window -lsfml-system
#LIBS=-lsigil

CC=x86_64-w64-mingw32-gcc
CXX=x86_64-w64-mingw32-g++

#export PATH="/usr/x86_64-w64-mingw32/bin:$PATH"

#PATH=/usr/include/

all: thegame

main.o: main.cpp
	g++ -c "main.cpp" -o main.o

joueur.o: joueur.cpp
	g++ -c "joueur.cpp" -o joueur.o

tilemapcol.o: tilemapcol.cpp
	g++ -c "tilemapcol.cpp" -o tilemapcol.o

ghost.o: ghost.cpp
	g++ -c "ghost.cpp" -o ghost.o

pellet.o: pellet.cpp
	g++ -c "pellet.cpp" -o pellet.o

matrix.o: matrix.cpp
	g++ -c "matrix.cpp" -o matrix.o

#thegame: main.o State.o PlayState.o Object.o Player.o
thegame: main.o joueur.o tilemapcol.o ghost.o pellet.o matrix.o
	@echo "** Building the game"
	g++ -o thegame main.o joueur.o tilemapcol.o ghost.o pellet.o matrix.o $(LIBS)

game32: 
	@echo "** Building the game for Windows 32"
	i686-w64-mingw32-g++ -o game32.exe main.o joueur.o tilemapcol.o ghost.o -I/usr/include/ $(LIBS) -std=c++11 -static -lm  -m32 -static-libstdc++ -I/home/dylan/Bureau/ # -I/usr/include/ -L/usr/i686-w64-mingw32/lib -I/usr/i686-w64-mingw32/include $(LIBS)


game64: main.o joueur.o tilemapcol.o ghost.o
	@echo "** Building the game for Windows 64"
	x86_64-w64-mingw32-g++ -o game64.exe main.o joueur.o tilemapcol.o ghost.o -I/usr/include/ -lm -static -static-libstdc++ -L/usr/lib $(LIBS)

clean:
	@echo "** Removing object files and executable..."
	rm -f thegame *.o

install:
	@echo '** Installing...'
	cp thegame /usr/bin

uninstall:
	@echo '** Uninstalling...'
	rm -f /usr/bin/thegame

