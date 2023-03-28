all:derle bagla calistir
derle:
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
	g++ -c -I "./include" ./src/YoneticiListesi.cpp -o ./lib/YoneticiListesi.o
	g++ -c -I "./include" ./src/SatirListesi.cpp -o ./lib/SatirListesi.o
	g++ -c -I "./include" ./src/Dugum.cpp -o ./lib/Dugum.o
bagla:
	g++ ./lib/main.o  ./lib/SatirListesi.o ./lib/Dugum.o ./lib/YoneticiListesi.o  -o ./bin/program
calistir:
	./bin/program
