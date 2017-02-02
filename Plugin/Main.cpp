/*
 Copyright (c) 2017 yvt

 This file is part of OSVoxlap.

 OSVoxlap is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 OSVoxlap is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with OSVoxlap.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <memory>

#include "Context.h"
#include "OSSWRendererPlugin.h"

#ifdef __APPLE__
#define OPVL_EXPORT __attribute__((visibility("default")))
#else
#define OPVL_EXPORT __declspec(dllexport)
#endif

struct tagOSSWRendererPluginContextPrivate {
	std::shared_ptr<osvlp::Context> context;
};

using OSSWContextPrivate = OSSWRendererPluginContextPrivate;

extern "C" OPVL_EXPORT const char *
OSSWRendererPluginInitialize(uint32_t version, OSSWRendererPluginContext *context) {
	if (verison != 1) {
		return "Unsupported interface version.";
	}

	context->priv = new OSSWContextPrivate();
	context->init = [](OSSWContextPrivate *priv, const OSSWRendererPluginParam *param) {
		priv->context.reset(new osvlp::Context{});
		priv->context->Initialize(*param);
	};
	context->destroy = [](OSSWContextPrivate *priv) { delete priv; };
	context->checkError = [](OSSWContextPrivate *priv) -> const char * {
		return priv->context->GetLastError();
	};

	return nullptr;
}
