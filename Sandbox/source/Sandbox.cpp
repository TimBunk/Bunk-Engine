#include <Bunk.h>
#include <stdio.h>

class Sandbox : public bnk::Application
{
public:
	Sandbox();
	~Sandbox();

private:

};

Sandbox::Sandbox()
{
}

Sandbox::~Sandbox()
{
}

bnk::Application* bnk::CreateApplication() 
{
	return new Sandbox();
}