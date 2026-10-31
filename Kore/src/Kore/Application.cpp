#include "krpch.h"
#include "Application.h"

#include "Kore/Events/ApplicationEvent.h"
#include "Kore/Log.h"

namespace Kore
{
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1200, 720);
		KR_TRACE(e.ToString());		//新版fmt不支持自动把 operator<< 当作格式化，所以要加入tostring方法
		while (true);
	}

}
