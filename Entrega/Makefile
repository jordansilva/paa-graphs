#################
## BRUTE FORCE ##
#################


WORKDIR = `pwd`

CC = gcc
CXX = g++
AR = ar
LD = g++
WINDRES = windres

INC = 
CFLAGS = -Wall
RESINC = 
LIBDIR = 
LIB = 
LDFLAGS = 

INC_RELEASE = $(INC)
CFLAGS_RELEASE = $(CFLAGS) -O3 -std=c++11
RESINC_RELEASE = $(RESINC)
RCFLAGS_RELEASE = $(RCFLAGS)
LIBDIR_RELEASE = $(LIBDIR)
LIB_RELEASE = $(LIB)
LDFLAGS_RELEASE = $(LDFLAGS)
OBJDIR_RELEASE = puzzle/obj
OUTDIR_RELEASE = puzzle/bin
DEP_RELEASE = 
OUT_RELEASE = $(OUTDIR_RELEASE)/puzzle

OBJ_RELEASE = $(OBJDIR_RELEASE)/main.o $(OBJDIR_RELEASE)/src/domain/Node.o $(OBJDIR_RELEASE)/src/helper/Settings.o $(OBJDIR_RELEASE)/src/helper/NodeHelper.o $(OBJDIR_RELEASE)/src/algorithms/AStar.o $(OBJDIR_RELEASE)/src/algorithms/Heuristic.o $(OBJDIR_RELEASE)/src/algorithms/LinearConflict.o $(OBJDIR_RELEASE)/src/algorithms/Manhattan.o $(OBJDIR_RELEASE)/src/algorithms/MisplacedTiles.o

all: release

clean: clean_release

before_release: 
	test -d $(OUTDIR_RELEASE) || mkdir -p $(OUTDIR_RELEASE)
	test -d $(OBJDIR_RELEASE) || mkdir -p $(OBJDIR_RELEASE)
	test -d $(OBJDIR_RELEASE)/src || mkdir -p $(OBJDIR_RELEASE)/src
	test -d $(OBJDIR_RELEASE)/src/algorithms || mkdir -p $(OBJDIR_RELEASE)/src/algorithms
	test -d $(OBJDIR_RELEASE)/src/helper || mkdir -p $(OBJDIR_RELEASE)/src/helper
	test -d $(OBJDIR_RELEASE)/src/domain || mkdir -p $(OBJDIR_RELEASE)/src/domain

after_release: 

release: before_release out_release after_release

out_release: before_release $(OBJ_RELEASE) $(DEP_RELEASE)
	$(LD) $(LIBDIR_RELEASE) -o $(OUT_RELEASE) $(OBJ_RELEASE)  $(LDFLAGS_RELEASE) $(LIB_RELEASE)

#HELPER
$(OBJDIR_RELEASE)/src/helper/Settings.o: puzzle/src/helper/Settings.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c puzzle/src/helper/Settings.cpp -o $(OBJDIR_RELEASE)/src/helper/Settings.o

$(OBJDIR_RELEASE)/src/helper/NodeHelper.o: puzzle/src/helper/NodeHelper.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c puzzle/src/helper/NodeHelper.cpp -o $(OBJDIR_RELEASE)/src/helper/NodeHelper.o

#DOMAIN
$(OBJDIR_RELEASE)/src/domain/Node.o: puzzle/src/domain/Node.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c puzzle/src/domain/Node.cpp -o $(OBJDIR_RELEASE)/src/domain/Node.o

#ALGORITHMS
$(OBJDIR_RELEASE)/src/algorithms/Heuristic.o: puzzle/src/algorithms/Heuristic.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c puzzle/src/algorithms/Heuristic.cpp -o $(OBJDIR_RELEASE)/src/algorithms/Heuristic.o

$(OBJDIR_RELEASE)/src/algorithms/LinearConflict.o: puzzle/src/algorithms/LinearConflict.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c puzzle/src/algorithms/LinearConflict.cpp -o $(OBJDIR_RELEASE)/src/algorithms/LinearConflict.o

$(OBJDIR_RELEASE)/src/algorithms/Manhattan.o: puzzle/src/algorithms/Manhattan.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c puzzle/src/algorithms/Manhattan.cpp -o $(OBJDIR_RELEASE)/src/algorithms/Manhattan.o

$(OBJDIR_RELEASE)/src/algorithms/MisplacedTiles.o: puzzle/src/algorithms/MisplacedTiles.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c puzzle/src/algorithms/MisplacedTiles.cpp -o $(OBJDIR_RELEASE)/src/algorithms/MisplacedTiles.o

$(OBJDIR_RELEASE)/src/algorithms/AStar.o: puzzle/src/algorithms/AStar.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c puzzle/src/algorithms/AStar.cpp -o $(OBJDIR_RELEASE)/src/algorithms/AStar.o

$(OBJDIR_RELEASE)/main.o: puzzle/main.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c puzzle/main.cpp -o $(OBJDIR_RELEASE)/main.o

clean_release: 
	rm -f $(OBJ_RELEASE) $(OUT_RELEASE)
	rm -rf $(OUTDIR_RELEASE)
	rm -rf $(OBJDIR_RELEASE)

.PHONY: before_release after_release clean_release

