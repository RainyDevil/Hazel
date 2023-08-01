#pragma once
#include "Core.h"
#include <memory>
namespace Hazel {
	class  HAZEL_DLL_API Application {
	public :
		Application();

		virtual ~Application();

		void Run();

	};
	Application* CreateApplication();

}