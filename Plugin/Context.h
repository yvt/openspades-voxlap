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
#pragma once

#include <string>

#include "OSSWRendererPlugin.h"

namespace osvlp {
	class Context {
	public:
		Context();
		~Context();

		void Initialize(const OSSWRendererPluginParam &);

		const char *GetLastError();

	private:
		std::string m_lastError;
	};
}
