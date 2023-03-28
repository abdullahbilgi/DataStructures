all:derle bagla calistir
derle:
	g++ -c -I "./include" ./src/TestProgrami.cpp -o ./lib/TestProgrami.o
	g++ -c -I "./include" ./src/Queue.cpp -o ./lib/Queue.o
	g++ -c -I "./include" ./src/Radix.cpp -o ./lib/Radix.o
	g++ -c -I "./include" ./src/Organizma.cpp -o ./lib/Organizma.o
	g++ -c -I "./include" ./src/Organ.cpp -o ./lib/Organ.o
	g++ -c -I "./include" ./src/Doku.cpp -o ./lib/Doku.o
	g++ -c -I "./include" ./src/Hucre.cpp -o ./lib/Hucre.o
	g++ -c -I "./include" ./src/Kontrol.cpp -o ./lib/Kontrol.o



bagla:
	g++ ./lib/TestProgrami.o ./lib/Queue.o ./lib/Radix.o ./lib/Organizma.o ./lib/Kontrol.o ./lib/Organ.o ./lib/Doku.o ./lib/Hucre.o -o ./bin/program
calistir:
	./bin/program
