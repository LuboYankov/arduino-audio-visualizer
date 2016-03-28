all: ledVisualizer

inputProcessor.o: inputProcessor.cc inputProcessor.h
matrixVisualizer.o: matrixVisualizer.cc matrixVisualizer.h
main.o: main.cc inputProcessor.h matrixVisualizer.h

ledVisualizer: main.o inputProcessor.o matrixVisualizer.o
	g++ main.o inputProcessor.o matrixVisualizer.o -o ledVisualizer
	
clean:
	rm -f *.o *.~ ledVisualizer
