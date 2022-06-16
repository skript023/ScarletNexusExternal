#include "pointers.hpp"
#include "memory/pattern.hpp"

namespace ellohim
{
	pointers::pointers():
		m_unreal_engine(pattern("Game Engine", "48 8B 0D ? ? ? ? E8 ? ? ? ? 48 85 ? 74 ? 33 DB").add(3).rip()),
		m_battle_points_handle(pattern("Battle Points Hanlder", "48 89 ? ? ? 57 48 83 EC ? 8B FA 48 8B ? E8 ? ? ? ? 3C ? 75 ? 8B 93")),
		m_credits_handle(pattern("Credits Handler", "48 89 ? ? ? 48 89 ? ? ? 48 89 ? ? ? 57 48 83 EC ? 4C 8B ? ? ? ? ? 33 F6")),
		m_items_handle(pattern("Items Handler", "45 8D ? ? 45 89 ? ? 45 3B"))
	{
		auto m_hwnd = FindWindowA("UnrealWindow", nullptr);
		if (!m_hwnd)
			throw std::runtime_error("Failed to find the game's window.");
		g_pointers = this;
	}

	pointers::~pointers()
	{
		g_pointers = nullptr;
	}
}