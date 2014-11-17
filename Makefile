default:
	mkdir -p bin
	g++ -Wall -pedantic src/* -o bin/libwtclient.so -shared -fPIC
