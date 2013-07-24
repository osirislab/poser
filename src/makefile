CXX = `which gcc`
SRC = '*.c'

all:
	$(CXX) -fPIC -c $(SRC)
	$(CXX) -shared -Wl,-soname,libposer.so.1 -o libposer.so.1.0 *.o

clean:
	rm -rf *.so*

