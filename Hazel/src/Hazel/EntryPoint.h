#pragma once
#include "Log.h"
extern Hazel::Application* Hazel::CreateApplication();

int main(int argc, char** argv)
{
	Hazel::Log::Init();
	int a = 10;
	HZ_CORE_ERROR("This is a = {0}", a);
	HZ_CORE_INFO("Start");
	HZ_WARN("Fail");
	HZ_FATAL("Fail");
	auto app = Hazel::CreateApplication(); 
	app->Run();
	delete app;
}