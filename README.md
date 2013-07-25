  			  -= [Introduction] =-

This is an interposition library. It is designed for use in help with 
binary debugging. 


--| Building |-----------------------------------------------------------------
After the sources have been obtained, cd into the main directory "poser".
From there run "make". This will create the library in test/libposer*.
Running make will also cause the test app to be built and a smoke test
to be run.

--| Usage |--------------------------------------------------------------------
Basic usage is as follows:

LD_PRELOAD=/path/to/my/shlib/libposer.so.0.1 ./your-binary

For example if the library were installed into /opt and we wanted to run 
it on /bin/ls:

:~/LD_PRELOAD=/opt/libposer.so.0.1 /bin/ls
0x118e040 = malloc(size = 568)
0x118e280 = malloc(size = 120)
0x118e040 = malloc(size = 5)
...

--| Development |--------------------------------------------------------------
Adding API function calls to poser is simple: 

Step 1: obtain the function header signature from either a manpage or
a header file.

Step 2: create a function stub with the same header.

Step 3: create a passthrough by calling dlsym(RTLD_NEXT, <name of function>);

At this point you can either return the value from the original function
or you can return a seperate value. For examples of the latter see the
poser/src/antidebug.c sources.
