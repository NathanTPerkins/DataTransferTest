all: dt

./object_files/CyRocDataTransfer.o: CyRocDataTransfer.cpp
	g++ -c CyRocDataTransfer.cpp -o ./object_files/CyRocDataTransfer.o

dt: ./object_files/CyRocDataTransfer.o main.cpp
	g++ main.cpp ./object_files/CyRocDataTransfer.o -o dt

.PHONY: clean

clean:
	rm -rf ./object_files/* dt