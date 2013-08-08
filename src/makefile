CXX = `which gcc`
SRC = *.c
NAME = libposer.so
VER = 0.1 
# uncomment the line below to build the 32 bit version.
#ARG = '-m32'



test: build
	cd ../test/ && make clean
	cp $(NAME).$(VER) ../test/
	cd ../test/ && make && LD_PRELOAD=`pwd`/$(NAME).$(VER) ./test

build:
	$(CXX) $(ARG) -fPIC -c $(SRC)
	$(CXX) $(ARG) -shared -ldl -Wl,-soname,$(NAME).$(VER) -o $(NAME).$(VER) *.o

clean:
	rm -rf *.o *.so*

