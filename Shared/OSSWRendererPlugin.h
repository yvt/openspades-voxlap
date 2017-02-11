/*
 Copyright (c) 2017 yvt

 This file is in public domain.
 */
#pragma once

#include <stdint.h>

#ifndef __cplusplus
extern "C" {
#endif

typedef float OSFloat;
typedef int16_t OSInt16;
typedef int32_t OSInt32;
typedef uint32_t OSUInt32;
typedef uint64_t OSUInt64;
typedef float OSFloat;

typedef struct tagOSIntVector3 { OSInt32 x, y, z; } OSIntVector3;

typedef struct tagOSVector3 { OSFloat x, y, z; } OSVector3;

typedef struct tagOSMatrix4 { OSFloat m[16]; } OSMatrix4;

typedef struct tagOSSWRendererPluginParam {
    OSInt32 width, height;
    OSUInt32 *framebuffer;
} OSSWRendererPluginParam;

typedef struct tagOSSWRendererPluginVoxelModelData {
    OSInt16 width, height, depth;
    OSUInt64 *solidMap;
    OSUInt32 *colorMap;
} OSSWRendererPluginVoxelModelData;

typedef struct tagOSSWRendererPluginSceneParam {
    OSMatrix4 viewMatrix;
    OSFloat fovX, fovY;
    OSFloat fogMaxDistance;
    OSUInt32 fogColor;
    OSUInt32 flags;
} OSSWRendererPluginSceneParam;

typedef enum tagOSSWRendererPluginSceneFlags {
    kOSSWRendererPluginSceneFlagsSkipWorld = 1
} OSSWRendererPluginSceneFlags;

typedef struct tagOSSWRendererPluginModelInstanceParam {
    OSMatrix4 modelMatrix;
    OSUInt32 customColor;
    OSUInt32 flags;
} OSSWRendererPluginModelInstanceParam;

typedef enum tagOSSWRendererPluginModelInstanceFlags {
    kOSSWRendererPluginModelInstanceFlagsDepthHack = 1
} OSSWRendererPluginModelInstanceFlags;

typedef struct tagOSSWRendererPluginContextPrivate OSSWRendererPluginContextPrivate;

typedef struct tagOSSWRendererPluginVoxelModel OSSWRendererPluginVoxelModel;

typedef struct tagOSSWRendererPluginContext {
    OSSWRendererPluginContextPrivate *priv;
    void (*init)(OSSWRendererPluginContextPrivate *, const OSSWRendererPluginParam *);
    void (*destroy)(OSSWRendererPluginContextPrivate *);
    const char *(*checkError)(OSSWRendererPluginContextPrivate *);

    void (*loadWorld)(const OSSWRendererPluginVoxelModelData *);
    void (*updateWorld)(const OSUInt32 *commands, OSUInt32 numCommands);

    OSSWRendererPluginVoxelModel *(*createVoxelModel)(const OSSWRendererPluginVoxelModelData *);
    void (*destroyVoxelModel)(OSSWRendererPluginVoxelModel *);

    void (*startScene)(const OSSWRendererPluginSceneParam *);
    void (*finalizeScene)(void);

    void (*addModelToScene)(OSSWRendererPluginVoxelModel *,
                            const OSSWRendererPluginModelInstanceParam *);

} OSSWRendererPluginContext;

#ifndef __cplusplus
};
#endif
