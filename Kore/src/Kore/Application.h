#pragma once

#include "Core.h"

#include "Events/Event.h"

namespace Kore {
	class KORE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//在应用中定义
	Application* CreateApplication();
}

