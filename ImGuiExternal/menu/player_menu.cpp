#include "player_menu.h"
#include "ImGui/imgui.h"
#include "bot_function.hpp"
#include "utility/utility.hpp"

namespace ellohim
{
    void player_menu::add_value()
    {
        slot_1 = utility::get_player_skill(1);
        slot_2 = utility::get_player_skill(2);
        slot_3 = utility::get_player_skill(3);
        slot_4 = utility::get_player_skill(4);
        slot_5 = utility::get_player_skill(5);
        slot_6 = utility::get_player_skill(6);
        slot_7 = utility::get_player_skill(7);
        slot_8 = utility::get_player_skill(8);
    }

    void player_menu::render_player_tab()
    {
        if (ImGui::BeginTabItem("Player Option"))
        {
            add_value();
            auto end = std::chrono::system_clock::now();
            std::time_t date = std::chrono::system_clock::to_time_t(end);

            ImGui::Text("%s", std::ctime(&date));

            ImGui::BeginGroup();

            ImGui::Checkbox("Inf Pychic", &infinite_psychic);
            if (infinite_psychic)
            {
                utility::set_player_pychic(1000.f);
            }

            ImGui::Checkbox("SAS No Cooldown", &no_sas_cooldown);
            if (no_sas_cooldown)
                utility::remove_sas_cooldown(no_sas_cooldown);

            if (ImGui::Checkbox("Inf SAS Duration", &infinite_sas_duration))
                utility::set_infinite_sas_duration(infinite_sas_duration);

            ImGui::EndGroup();
            ImGui::SameLine(200);

            ImGui::BeginGroup();

            ImGui::Checkbox("Inf Brain Dive", &infinite_brain_dive);
            if (infinite_brain_dive) utility::set_infinite_brain_dive(infinite_brain_dive);

            ImGui::Checkbox("Instant Brain Field", &instant_brain_field);
            if (instant_brain_field) utility::instant_brain_field(instant_brain_field);

            ImGui::Checkbox("Inf Battle Point", &infinite_battle_point);


            ImGui::EndGroup();
            ImGui::SameLine(400);

            ImGui::BeginGroup();

            if (ImGui::Checkbox("No Item Use Cooldown", &no_items_cooldown))
                utility::item_usage_no_cooldown(no_items_cooldown);

            ImGui::Checkbox("Inf Items", &infinite_items);

            ImGui::Checkbox("Infinite Credits", &infinite_credits);

            ImGui::EndGroup();

            if (ImGui::Combo("Skill Slot 1", &slot_1, skill_list, IM_ARRAYSIZE(skill_list)))
                utility::modify_player_skill(1, slot_1);

            if (ImGui::Combo("Skill Slot 2", &slot_2, skill_list, IM_ARRAYSIZE(skill_list)))
                utility::modify_player_skill(2, slot_2);

            if (ImGui::Combo("Skill Slot 3", &slot_3, skill_list, IM_ARRAYSIZE(skill_list)))
                utility::modify_player_skill(3, slot_3);

            if (ImGui::Combo("Skill Slot 4", &slot_4, skill_list, IM_ARRAYSIZE(skill_list)))
                utility::modify_player_skill(4, slot_4);

            if (ImGui::Combo("Skill Slot 5", &slot_5, skill_list, IM_ARRAYSIZE(skill_list)))
                utility::modify_player_skill(5, slot_5);

            if (ImGui::Combo("Skill Slot 6", &slot_6, skill_list, IM_ARRAYSIZE(skill_list)))
                utility::modify_player_skill(6, slot_6);

            if (ImGui::Combo("Skill Slot 7", &slot_7, skill_list, IM_ARRAYSIZE(skill_list)))
                utility::modify_player_skill(7, slot_7);

            if (ImGui::Combo("Skill Slot 8", &slot_8, skill_list, IM_ARRAYSIZE(skill_list)))
                utility::modify_player_skill(8, slot_8);

            ImGui::EndTabItem();
        }
    }
}