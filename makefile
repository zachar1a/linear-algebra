INC_DIR = inc
SRC_DIR = src
CFLAGS = -std=c++11 -c -Wall -I $(INC_DIR)
SRCS = main.cpp 
OBJS = $(SRC_DIR)/*.o main.o

linalg:
	make sub-make
	g++ $(CFLAGS) $(SRCS)
	g++ -o main $(OBJS)
	make clean

sub-make:
	make -C $(SRC_DIR)/

clean:
	$(RM) src/*.o
	$(RM) *.o

