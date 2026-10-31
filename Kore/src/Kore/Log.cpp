#include "krpch.h"
#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Kore {

	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;
	//静态变量的定义
	void Log::Init()//初始化
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");//设置日志格式
		s_CoreLogger = spdlog::stdout_color_mt("Kore");//创建对象
		s_CoreLogger->set_level(spdlog::level::trace);//设置日志级别

		s_ClientLogger = spdlog::stdout_color_mt("APP");
		s_ClientLogger->set_level(spdlog::level::trace);

	}
}
