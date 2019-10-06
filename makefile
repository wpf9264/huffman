XX = g++
CC = gcc
CFLAGS = -Wall -O -g
TARGET = test

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o:%.cpp
	$(XX) $(CFLAGS) -c $< -o $@

SOURCES = $(wildcard *.c *.cpp)
OBJS = $(patsubst %.c,%.o,$(patsubst %.cpp,%.o,$(SOURCES)))

$(TARGET): $(OBJS)
	$(XX) $(OBJS) -o $(TARGET) -std=c++11

clean:
	rm -rf *.o test
