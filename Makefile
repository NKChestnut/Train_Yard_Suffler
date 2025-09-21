CXX = g++
CXXFLAGS = -std=c++11 -Wall

TARGET = TrainYardShuffler

SOURCES = main.cpp GameUI.cpp GameLogic.cpp

OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJECTS)
