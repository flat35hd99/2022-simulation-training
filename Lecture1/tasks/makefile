CPP=g++
PYTHON=python

ALL: pi.csv pi.png

pi.png: plot.py pi.csv
	python $<

pi.csv: a.out
	./$< > $@

a.out: pi.cpp
	$(CPP) -O3 $< -o $@

clean:
	rm pi.csv