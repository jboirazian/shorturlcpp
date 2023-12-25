CC = g++
CFLAGS = -lpthread -ljsoncpp -lcurl -I includes

all: shorturlcpp

shorturlcpp: src/main.cpp
	$(CC) $< -o $@ $(CFLAGS)

clean:
	rm -f shorturlcpp