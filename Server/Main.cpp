/*
 Copyright (c) 2017 yvt

 This file is part of OSVoxlap Server.
 */

#include <cstdio>

#include "Server.h"

using namespace osvl;

int main(int argc, char **argv) {
	uint32_t magic;
	if (std::fread(&magic, 4, 1, std::stdin) == 0 || magic != kOSVLMagicNumber) {
		return 1;
	}

	OSVLContextParam context_param;
	if (std::fread(&context_param, sizeof(OSVLContextParam), 1, std::stdin) == 0) {
		return 2;
	}

	InitializeServer(context_param);

	// TODO
	return 0;
}
