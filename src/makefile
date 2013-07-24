CXX = `which gcc`
SRC = *.c
NAME = libposer.so
VER = 0.1 


all:
	$(CXX) -fPIC -c $(SRC)
	$(CXX) -shared -ldl -Wl,-soname,$(NAME).$(VER) -o $(NAME).$(VER) *.o

test: all
	cp $(NAME).$(VER) ../test/
	cd ../test/ && make && LD_PRELOAD=`pwd`/$(NAME).$(VER) ./test

clean:
	rm -rf *.o *.so*

