#include "player_stats.h"
#include "ImGui/imgui.h"
#include "bot_function.hpp"
#include <memory/process.hpp>
#include <utility/utility.hpp>


namespace ellohim
{
    void player_stat::add_value()
    {
        dmg_factor = g_process->read<float>(utility::getCharacterStats() + 0xC0);
        obj_dmg_factor = g_process->read<float>(utility::getCharacterStats() + 0xC4);
        fire_dmg_factor = g_process->read<float>(utility::getCharacterStats() + 0xC8);
        electric_dmg_factor = g_process->read<float>(utility::getCharacterStats() + 0xCC);
        random_factor_min = g_process->read<float>(utility::getCharacterStats() + 0xD0);
        random_factor_max = g_process->read<float>(utility::getCharacterStats() + 0xD4);
        critical_factor = g_process->read<float>(utility::getCharacterStats() + 0xD8);
        critical_crash_factor = g_process->read<float>(utility::getCharacterStats() + 0xDC);
        bad_up_factor = g_process->read<float>(utility::getCharacterStats() + 0xE0);
        bad_down_factor = g_process->read<float>(utility::getCharacterStats() + 0xE4);
        crash_factor = g_process->read<float>(utility::getCharacterStats() + 0xE8);
        armor_dmg_factor = g_process->read<float>(utility::getCharacterStats() + 0xEC);
        copy_psy_armor_factor = g_process->read<float>(utility::getCharacterStats() + 0xF0);
        psy_dmg_factor_boss = g_process->read<float>(utility::getCharacterStats() + 0xF4);
    }

    void player_stat::render_player_stat()
    {
        if (ImGui::BeginTabItem("Player Stats"))
        {
            add_value();

            if (ImGui::SliderFloat("DAMAGE FACTOR", &dmg_factor, 0.0f, 9999.f))
                g_process->write(utility::getCharacterStats() + 0xC0, dmg_factor);

            if (ImGui::SliderFloat("OBJECT DAMAGE FACTOR", &obj_dmg_factor, 0.0f, 9999.f))
                g_process->write(utility::getCharacterStats() + 0xC4, obj_dmg_factor);

            if (ImGui::SliderFloat("FIRE DAMAGE FACTOR", &fire_dmg_factor, 0.0f, 9999.f))
                g_process->write(utility::getCharacterStats() + 0xC8, fire_dmg_factor);

            if (ImGui::SliderFloat("ELECTRIC DAMAGE FACTOR", &electric_dmg_factor, 0.0f, 9999.f))
                g_process->write(utility::getCharacterStats() + 0xCC, electric_dmg_factor);

            if (ImGui::SliderFloat("RANDOM FACTOR_MIN", &random_factor_min, 0.0f, 9999.f))
                g_process->write(utility::getCharacterStats() + 0xD0, random_factor_min);

            if (ImGui::SliderFloat("RANDOM FACTOR MAX", &random_factor_max, 0.0f, 9999.f))
                g_process->write(utility::getCharacterStats() + 0xD4, random_factor_max);

            if (ImGui::SliderFloat("CRITICAL FACTOR", &critical_factor, 0.0f, 9999.f))
                g_process->write(utility::getCharacterStats() + 0xD8, critical_factor);

            if (ImGui::SliderFloat("CRITICAL CRASH FACTOR", &critical_crash_factor, 0.0f, 9999.f))
                g_process->write(utility::getCharacterStats() + 0xDC, critical_crash_factor);

            if (ImGui::SliderFloat("BAD STATE UP FACTOR", &bad_up_factor, 0.0f, 9999.f))
                g_process->write(utility::getCharacterStats() + 0xE0, bad_up_factor);

            if (ImGui::SliderFloat("BAD STATE DOWN FACTOR", &bad_down_factor, 0.0f, 9999.f))
                g_process->write(utility::getCharacterStats() + 0xE4, bad_down_factor);

            if (ImGui::SliderFloat("CRASH FACTOR", &crash_factor, 0.0f, 9999.f))
                g_process->write(utility::getCharacterStats() + 0xE8, crash_factor);

            if (ImGui::SliderFloat("ARMOR DAMAGE UP FACTOR", &armor_dmg_factor, 0.0f, 9999.f))
                g_process->write(utility::getCharacterStats() + 0xEC, armor_dmg_factor);

            if (ImGui::SliderFloat("COPY PSYCHIC ARMOR FACTOR", &copy_psy_armor_factor, 0.0f, 9999.f))
                g_process->write(utility::getCharacterStats() + 0xF0, copy_psy_armor_factor);

            if (ImGui::SliderFloat("PSYCHICFIELD DAMAGE FACTOR BOSS", &psy_dmg_factor_boss, 0.0f, 9999.f))
                g_process->write(utility::getCharacterStats() + 0xF4, psy_dmg_factor_boss);


            ImGui::EndTabItem();
        }
    }
}