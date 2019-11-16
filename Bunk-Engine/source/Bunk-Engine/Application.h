#pragma once

#include "Core.h"

namespace bnk {

	class BNK_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined by the user
	Application* CreateApplication();

}

