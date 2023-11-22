CFLAGS = -std=c++11 -O3 -Wall -lm
BINDIR = ../bin

p1: p1.cpp
	g++ $(CFLAGS) $^ -o $(BINDIR)/$@

alt: p1v2.cpp
	g++ $(CFLAGS) $^ -o $(BINDIR)/$@

run:
	$(BINDIR)/p1

run_alt:
	$(BINDIR)/alt

clean:
	rm -f $(BINDIR)/p1
