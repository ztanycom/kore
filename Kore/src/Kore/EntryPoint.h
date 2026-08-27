#pragma once

#ifdef KR_PLATFORM_WINDOWS

extern Kore::Application* Kore::CreateApplication();

int main(int argc,char** argv)
{
	auto app = Kore::CreateApplication();
	app->Run();
	delete app;
	
}

#endif
