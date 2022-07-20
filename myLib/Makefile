
mylib: module_a42.o
# nvc++ -shared -Minfo=acc -ta=multicore -acc  -o mylib.so  module_a42.o
# nvc++ -shared -Minfo=acc -std=c++11 -mp -acc:gpu -gpu=pinned   -o mylib.so  module_a42.o
	nvc++ -shared -Minfo=acc -std=c++11 -acc -ta=multicore  -o mylib.so  module_a42.o

module_a42.o:
#nvc++ -c -std=c++11 -mp -acc:gpu -gpu=pinned -fPIC -o module_a42.o  module_a42.cpp
	nvc++ -c -std=c++11 -acc -ta=multicore -fPIC -o module_a42.o  module_a42.cpp
#-ta=multicore -Minfo=acc

clean:
	rm -fR module_a42.o mylib.so
