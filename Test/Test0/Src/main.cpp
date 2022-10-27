#include <iostream>
#include <TestLib/TestWindowManager.h>
#include <TestLib/TestWindow.h>
#include <cassert>
static void ResizeCallback(TestLib::TestWindow* window, int wid, int hei)
{
	if (!window) { 
		std::cerr << "error" << std::endl;
		return;
	}
	std::cerr << "[" << wid << "," << hei << "]\n";
}
static void CursorCallback(TestLib::TestWindow* window, double x, double y)
{
	if (!window) {
		std::cerr << "error" << std::endl;
		return;
	}
	std::cerr << "[" << x << "," << y << "]\n";
}
int main(int argc, const char* argv[])
{
	TestLib::TestWindow::Manager().Init();
	auto window  = TestLib::TestWindow(800, 600, "title");
	window.SetPosition({ 400,400 });
	window.Init();
	auto window2 = TestLib::TestWindow(800, 600, "title");
	window2.SetPosition({ 100,200 });
	window2.Init();
	window.SetSizeCallback(ResizeCallback);
	window.SetCursorPosCallback(CursorCallback);
	window.SetResizable(true);
	window.Show();
	window2.Show();

	bool shouldClose = false;
	while (!shouldClose) {
		TestLib::TestWindow::Manager().Update();
		if (window.ShouldClose() && window2.ShouldClose()) {
			shouldClose = true;
		}
		else if (window .ShouldClose()) {
			window.Hide();
		}
		else if (window2.ShouldClose()) {
			window2.Hide();
		}
	}
	
	window2.Hide();
	window2.Free();
	window.Hide();
	window.Free();
	TestLib::TestWindow::Manager().Free();
}