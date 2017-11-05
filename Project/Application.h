#pragma once

#include "Engine.h"

namespace Project
{
	class Application:public Engine
	{
	public:
		Application();
		~Application();

		bool init();
	};
}
