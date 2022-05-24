#pragma once

namespace ellohim
{
	class player_stat
	{
	public:
		static void render_player_stat();
    private:
        static void add_value();
	private:
        static inline float dmg_factor{};
        static inline float obj_dmg_factor{};
        static inline float fire_dmg_factor{};
        static inline float electric_dmg_factor{};
        static inline float random_factor_min{};
        static inline float random_factor_max{};
        static inline float critical_factor{};
        static inline float critical_crash_factor{};
        static inline float bad_up_factor{};
        static inline float bad_down_factor{};
        static inline float crash_factor{};
        static inline float armor_dmg_factor{};
        static inline float copy_psy_armor_factor{};
        static inline float psy_dmg_factor_boss{};
	};
}