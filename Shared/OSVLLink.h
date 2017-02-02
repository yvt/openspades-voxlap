#pragma once

#include <stdint.h>

#ifndef __cplusplus
extern "C" {
#endif

typedef float OSVLFloat;
typedef int32_t OSVLInt;
typedef uint32_t OSVLColor;

enum { kOSVLMagicNumber = 0x11451419 };

typedef enum tagOSVLCommand {
	kOSVLCommandLoadWorld = 1,
	kOSVLCommandSetWorldVoxelSolid,
	kOSVLCommandSetWorldVoxelEmpty,
	kOSVLCommandCreateModel,
	kOSVLCommandDestroyModel,
	kOSVLCommandFinalizeScene,
	kOSVLCommandStartScene,
	kOSVLCommandAddModelToScene,
} OSVLCommand;

typedef struct tagOSVLIntVector3 { OSVLInt x, y, z; } OSVLIntVector3;

typedef struct tagOSVLVector3 { OSVLFloat x, y, z; } OSVLVector3;

typedef struct tagOSVLMatrix4 { OSVLFloat m[16]; } OSVLMatrix4;

typedef struct tagOSVLCommandHeader {
	OSVLInt command; // OSVLCommand
	OSVLInt length;  // excluding header
} OSVLCommandHeader;

typedef struct tagOSVLContextParam { OSVLInt width, height; } OSVLContextParam;

typedef struct tagOSVLSceneParam {
	OSVLMatrix4 viewMatrix;
	OSVLFloat fovX, fovY;
	OSVLFloat fogMaxDistance;
	OSVLColor fogColor;
} OSVLSceneParam;

typedef enum tagOSVLSceneFlags { kOSVLSceneFlagsSkipWorld = 1 } OSVLSceneFlags;

typedef struct tagOSVLModelInstanceParam {
	OSVLMatrix4 modelMatrix;
	OSVLColor customColor;
	OSVLInt flags;
} OSVLModelInstanceParam;

typedef enum tagOSVLModelInstanceFlags {
	kOSVLModelInstanceFlagsDepthHack = 1
} OSVLModelInstanceFlags;

#ifndef __cplusplus
};
#endif
