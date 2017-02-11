#pragma once

#include "OSSWRendererPlugin.h"

#ifndef __cplusplus
extern "C" {
#endif

typedef float OSVLFloat;
typedef int32_t OSVLInt;
typedef uint32_t OSVLColor;

enum { kOSVLMagicNumber = 0x11451419 };

typedef enum tagOSVLCommand {
	kOSVLCommandLoadWorld = 1,
	kOSVLCommandUpdateWorld,
	kOSVLCommandCreateModel,
	kOSVLCommandDestroyModel,
	kOSVLCommandFinalizeScene,
	kOSVLCommandStartScene,
	kOSVLCommandAddModelToScene,
} OSVLCommand;

typedef struct tagOSVLCommandHeader {
	OSVLInt command; // OSVLCommand
	OSVLInt length;  // excluding header
} OSVLCommandHeader;

typedef struct tagOSVLContextParam { OSVLInt width, height; } OSVLContextParam;

#ifndef __cplusplus
};
#endif
