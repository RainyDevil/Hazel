#pragma once
#include "Hazel.h"
extern Hazel::Application* Hazel::CreateApplication();

bool onResize(Hazel::Event& event)
{
	
	std::cout <<  event  << std::endl;
	return true;
}
int main(int argc, char** argv)
{
	Hazel::Log::Init();
	int a = 10;
	HZ_CORE_ERROR("This is a = {0}", a);
	HZ_CORE_INFO("Start");
	HZ_WARN("Fail");
	HZ_FATAL("Fail");
	Hazel::WindowResizeEvent resizeEvent(1920,1080);
	Hazel::EventDispatcher dispatcher(resizeEvent);
	dispatcher.Dispatcher<Hazel::WindowResizeEvent>(onResize);
	HZ_CORE_INFO("Dispatch a resize event");
	auto app = Hazel::CreateApplication(); 
	app->Run();
	delete app;
}