# Makefile ARM — poly_mult
CC      = arm-linux-gnueabihf-gcc

CFLAGS  = -O3 -static -Wall -std=c99

TARGET  = poly_mult.arm
SRC     = poly_mult.c

all: $(TARGET)

$(TARGET): $(SRC) Makefile
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET) *.o
	rm -rf m5out_* stats.txt

.PHONY: all clean
