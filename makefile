all: fetch

fetch: fetch.c config.h
	gcc fetch.c -o fetch
	
install: fetch
	mkdir -p  ~/.local/bin
	mv fetch ~/.local/bin
