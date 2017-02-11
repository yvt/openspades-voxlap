/*
 Copyright (c) 2017 yvt

 This file is part of OSVoxlap Server.
 */
#pragma once

#include <vector>

#include <Shared/OSVLLink.h>

namespace osvl {
    void InitializeServer(const OSVLContextParam &);
    void HandleIncomingCommand(OSVLCommand type, const std::vector<char> &);
}