all: fetch

fetch: fetch.c config.h
	gcc fetch.c -o fetch
	
