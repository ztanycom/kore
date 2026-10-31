#pragma once



#include "Core.h"
#include "spdlog/spdlog.h"	
#include "spdlog/fmt/ostr.h" 

namespace Kore {
	class KORE_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }//返回应用类型
		//inline关键字让函数/变量可以定义在头文件里、被多个 cpp 包含而不报重复定义
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
		//静态变量的声明，shared_ptr是智能指针，logger是日志类型

	};
}

//引擎日志的宏定义

#define KR_CORE_TRACE(...)  ::Kore::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define KR_CORE_INFO(...)   ::Kore::Log::GetCoreLogger()->info(__VA_ARGS__)
#define KR_CORE_WARN(...)   ::Kore::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define KR_CORE_ERROR(...)  ::Kore::Log::GetCoreLogger()->error(__VA_ARGS__)
#define KR_CORE_FATAL(...)  ::Kore::Log::GetCoreLogger()->critical(__VA_ARGS__)

//应用日志的宏定义
										
#define KR_TRACE(...)		::Kore::Log::GetClientLogger()->trace(__VA_ARGS__)
#define KR_INFO(...)		::Kore::Log::GetClientLogger()->info(__VA_ARGS__)
#define KR_WARN(...)		::Kore::Log::GetClientLogger()->warn(__VA_ARGS__)
#define KR_ERROR(...)		::Kore::Log::GetClientLogger()->error(__VA_ARGS__)
#define KR_FATAL(...)		::Kore::Log::GetClientLogger()->critical(__VA_ARGS__)
