OBJECTS=$(patsubst %.java,%.class,$(wildcard *.java))

all: $(OBJECTS)

%.class : %.java
	javac $<
clean:
	rm -rf *.class

