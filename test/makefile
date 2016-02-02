TARGETS=t_ppn
CC=g++
t_ppn:t_ppn.o
	$(CC) -o t_ppn t_ppn.o
t_ppn.o:t_ppn.cpp

clean:
	@rm $(TARGETS)
	@rm *.o

run:
	./t_ppn
