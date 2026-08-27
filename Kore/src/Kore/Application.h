#pragma once

#include "Core.h"

namespace Kore {
	class Kore_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//在应用中定义
	Application* CreateApplication();
}

