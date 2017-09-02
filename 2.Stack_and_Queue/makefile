.PYHON: clear

all: gc.queue

gc_queue: gc_queue.o gc_queuec.o
	g++ -o gc_queue gc_queue.o gc_queuec.o

gc_queue.o: gc_queue.cc
	g++ -o gc_queue.o -c gc_queue.cc

gc.duiliec.o: gc.duilie.cpp
	g++ -o gc_queuec.o -c -DTESTCASE gc_queue.cpp

clear:
	rm gc_queue.o gc_queuec.o
