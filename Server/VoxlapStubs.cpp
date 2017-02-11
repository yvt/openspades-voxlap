/*
 Copyright (c) 2017 yvt

 This file is part of OSVoxlap Server.
 */

#include <stdexcept>
#include <algorithm>
#include <cstring>

#include "VoxlapStubs.h"
#include "Voxlap/kplib.h"

namespace {
    std::vector<char> g_kplib_current_file;
    std::size_t g_kplib_current_position = 0;
}

/*
 * sysmain
 */

long cputype;

void evilquit(const char *reason) {
    throw std::runtime_error(reason);
}

extern long getcputype(); // defined in winmain.cpp

/*
 * kplib
 */

int kzfilelength() {
    return static_cast<int>(g_kplib_current_file.size());
}
int kzopen(const char *) {
    g_kplib_current_position = 0;
    return 1;
}
int kzread(void *data, int num_bytes) {
    if (num_bytes < 0) {
        return 0;
    }

    auto read_bytes = std::min(g_kplib_current_file.size() - g_kplib_current_position,
        static_cast<std::size_t>(num_bytes));
    std::memcpy(data, g_kplib_current_file.data() + g_kplib_current_position, read_bytes);
    g_kplib_current_position += read_bytes;

    return static_cast<int>(read_bytes);
}
int kztell() {
    return static_cast<int>(g_kplib_current_position);
}
void kzclose() {
    // no-op
}

namespace osvl {
    void InitializeVoxlapStubs() {
        cputype = getcputype();
        // There is no longer need to check the value of cputype here.
        // How could OpenSpades be possible to even launch with 586!?
    }

    void LoadKPLibFileBytes(const std::vector<char> &data) {
        g_kplib_current_file = data;
    }

    void LoadKPLibFileBytes(std::vector<char> &&data) {
        g_kplib_current_file = data;
    }

    void UnloadKPLibFile() {
        std::vector<char> empty;
        g_kplib_current_file.swap(empty);
    }
}
