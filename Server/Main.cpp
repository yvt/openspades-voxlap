/*
 Copyright (c) 2017 yvt

 This file is part of OSVoxlap Server.
 */

#include <cstdio>

#include "Server.h"
#include "VoxlapStubs.h"

using namespace osvl;

int main(int argc, char **argv) {
	uint32_t magic;
	if (std::fread(&magic, 4, 1, stdin) == 0 || magic != kOSVLMagicNumber) {
		return 1;
	}

	OSVLContextParam context_param;
	if (std::fread(&context_param, sizeof(OSVLContextParam), 1, stdin) == 0) {
		return 2;
	}

	InitializeVoxlapStubs();

	InitializeServer(context_param);

	OSVLCommandHeader header;
	std::vector<char> buffer;

	while (true) {
		if (std::fread(&header, sizeof(OSVLCommandHeader), 1, stdin) == 0) {
			return 3;
		}

		buffer.resize(header.length);

		if (std::fread(buffer.data(), 1, buffer.size(), stdin) < buffer.size()) {
			return 3;
		}

		HandleIncomingCommand(static_cast<OSVLCommand>(header.command), buffer);
	}

	return 0;
}
