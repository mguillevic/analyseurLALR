all: Main

Main: Lexer.o Symbole.o Etat.o Automate.o Main.o
	g++ -o Main Lexer.o Symbole.o Etat.o Automate.o Main.o

Lexer.o: Lexer.cpp Lexer.h
	g++ -o Lexer.o -c Lexer.cpp

Symbole.o: Symbole.cpp Symbole.h
	g++ -o Symbole.o -c Symbole.cpp

Etat.o: Etat.cpp Etat.h
	g++ -o Etat.o -c Etat.cpp

Automate.o: Automate.cpp Automate.h
	g++ -o Automate.o -c Automate.cpp

Main.o: Main.cpp Symbole.h Lexer.h Etat.h
	g++ -o Main.o -c Main.cpp

clean:
	rm -rf *.o