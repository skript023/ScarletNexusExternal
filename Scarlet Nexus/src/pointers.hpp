#pragma once
#include "pointer.hpp"

namespace ellohim
{
	class pointers
	{
	public:
		explicit pointers();
		~pointers();
	public:
		pointer<uint64_t> m_unreal_engine;
		pointer<uint64_t> m_battle_points_handle;
		pointer<uint64_t> m_credits_handle;
		pointer<uint64_t> m_items_handle;
	};

	inline pointers* g_pointers;
}