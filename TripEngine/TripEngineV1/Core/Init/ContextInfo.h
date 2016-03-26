#pragma once

namespace TripEngine
{
	namespace Core
	{
		struct ContextInfo
		{
			int versionMajor, versionMinor;
			bool core;

			ContextInfo()
			{
				versionMajor = 4;
				versionMinor = 5;
				core = true;
			}

			ContextInfo(int versionMajor, int versionMinor, bool core)
			{
				this->versionMajor = versionMajor;
				this->versionMinor = versionMinor;
				this->core = core;
			}
		};
	}
}