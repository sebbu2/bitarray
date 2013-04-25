CC=$(CXX)
CPPFLAGS=-g -O0
CFLAGS=-std=c99
CXXFLAGS=-std=c++98
LDFLAGS=
LDLIBS=
LOADLIBES=
RANLIB=ranlib

#disable built-in implicit rules
#.SUFFIXES:
#disable automatic deletion of intermediate files
.SECONDARY:
#delete output file if error occured
.DELETE_ON_ERROR:

all: bitarray_test2.exe bitarray_test.exe
bitarray_test.exe: bitarray.o bitarray_test.o tests.a
bitarray_test2.exe: bitarray.o bitarray_test2.o

tests.a: tests/test_8.o tests/test_get_lr.o tests/test_default_size.o tests/test_sizes.o tests/test_shifts32.o tests/test_shifts.o tests/test_default_bit_values.o tests/test_flip_bit_values.o tests/test_get_set_bit_values.o tests/test_push_pop.o
	$(AR) rc "$@" $^
	$(RANLIB) "$@"

%.exe: %.o
	$(CXX) $(CPPFLAGS) $(LDFLAGS) -o $@ $^ $(LDLIBS) $(LOADLIBES)

bclean:
	@-rm tests/*.o tests.a bitarray*.o bitarray_test.exe
clean:
	@-rm *.o tests/*.o
distclean: clean
	@-rm *.a *.exe
