#pragma once

namespace ellohim
{
	class player_menu
	{
	public:
		static void render_player_tab();
	private:
		static void add_value();
	private:
		static inline bool infinite_psychic{ false };
		static inline bool no_sas_cooldown{ false };
		static inline bool infinite_sas_duration{ false };
		static inline bool infinite_brain_dive{ false };
		static inline bool instant_brain_field{ false };
		static inline bool infinite_battle_point{ false };
		static inline bool no_items_cooldown{ false };
		static inline bool infinite_items{ false };
		static inline bool infinite_credits{ false };

		static inline const char* const skill_list[]{ "Pyrokinesis","Sclerokinesis","Clairvoyance","Teleportation","Invisibility","Electrokinesis","Duplication","Hypervelocity","Psychokinesis","Psychokinesis","No Skill" };
		
		static inline int slot_1{};
		static inline int slot_2{};
		static inline int slot_3{};
		static inline int slot_4{};
		static inline int slot_5{};
		static inline int slot_6{};
		static inline int slot_7{};
		static inline int slot_8{};
	};
}