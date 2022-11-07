#include <Akari/Engine/AkariEngine.h>
#include <Akari/Engine/AkariWindow.h>
#include <Akari/Engine/AkariUtility.h>
#include <memory>
int main(int argc, const char** argv) {
	Akari::AkariEngine engine;
	AKARI_DEBUG_ASSERT(engine.Init());
	auto window = std::unique_ptr<Akari::AkariWindow>(Akari::AkariWindow::New(engine, Akari::AkariWindowDesc()
		.SetTitle("Akari-Engine-Test0")
		.SetPosition({UINT32_MAX,UINT32_MAX})
		.SetSize({800,600})
		.SetResizable(true)
		.SetVisible(true)
		.SetUserPointer(nullptr)));

	engine.Loop();
	engine.Free();
	return 0;
}