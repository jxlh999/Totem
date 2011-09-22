VPATH = src/io src/lang src/util include/io include/lang include/util

CXX = g++

CXXFLAGS = -O2 -g -Wall -fmessage-length=0 -I include/io -I include/lang -I include/util

OBJS = main.o Object.o String.o

LIBS =

TARGET = main

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)
	
all: $(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
