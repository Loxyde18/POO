COMPIL=g++  -Wall -I $(OBJCPATH) -I $(SRCPATH) -I $(INCLUDEPATH) -I $(BINPATH)
OBJCPATH = ./Obj
BINPATH = ./bin
SRCPATH = ./src
INCLUDEPATH = ./Include


all : $(BINPATH) $(OBJCPATH) $(BINPATH)/Test7

$(BINPATH):
	mkdir -p $(BINPATH)
	@echo "Création du fichier bin "

$(OBJCPATH):
	mkdir -p $(OBJCPATH)
	@echo "Création du fichier obj"


$(BINPATH)/Test7: $(SRCPATH)/Test7.cpp $(OBJCPATH)/Time.o $(OBJCPATH)/Event.o $(OBJCPATH)/Timing.o $(OBJCPATH)/Schedulable.o $(OBJCPATH)/Professor.o $(OBJCPATH)/Group.o $(OBJCPATH)/Classroom.o $(OBJCPATH)/Exception.o $(OBJCPATH)/TimeException.o $(OBJCPATH)/TimingException.o $(OBJCPATH)/XmlFileSerializerException.o 
	$(COMPIL) $(SRCPATH)/Test7.cpp $(OBJCPATH)/Event.o $(OBJCPATH)/Time.o $(OBJCPATH)/Timing.o $(OBJCPATH)/Schedulable.o $(OBJCPATH)/Professor.o $(OBJCPATH)/Classroom.o $(OBJCPATH)/Group.o $(OBJCPATH)/Exception.o $(OBJCPATH)/TimeException.o $(OBJCPATH)/TimingException.o $(OBJCPATH)/XmlFileSerializerException.o -o $(BINPATH)/Test7

$(OBJCPATH)/Event.o: $(SRCPATH)/Event.cpp $(INCLUDEPATH)/Event.h
	$(COMPIL) $(SRCPATH)/Event.cpp -c -o $(OBJCPATH)/Event.o

$(OBJCPATH)/Time.o: $(SRCPATH)/Time.cpp $(INCLUDEPATH)/Time.h
	$(COMPIL) $(SRCPATH)/Time.cpp -c -o $(OBJCPATH)/Time.o

$(OBJCPATH)/Timing.o : $(SRCPATH)/Timing.cpp $(INCLUDEPATH)/Timing.h
	$(COMPIL) $(SRCPATH)/Timing.cpp -c -o  $(OBJCPATH)/Timing.o

$(OBJCPATH)/Schedulable.o: $(SRCPATH)/Schedulable.cpp $(INCLUDEPATH)/Schedulable.h
	$(COMPIL) $(SRCPATH)/Schedulable.cpp  -c -o $(OBJCPATH)/Schedulable.o

$(OBJCPATH)/Professor.o: $(SRCPATH)/Professor.cpp $(INCLUDEPATH)/Professor.h
	$(COMPIL) $(SRCPATH)/Professor.cpp  -c -o $(OBJCPATH)/Professor.o

$(OBJCPATH)/Classroom.o: $(SRCPATH)/Classroom.cpp $(INCLUDEPATH)/Classroom.h
	$(COMPIL) $(SRCPATH)/Classroom.cpp  -c -o $(OBJCPATH)/Classroom.o	

$(OBJCPATH)/Group.o: $(SRCPATH)/Group.cpp $(INCLUDEPATH)/Group.h
	$(COMPIL) $(SRCPATH)/Group.cpp  -c -o $(OBJCPATH)/Group.o	

$(OBJCPATH)/Exception.o: $(SRCPATH)/Exception.cpp $(INCLUDEPATH)/Exception.h
	$(COMPIL) $(SRCPATH)/Exception.cpp  -c -o $(OBJCPATH)/Exception.o	

$(OBJCPATH)/TimeException.o: $(SRCPATH)/TimeException.cpp $(INCLUDEPATH)/TimeException.h
	$(COMPIL) $(SRCPATH)/TimeException.cpp  -c -o $(OBJCPATH)/TimeException.o	


$(OBJCPATH)/TimingException.o: $(SRCPATH)/TimingException.cpp $(INCLUDEPATH)/TimingException.h
	$(COMPIL) $(SRCPATH)/TimingException.cpp  -c -o $(OBJCPATH)/TimingException.o	

$(OBJCPATH)/XmlFileSerializer.o: $(SRCPATH)/XmlFileSerializer.ipp $(INCLUDEPATH)/XmlFileSerializer.hpp
	$(COMPIL) $(SRCPATH)/XmlFileSerializer.ipp -c -o $(OBJCPATH)/XmlFileSerializer.o

$(OBJCPATH)/XmlFileSerializerException.o: $(SRCPATH)/XmlFileSerializerException.cpp $(INCLUDEPATH)/XmlFileSerializerException.h
	$(COMPIL) $(SRCPATH)/XmlFileSerializerException.cpp -c -o $(OBJCPATH)/XmlFileSerializerException.o

clean:
	rm -f $(OBJCPATH)/*.o 

clobber: clean
	rm -f $(BINPATH)/Test7 *.xml