#include <iostream>
#include "flags.h"

int main(int argc, char** argv) {
	gflags::ParseCommandLineFlags(&argc, &argv, true);

	print();
	return 0;
}