#include "features.hpp"
#include "utility/utility.hpp"
#include "utility/menu_settings.hpp"
#include "script.hpp"

namespace ellohim::features
{
	void run_per_tick()
	{
        if (option.infinite_psychic)
        {
            utility::set_player_pychic(1000.f);
        }

        utility::remove_sas_cooldown(option.no_sas_cooldown);
        utility::set_infinite_sas_duration(option.infinite_sas_duration);

        utility::set_infinite_brain_dive(option.infinite_brain_dive);
        utility::instant_brain_field(option.instant_brain_field);
        utility::enter_brain_dive(option.enter_brain_dive);

        utility::infinite_battle_points(option.infinite_battle_point);
        utility::item_usage_no_cooldown(option.no_items_cooldown);
        utility::infinite_player_credits(option.infinite_credits);
	}

    void script_func()
    {
        while (true)
        {
            TRY_CLAUSE
            {
                run_per_tick();
            }
            EXCEPT_CLAUSE
            script::get_current()->yield();
        }
    }
}