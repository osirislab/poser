CXX = `which gcc`
SRC = *.c
NAME = libposer.so
VER = 0.1 



test: build
	cd ../test/ && make clean
	cp $(NAME).$(VER) ../test/
	cd ../test/ && make && LD_PRELOAD=`pwd`/$(NAME).$(VER) ./test

build:
	$(CXX) -fPIC -c $(SRC)
	$(CXX) -shared -ldl -Wl,-soname,$(NAME).$(VER) -o $(NAME).$(VER) *.o

clean:
	rm -rf *.o *.so*

