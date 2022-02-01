# Used the a4 programming assignment makefile for reference

CPPFLAGS = -std=c++17 -Wall -Wextra -Werror -Wfatal-errors -Wno-sign-compare -Wnon-virtual-dtor -g

a5: Operator.o Database.o Menu.o a5.o
	g++ -o a5 Operator.o Database.o Menu.o a5.o

Operator:
	g++ -c $(CPPFLAGS) Operator.cpp

Database:
	g++ -c $(CPPFLAGS) Database.cpp

Menu:
	g++ -c $(CPPFLAGS) Menu.cpp

clean:
	rm -f a5 Operator.o Database.o Menu.o
