default: libfoo.so
	$(CXX) main.cpp -lelf

libfoo.so:
	$(CXX) -c -fPIC foo.cpp -o foo.o
	$(CXX) -shared foo.o -o libfoo.so
	strip libfoo.so

clean:
	rm -f a.out foo.o libfoo.so
