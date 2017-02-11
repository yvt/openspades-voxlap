cmake_minimum_required (VERSION 3.4.0)
project (OSVoxlapServer)

file(GLOB SERVER_FILES *.cpp *.h)
file(GLOB VOXLAP_FILES Voxlap/*.cpp Voxlap/*.h)
file(GLOB SHARED_FILES ../Shared/*.h)

if(MSVC)
    enable_language(ASM_NASM)
    file(GLOB VOXLAP_ASM_FILES Voxlap/*.masm)
else()
    enable_language(ASM_NASM)
    file(GLOB VOXLAP_ASM_FILES Voxlap/*.nasm)
endif()

add_executable(OSVoxlapServer ${SERVER_FILES} ${SHARED_FILES} ${VOXLAP_FILES} ${VOXLAP_ASM_FILES})
set_target_properties(OSVoxlapServer PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(OSVoxlapServer PROPERTIES OUTPUT_NAME OSVoxlapServer)
set_target_properties(OSVoxlapServer PROPERTIES CXX_STANDARD 11)

include_directories(BEFORE "..")

source_group("Server" FILES ${SERVER_FILES})
source_group("Shared" FILES ${SHARED_FILES})
source_group("Voxlap" FILES ${VOXLAP_FILES})
