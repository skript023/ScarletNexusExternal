#include "player_menu.h"
#include "imgui.h"
#include "bot_function.hpp"
#include "utility/utility.hpp"
#include "utility/menu_settings.hpp"

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

            ImGui::Checkbox("Inf Pychic", &option.infinite_psychic);
            ImGui::Checkbox("SAS No Cooldown", &option.no_sas_cooldown);
            ImGui::Checkbox("Inf SAS Duration", &option.infinite_sas_duration);

            ImGui::EndGroup();
            ImGui::SameLine(200);

            ImGui::BeginGroup();

            ImGui::Checkbox("Inf Brain Dive", &option.infinite_brain_dive);
            ImGui::Checkbox("Enter Brain Dive", &option.enter_brain_dive);
            ImGui::Checkbox("Inf Battle Point", &option.infinite_battle_point);

            ImGui::EndGroup();
            ImGui::SameLine(400);

            ImGui::BeginGroup();

            ImGui::Checkbox("No Item Use Cooldown", &option.no_items_cooldown);
            ImGui::Checkbox("Instant Brain Field", &option.instant_brain_field);
            ImGui::Checkbox("Infinite Credits", &option.infinite_credits);

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