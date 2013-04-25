#include "tests.hpp"
#include "bitarray_test.hpp"
//tests
// #include "tests/test_*.hpp"
#include "tests/test_8.hpp"
#include "tests/test_get_lr.hpp"
#include "tests/test_default_size.hpp"
#include "tests/test_sizes.hpp"
#include "tests/test_shifts32.hpp"
#include "tests/test_shifts.hpp"
#include "tests/test_default_bit_values.hpp"
#include "tests/test_flip_bit_values.hpp"
#include "tests/test_get_set_bit_values.hpp"
#include "tests/test_push_pop.hpp"

//using namespace std;

static struct {
	fptr fpt;
	const char* funcname;
} functions[]={
	{test_8, "test_8"},
	{test_get_lr, "test_get_lr"},
	{test_default_size, "test_default_size"},
	{test_sizes, "test_sizes"},
	{test_shifts32, "test_shifts32"},
	{test_shifts, "test_shifts"},
	{test_default_bit_values, "test_default_bit_values"},
	{test_flip_bit_values, "test_flip_bit_values"},
	{test_get_set_bit_values, "test_get_set_bit_values"},
	{test_push_pop_back_0_values, "test_push_pop_back_0_values"},
	{test_push_pop_back_1_values, "test_push_pop_back_1_values"},
	{test_push_pop_front_0_values, "test_push_pop_front_0_values"},
	{test_push_pop_front_1_values, "test_push_pop_front_1_values"},
};

static const char* print_function(fptr fpt) {
	unsigned int max=sizeof(functions)/sizeof(functions[0]);
	for(unsigned int i=0;i<max;++i) {
		if(functions[i].fpt==fpt) {
			return functions[i].funcname;
		}
	}
	return "";
}

void run(unsigned int *success, unsigned int *fail, unsigned int *total, fptr fpt) {
	assert(success!=NULL);
	assert(fail!=NULL);
	assert(total!=NULL);
	assert(fpt!=NULL);
	try {
		printf("---\n");
		++(*total);
		printf("test '%s%s%s' started\n", "\x1b[1;33m", print_function(fpt), "\x1b[0m");
		(*fpt)(ARG2);
		printf("test '%s%s%s' succeeded\n", "\x1b[1;33m", print_function(fpt), "\x1b[0m");
		++(*success);
	}
	catch(const char *s) {
		printf("test '%s%s%s' failed\n", "\x1b[1;33m", print_function(fpt), "\x1b[0m");
		fprintf(stderr, "exception message : '%s'\n", s);
		++(*fail);
	}
	catch(unsigned int e) {
		printf("test '%s%s%s' failed\n", "\x1b[1;33m", print_function(fpt), "\x1b[0m");
		fprintf(stderr, "exception number : '%10d'\n", e);
		++(*fail);
	}
	catch(...) {
		printf("test '%s%s%s' failed\n", "\x1b[1;33m", print_function(fpt), "\x1b[0m");
		++(*fail);
	}
	printf("---\n");
}

int main(void) {
	printf("__FUNCTION__=%s\n", __FUNCTION__);
	printf("__func__=%s\n", __func__);
	std::vector<fptr> tests;
	for(unsigned int i=0;i<sizeof(functions)/sizeof(functions[0]);++i) {
		tests.push_back(functions[i].fpt);
	}
	//begin config
	unsigned int success=0;
	unsigned int fail=0;
	unsigned int total=0;
	unsigned int max=tests.size();
	unsigned int max_fail=0;
	//end config
	if(max_fail==0) max_fail=max;
	assert(success+fail==total);
	assert(max_fail!=0 && max_fail <= max);
	//begin tests
	printf("---\n");
	for(unsigned int i=0;i<max;++i) {
		fptr fpt=tests.at(i);
		run(&success, &fail, &total, fpt);
		if(max_fail>0 && fail>=max_fail) break;
	}
	printf("---\n");
	//end tests
	if(success==total) {
		printf("\x1b[1;32m%04d\x1b[0m succeeded tests,\n", success);
	}
	else {
		printf("%04d succeeded tests,\n", success);
	}
	if(fail>0) {
		printf("\x1b[1;31m%04d\x1b[0m failed tests,\n", fail);
	}
	else {
		printf("%04d failed tests,\n", fail);
	}
	if(total!=max) {
		printf("\x1b[1;34m%04d/%04d\x1b[0m total tests\n", total, max);
	}
	else {
		printf("%04d total tests\n", total);
	}
	//end
	assert(success+fail==total);
	return EXIT_SUCCESS;
}
//
