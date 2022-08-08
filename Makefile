
mylib: module_a42.o
	nvc++ -shared -Minfo=acc -std=c++17  -acc:gpu -gpu=managed  -Minfo=mp  -o mylib.so  module_a42.o

module_a42.o:
	nvc++ -c -std=c++17 -acc -gpu=managed -fPIC -Minfo=mp -o module_a42.o  module_a42.cpp 
	# -ta=multicore 

clean:
	rm -fR module_a42.o mylib.so
