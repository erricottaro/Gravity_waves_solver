#lista delle flags per la compilazione degli oggetti di RooT
FLAGS:=`root-config --libs` `root-config --cflags`
#librerie necessarie per la compilazione
LIBS=eqdiff.o funvec.o algvec.o
DEPS=eqdiff.h funvec.h algvec.h

#istruzioni per la compilazione dei file eseguibili
# $@ indica il nome del target, $^ indica la lista delle dipendenze
main: main.cpp ${LIBS}
	g++ -o $@ $^ 
# istruzione generica per creare un file oggetto
# $< indica la prima dipendenza (i. e. il file .cpp in questo caso)
%.o: %.cpp %.h ${DEPS}
	g++ -c $< 

clean:
	rm *.o *.x

#TO MODIFY