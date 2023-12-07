CFLAGS = -std=c++11 -O3 -Wall -lm

p1: p1.cpp
	g++ $(CFLAGS) $^ -o p1

clean:
	rm -f $(BINDIR)/p1
