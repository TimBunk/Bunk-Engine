#pragma once

#ifdef _WIN64

// Extern is a declaration without definition meaning that it will look for this function. Note that it has to be in file scope and without the static keyword
// https://stackoverflow.com/questions/10422034/when-to-use-extern-in-c
extern bnk::Application* bnk::CreateApplication();

int main(int argc, char** argv) {
	auto app = bnk::CreateApplication();
	app->Run();
	delete app;
}

#endif // _WIN64
