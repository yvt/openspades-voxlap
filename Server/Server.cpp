/*
 Copyright (c) 2017 yvt

 This file is part of OSVoxlap Server.
 */

#include <cstdio>
#include <cstdlib>
#include <stdexcept>

#include "Server.h"

namespace osvl {
    namespace {
        std::vector<char> g_send_buffer;

        void Flush() {
            std::fwrite(g_send_buffer.data(), 1, g_send_buffer.size(), stdout);
            g_send_buffer.resize(0);
        }
        void SendData(const char *data, std::size_t length) {
            g_send_buffer.insert(g_send_buffer.end(), data, data + length);
        }
        void SendData(const std::vector<char> &data) {
            SendData(data.data(), data.size());
        }

        void HandleLoadWorld(const std::vector<char> &payload) {

        }
        void HandleUpdateWorld(const std::vector<char> &payload) {

        }
        void HandleCreateModel(const std::vector<char> &payload) {

        }
        void HandleDestroyModel(const std::vector<char> &payload) {

        }
        void HandleFinalizeScene(const std::vector<char> &payload) {

        }
        void HandleStartScene(const std::vector<char> &payload) {

        }
        void HandleAddModelToScene(const std::vector<char> &payload) {

        }
    }

    void InitializeServer(const OSVLContextParam &param) {
        // TODO
    }

    void HandleIncomingCommand(OSVLCommand type, const std::vector<char> &payload) {
        switch (type) {
            case kOSVLCommandLoadWorld:
                HandleLoadWorld(payload);
                break;
            case kOSVLCommandUpdateWorld:
                HandleUpdateWorld(payload);
                break;
            case kOSVLCommandCreateModel:
                HandleCreateModel(payload);
                break;
            case kOSVLCommandDestroyModel:
                HandleDestroyModel(payload);
                break;
            case kOSVLCommandFinalizeScene:
                HandleFinalizeScene(payload);
                break;
            case kOSVLCommandStartScene:
                HandleStartScene(payload);
                break;
            case kOSVLCommandAddModelToScene:
                HandleAddModelToScene(payload);
                break;
            default:
                throw std::runtime_error("bad command");
        }
        // TODO
    }
}