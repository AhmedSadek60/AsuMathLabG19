all: 
	g++ main.cpp -o matrix -fpermissive -w -std=c++11 -std=c++0x -std=gnu++11

clean:
	rm -rf *o matrix