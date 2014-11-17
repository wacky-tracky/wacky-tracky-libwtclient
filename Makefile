default:
	mkdir -p bin
	g++ -Wall -pedantic src/* -o bin/libwtclient.so -shared -fPIC -std=c++11

install:
	sudo cp bin/libwtclient.so /usr/lib/
	sudo ldconfig

	g++ -Wall -pedantic -std=c++11 -Isrc -Lbin -lwtclient test/test_greeting.cpp -o bin/test_greeting.elf 
	g++ -Wall -pedantic -std=c++11 -Isrc -Lbin -lwtclient test/test_authenticate.cpp -o bin/test_authenticate.elf 


