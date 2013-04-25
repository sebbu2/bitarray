#ifndef TESTS_HPP
#define TESTS_HPP

//#include <cstdio>
#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <unistd.h>
#include <fcntl.h>
#include <vector>
//
#include "bitarray.hpp"

#define ARG void*
#define ARG2 NULL
//#define ARG void
//#define ARG2
//#define TYPE void
#define TYPE void*
//#define RETURN 0
#define RETURN 1
typedef TYPE(*fptr)(ARG);

#endif
//
