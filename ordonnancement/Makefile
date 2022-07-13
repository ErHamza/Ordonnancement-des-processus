all : prog

prog : main.o FCFS.o SJF.o RR.o
	g++ main.o FCFS.o SJF.o RR.o -o prog 
main.o : main.cpp
	g++ -c main.cpp
FCFS.o : FCFS.cpp FCFS.h
	g++ -c FCFS.cpp
SJF.o : SJF.cpp SJF.h
	g++ -c SJF.cpp
RR.o : RR.cpp RR.h
	g++ -c RR.cpp	