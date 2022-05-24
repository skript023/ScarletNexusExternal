#include "bot_function.hpp"
#include "player_inventory.h"
#include "imgui.h"
#include "utility/utility.hpp"

namespace ellohim
{
	void player_inventory::render_player_inventory()
	{
        if (ImGui::BeginTabItem("Player Inventory"))
        {
            ImGui::Text("Your Credits : %d", utility::get_player_credits());
            ImGui::Text("Your Battle Points : %d", utility::get_player_battle_point());

            ImGui::InputInt("Put Your Credits", &credits);
            if (ImGui::Button("Add Credits"))
            {
                utility::set_player_credits(credits);
            }

            ImGui::InputInt("Put Your Battle Points", &battle_points);
            if (ImGui::Button("Add Battle Points"))
            {
                utility::set_player_battle_point(battle_points);
            }

            ImGui::EndTabItem();
        }
	}
}