#include "Kore.h"

class Sandbox :public Kore::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Kore::Application* Kore::CreateApplication()
{
	return new Sandbox();
}