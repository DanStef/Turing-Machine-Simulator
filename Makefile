build: task1

task1: task1.c
	gcc task1.c -O2 -o task1

run: task1
	./task1

clean: task1
	rm task1
