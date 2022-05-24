#pragma once
#include "pointers.hpp"
#include "joaat.hpp"
#include "memory.hpp"
#include "memory/process.hpp"

namespace ellohim::utility
{
	inline auto getUserParamsBase() -> uintptr_t
	{
		return memory::readPointer(g_pointers->m_unreal_engine, { 0xE08, 0x2D8, 0x80, 0x0 });
	}

	inline auto getCharacterBase() -> uintptr_t
	{
		return memory::readPointer(g_pointers->m_unreal_engine, { 0xE08, 0x38, 0x0, 0x30, 0x270, 0x0 });
	}

	inline auto getCharacterStats() -> uintptr_t
	{
		return memory::readPointer(g_pointers->m_unreal_engine, { 0xE08, 0x38, 0x0, 0x30, 0x270, 0x9A8, 0x0 });
	}

	inline auto getCharacterParamsBase() -> uintptr_t
	{
		return memory::readPointer(g_pointers->m_unreal_engine, { 0xE08, 0x38, 0x0, 0x30, 0x270, 0x948, 0x0 });
	}

	inline auto getPlayerGaugeBase() -> uintptr_t
	{
		return memory::readPointer(g_pointers->m_unreal_engine, { 0xE08, 0x38, 0x0, 0x30, 0x270, 0x1198, 0x0 });
	}

	inline auto getSASStateBase() -> uintptr_t
	{
		return memory::readPointer(g_pointers->m_unreal_engine, { 0xE08, 0x38, 0x0, 0x30, 0x270, 0x1B38, 0x0 });
	}

	inline auto getBrainDriveBase() -> uintptr_t
	{
		return memory::readPointer(g_pointers->m_unreal_engine, { 0xE08, 0x38, 0x0, 0x30, 0x270, 0x1068, 0x0 });
	}

	inline auto getSASRecastBase() -> uintptr_t
	{
		return memory::readPointer(g_pointers->m_unreal_engine, { 0xE08, 0x38, 0x0, 0x30, 0x270, 0x11C0, 0xE8 });
	}

	inline auto getSASDelayBase() -> uintptr_t
	{
		return memory::readPointer(g_pointers->m_unreal_engine, { 0xE08, 0x38, 0x0, 0x30, 0x270, 0x11C0, 0x108 });
	}

	inline auto getItemUseRecastBase() -> uintptr_t
	{
		return memory::readPointer(g_pointers->m_unreal_engine, { 0xE08, 0x38, 0x0, 0x30, 0x270, 0x1170, 0xF8 });
	}

	inline auto getPlayerSkillBase() -> uintptr_t
	{
		return memory::readPointer(g_pointers->m_unreal_engine, { 0xE08, 0x38, 0x0, 0x30, 0x270, 0x11C0, 0xD8, 0x0 });
	}

	inline void set_velocity_jump(float number)
	{
		uintptr_t character_base = getCharacterBase() + 0x298;
		if (!character_base)
			return;
		auto jump_velocity = g_process->read<uintptr_t>(character_base) + 0x168;
		g_process->write(jump_velocity, number);
	}

	inline void set_player_health(int health)
	{
		uintptr_t character_base = getCharacterBase() + 0x948;
		if (!character_base)
			return;
		auto player_health = g_process->read<uintptr_t>(character_base) + 0x0;
		g_process->write(player_health, health);
	}

	inline void set_ignore_damage(bool activate)
	{
		uintptr_t character_base = getCharacterBase();
		uintptr_t base = 0x0;
		if (character_base)
			base = g_process->read<uintptr_t>(character_base + 0x998);

		if (activate)
		{
			g_process->write(character_base + 0x998, 0);
		}
		else
		{
			uintptr_t check_pointer = g_process->read<uintptr_t>(character_base + 0x998);
			if (check_pointer != 0) 
				return;
			if (base && base != 0)
				g_process->write(character_base + 0x998, base);
		}
	}

	inline void set_player_pychic(float pychic)
	{
		auto pychic_addr = getPlayerGaugeBase();

		if (!pychic_addr) 
			return;
		g_process->write(pychic_addr + 0x188, pychic);
	}

	inline void remove_sas_cooldown(bool activate)
	{
		if (activate)
		{
			auto base = getSASRecastBase();
			if (!base) return;
			auto num = g_process->read<int>(base + 0x8);
			base = g_process->read<uintptr_t>(base);
			for (int i = 0; i < num; i++) g_process->write(base + 0xC * i + 8, '\x00');
		}
	}

	inline void set_infinite_sas_duration(bool activate)
	{
		auto base = getSASStateBase();
		if (!base) return;

		g_process->write(base + 0xE0, static_cast<char>(activate));
	}

	inline void set_infinite_brain_dive(bool activate)
	{
		if (activate)
		{
			auto base = getBrainDriveBase();

			if (!base) return;
			g_process->write(base + 0x24C, 0.0f);
		}
	}

	inline void instant_brain_field(bool activate)
	{
		if (activate)
		{
			auto base = getBrainDriveBase();

			if (!base) return;

			g_process->write(base + 0x21C, 0.0f);
		}
	}

	inline void enter_brain_dive(bool activate)
	{
		auto base = getBrainDriveBase();

		if (!base) return;

		g_process->write(base + 0x1A2, activate);
	}

	inline void item_usage_no_cooldown(bool activate)
	{
		if (activate)
		{
			auto base = getItemUseRecastBase();

			if (!base) return;

			auto num = g_process->read<int>(base + 0x8);
			base = g_process->read<uintptr_t>(base);

			if (!base) return;

			for (int i = 0; i < num; i++)
			{
				g_process->write(base + 0xC * i + 0x8, '\x00');
			}
		}
	}

	inline void infinite_battle_points(bool activate)
	{
		if (activate)
			g_process->write(g_pointers->m_battle_points_handle, '\xC3');
		else
			g_process->write(g_pointers->m_battle_points_handle, '\x48');
	}

	inline void modify_player_skill(int slot, int8_t skillId)
	{
		switch (slot)
		{
		case 1:
			g_process->write(getPlayerSkillBase() + 0x2, skillId);
			break;
		case 2:
			g_process->write(getPlayerSkillBase() + 0x0, skillId);
			break;
		case 3:
			g_process->write(getPlayerSkillBase() + 0x1, skillId);
			break;
		case 4:
			g_process->write(getPlayerSkillBase() + 0x3, skillId);
			break;
		case 5:
			g_process->write(getPlayerSkillBase() + 0x6, skillId);
			break;
		case 6:
			g_process->write(getPlayerSkillBase() + 0x4, skillId);
			break;
		case 7:
			g_process->write(getPlayerSkillBase() + 0x5, skillId);
			break;
		case 8:
			g_process->write(getPlayerSkillBase() + 0x7, skillId);
			break;
		}
	}

	inline int8_t get_player_skill(int slot)
	{
		switch (slot)
		{
		case 1:
			return g_process->read<int8_t>(getPlayerSkillBase() + 0x2);
		case 2:
			return g_process->read<int8_t>(getPlayerSkillBase() + 0x0);
		case 3:
			return g_process->read<int8_t>(getPlayerSkillBase() + 0x1);
		case 4:
			return g_process->read<int8_t>(getPlayerSkillBase() + 0x3);
		case 5:
			return g_process->read<int8_t>(getPlayerSkillBase() + 0x6);
		case 6:
			return g_process->read<int8_t>(getPlayerSkillBase() + 0x4);
		case 7:
			return g_process->read<int8_t>(getPlayerSkillBase() + 0x5);
		case 8:
			return g_process->read<int8_t>(getPlayerSkillBase() + 0x7);
		}
	}

	inline int get_player_credits()
	{
		auto base = getUserParamsBase();

		if (!base) return 0;

		return g_process->read<int>(base + 0x50);
	}

	inline void set_player_credits(int credits)
	{
		auto base = getUserParamsBase();

		if (!base) return;

		g_process->write(base + 0x50, credits);
	}

	inline void infinite_player_credits(bool activate)
	{
		static const auto credits = get_player_credits();
		if (activate)
		{
			set_player_credits(credits);
		}
	}

	inline int get_player_battle_point()
	{
		auto base = getUserParamsBase();

		if (!base) return 0;

		return g_process->read<int>(base + 0x2D0);
	}

	inline void set_player_battle_point(int battlePoints)
	{
		auto base = getUserParamsBase();

		if (!base) return;

		g_process->write(base + 0x2D0, battlePoints);
	}

	inline void get_player_battle_point(bool activate)
	{
		static const auto battle_points = get_player_credits();
		if (activate)
		{
			set_player_battle_point(battle_points);
		}
	}
}