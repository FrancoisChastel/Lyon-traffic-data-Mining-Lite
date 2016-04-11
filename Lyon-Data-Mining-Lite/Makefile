# Written by F. Chastel and L. Cristol

COMP = g++ -O3

CLEAN = clean
RM = rm
RMFLAGS =


OBJ = SensorTree.o Sensor.o EventArchivePerDay.o EventArchivePerHour.o EventArchivePerMinute.o main.o
EXE = EXE

all : $(EXE)

$(EXE): $(OBJ)
	$(COMP) -o $(EXE) $(OBJ)

SenTree.o: SensorTree.cpp SensorTree.h BinaryTreeG/BinaryTreeG.h
	$(COMP) -c SensorTree.cpp -o SensorTreeG.o

Sens.o: Sensor.cpp Sensor.h EventArchivePerDay.h
	$(COMP) -c Sensor.cpp -o Sensor.o

EventDay.o: EventArchivePerDay.cpp EventArchivePerDay.h EventArchivePerHour.h
	$(COMP) -c EventArchivePerDay.cpp -o EventArchivePerDay.o

EventHour.o: EventArchivePerHour.cpp EventArchivePerHour.h EventArchivePerMinute.h
	$(COMP) -c BinaryTreeG/BinaryTreeG.cpp -o BinaryTreeG.o

EventMinute.o: EventArchivePerMinute.cpp EventArchivePerMinute.h config.h
	$(COMP) -c EventArchivePerMinute.cpp -o EventArchivePerMinute.o


main.o: main.cpp SensorTree.h
	$(COMP) -c main.cpp -o main.o

$(CLEAN):
	$(RM) $(RMFLAGS) $(OBJ)
