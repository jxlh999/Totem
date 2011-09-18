CXX = g++

CXXFLAGS = -O2 -g -Wall -fmessage-length=0

OBJS = File.o Object.o String.o StringBuffer.o Date.o Iterable.o Log.o

LIBS =

TARGET = totem

INCLUDE = 

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
