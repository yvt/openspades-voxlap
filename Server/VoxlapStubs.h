/*
 Copyright (c) 2017 yvt

 This file is part of OSVoxlap Server.
 */
#pragma once

#include <vector>

namespace osvl {
    void InitializeVoxlapStubs();

    void LoadKPLibFileBytes(const std::vector<char>&);
    void LoadKPLibFileBytes(std::vector<char>&&);
    void UnloadKPLibFile();
}