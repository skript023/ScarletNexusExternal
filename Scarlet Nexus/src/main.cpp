#include "renderer.hpp"
#include "Functions.h"
#include "memory/process.hpp"
#include "pointers.hpp"
#include "common.hpp"
#include "file_manager.hpp"
#include "thread_pool.hpp"
#include "fiber_pool.hpp"
#include "script_mgr.hpp"
#include "features.hpp"

//int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)

inline uint32_t find_game_id() 
{
	auto win = ellohim::functions::GetProcessId(ellohim::TargetProcess);
	if (!win) 
	{
		LOG(INFO) << "Cannot find game window";
	}

	return win;
}

int main()
{
	using namespace ellohim;

	OverlayWindow::Name = "Ellohim Scarlet Nexus";//RandomString(10).c_str();

	std::filesystem::path base_dir = std::getenv("appdata");
	base_dir /= "Ellohim Menu";

	auto file_manager_instance = std::make_unique<file_manager>(base_dir);

	auto logger_instance = std::make_unique<logger>(
		OverlayWindow::Name,
		file_manager_instance->get_project_file("./Scarlet Nexus.log"));
	
	LOG(RAW_GREEN_TO_CONSOLE) << R"kek(
  _____                _      _   _   _                  _______        _                 
 / ____|              | |    | | | \ | |                |__   __|      (_)                
| (___   ___ __ _ _ __| | ___| |_|  \| | _____  ___   _ ___| |_ __ __ _ _ _ __   ___ _ __ 
 \___ \ / __/ _` | '__| |/ _ \ __| . ` |/ _ \ \/ / | | / __| | '__/ _` | | '_ \ / _ \ '__|
 ____) | (_| (_| | |  | |  __/ |_| |\  |  __/>  <| |_| \__ \ | | | (_| | | | | |  __/ |   
|_____/ \___\__,_|_|  |_|\___|\__|_| \_|\___/_/\_,\____|___/_|_|  \__,_|_|_| |_|\___|_| 
 )kek";

	auto process_instance = std::make_unique<process>(find_game_id());
	LOG(INFO) << "Process initalized.";

	auto pointers_instance = std::make_unique<pointers>();
	LOG(INFO) << "Pointers initialized.";

	auto fiber_pool_instance = std::make_unique<fiber_pool>(10);
	LOG(INFO) << "Fiber pool initialized.";

	auto thread_pool_instance = std::make_unique<thread_pool>();
	LOG(INFO) << "Thread pool initialized.";

	auto renderer_instance = std::make_unique<renderer>();
	LOG(INFO) << "Renderer Initialized.";

	g_script_mgr.add_script(std::make_unique<script>(&features::script_func));
	LOG(INFO) << "Scripts registered.";

	while (g_running)
	{
		g_script_mgr.tick();
		if (g_process->is_running())
		{
			g_renderer->rendering();
		}
		else
		{
			g_running = false;
		}

		Sleep(0);
	}
	renderer_instance.reset();
	LOG(INFO) << "Renderer Uninitialized";

	g_script_mgr.remove_all_scripts();
	LOG(INFO) << "Scripts unregistered.";

	fiber_pool_instance.reset();
	LOG(INFO) << "Fiber pool uninitialized.";

	thread_pool_instance->destroy();
	LOG(INFO) << "Destroyed thread pool.";

	thread_pool_instance.reset();
	LOG(INFO) << "Thread pool uninitialized.";

	pointers_instance.reset();
	LOG(INFO) << "Pointers Uninitialized.";

	process_instance.reset();
	LOG(INFO) << "Process Uninitalized.";

	logger_instance.reset();
	file_manager_instance.reset();

	exit(0);
}