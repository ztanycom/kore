#pragma once

#ifdef KR_PLATFORM_WINDOWS

extern Kore::Application* Kore::CreateApplication();

int main(int argc,char** argv)
{

	Kore::Log::Init();
	KR_CORE_WARN("warning");
	KR_INFO("Hello var={0}",5);//{0}表示后面第0个的值

	auto app = Kore::CreateApplication();
	app->Run();
	delete app;
	
}

#endif
