all:inheritance
inheritance: main.o refikorkun_arslan_151044063.o
	g++ -std=c++11 main.o refikorkun_arslan_151044063.o -o exe
main.o: main.cpp
	g++ -c -std=c++11 main.cpp
refikorkun_arslan_151044063.o: refikorkun_arslan_151044063.cpp
	g++ -c -std=c++11 refikorkun_arslan_151044063.cpp	
clean:
	rm*.o exe
