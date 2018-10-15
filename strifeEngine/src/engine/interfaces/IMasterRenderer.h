#pragma once

namespace engine
{
	namespace interfaces
	{
		class IMasterRenderer
		{
			virtual void prepare() = 0;
			virtual void cleanUp() = 0;
		};
	}
}
