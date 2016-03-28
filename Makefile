all: ledVisualizer

inputProcessor.o: inputProcessor.cc inputProcessor.h
main.o: main.cc inputProcessor.h

ledVisualizer: main.o inputProcessor.o
	g++ main.o inputProcessor.o -o ledVisualizer
	
clean:
	rm -f *.o *.~ ledVisualizer
