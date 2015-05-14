OBJECTS=$(patsubst %.c,%.o,$(wildcard *.c))

all: $(OBJECTS)

%.o : %.c
	gcc -std=c11 $< -o $@
clean:
	rm -rf *.o
