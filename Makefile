CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -O2
SOURCES = src/normal_distribution.cpp src/black_scholes.cpp main.cpp
OBJECTS = $(SOURCES:.cpp=.o)
TARGET = black_scholes

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean 