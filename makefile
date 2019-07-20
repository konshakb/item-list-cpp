


CXX = g++
CXXFLAGS = -std=c++0x
//CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
LDFLAGS = -lboost_date_time

OBJS = main

SRCS = main.cpp List.cpp Item.cpp

HEADERS = List.hpp Item.hpp


#target:  dependencies
#	rule to build
#	




main:  $(SRCS) $(HEADERS)
	${CXX} ${CXXFLAGS} main.cpp Item.cpp List.cpp -o main

clean: 
	rm ${OBJS}
