all: clean sattothreesat coltosat threesattocol

sattothreesat:
	g++ -Wall -Wextra main.cpp parserCNF.cpp SAT.cpp clause.cpp -o sattothreesat -std=c++11

coltosat:
	g++ -Wall -Wextra main.cpp parserCNF.cpp SAT.cpp clause.cpp -o coltosat -std=c++11

threesattocol:
	g++ -Wall -Wextra main.cpp parserCNF.cpp SAT.cpp clause.cpp -o threesattocol -std=c++11

clean: 
	rm -rf sattothreesat coltosat threesattocol *.o
