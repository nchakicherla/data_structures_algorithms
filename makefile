CC = gcc
CFLAGS = -std=c99 -Wall -Wpedantic -luuid -Werror
OS := $(shell uname)

mkdir_bin := $(shell mkdir -p bin)
mkdir_obj := $(shell mkdir -p obj)

MAIN = 	./obj/main.o

OBJS = 	./obj/nc_array.o 				\

run: final-link
ifeq ($(OS),Darwin) 
		./bin/main.run
else 
		./bin/main.run  
endif

final-link: $(OBJS) $(MAIN)
	$(CC) $(CFLAGS) $(OBJS) $(MAIN) -o ./bin/main.run

./obj/%.o: ./src/%.c ./src/%.h
	$(CC) $(CFLAGS) -c $< -o $@

./obj/main.o: ./src/main.c
	$(CC) $(CFLAGS) -c ./src/main.c -o ./obj/main.o

clean-obj:
	trash-put ./obj/*
	
clean: clean-obj
	trash-put ./bin/*
