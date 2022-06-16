#pragma once
#include <windows.h>
#include <psapi.h>
#include <tlhelp32.h>
#include <iostream>
#include <dwmapi.h>
#include <d3d9.h>
#include <time.h>
#include <vector>
#include <thread>
#include <chrono>
#include <atomic>
#include <optional>
#include <filesystem>
#include <fstream>
#include <map>
#include <vector>
#include <stack>

#include <logger.hpp>

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "dwmapi.lib")

namespace ellohim
{
	inline std::atomic_bool g_running{ true };

	constexpr inline LPCSTR m_target_process = "explorer.exe";
	inline bool m_create_console = true;

	namespace window_process
	{
		inline DWORD m_id;
		inline HANDLE m_handle;
		inline HWND m_hwnd;
		inline WNDPROC WndProc;

		inline LPCSTR m_title;
		inline LPCSTR m_class_name;
		inline LPCSTR m_path;

		struct screen_resolution
		{
			int x;//m_window_width;
			int y;//m_window_height;
		};

		struct screen_pos
		{
			int m_window_left;
			int m_window_right;
			int m_window_top;
			int m_window_botton;
		};

		inline screen_resolution m_screen_resolution{};
		inline screen_pos m_screen_pos{};
	}

	namespace overlay_window
	{
		inline WNDCLASSEX m_window_class;
		inline HWND m_hwnd;
		inline LPCSTR m_name;
	}

	namespace d3d9
	{
		inline IDirect3D9Ex* m_d3d_context = NULL;
		inline IDirect3DDevice9Ex* m_d3d_device = NULL;
		inline D3DPRESENT_PARAMETERS m_d3d_params = { NULL };
		inline MARGINS m_d3d_margin = { -1 };
		inline MSG m_d3d_message = { NULL };
	}
}