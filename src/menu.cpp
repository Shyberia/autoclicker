#include "menu.hpp"
#include "autoclicker.hpp"

char input_buf[512] = "1000";
bool left           = false;
bool right          = false;

void render() {
    auto flags = ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse;

    ImGui::SetNextWindowPos({ 0, 0 }, ImGuiCond_Once);
    ImGui::SetNextWindowSize({ 480, 300 }, ImGuiCond_Once);
    ImGui::Begin("bunposting rise and grind up gang ong fr", nullptr, flags);
    if(ImGui::BeginTable("top", 3)) {
        ImGui::TableNextRow();
        ImGui::TableNextColumn();
        ImGui::TableNextColumn();
        std::string text      = "Fuck";
        auto        column1_x = (ImGui::GetCursorPosX() + 160 * 0.5 - ImGui::CalcTextSize(text.c_str()).x);
        if(column1_x > ImGui::GetCursorPosX()) {
            ImGui::SetCursorPosX(column1_x);
        }
        ImGui::Text("%s", text.c_str());
        ImGui::TableNextColumn();
        ImGui::EndTable();
    }
    if(ImGui::BeginTable("middle", 2)) {
        ImGui::TableNextRow();
        ImGui::TableNextColumn();
        std::string text      = "Mouse 1";
        auto        column1_x = (ImGui::GetCursorPosX() + 160 * 0.5 - ImGui::CalcTextSize(text.c_str()).x);
        if(column1_x > ImGui::GetCursorPosX()) {
            ImGui::SetCursorPosX(column1_x + 80.0f);
        }
        ImGui::Text("%s", text.c_str());
        auto button1_x = (ImGui::GetCursorPosX() + 160 * 0.5 - 20.0f);
        if(button1_x > ImGui::GetCursorPosX()) {
            ImGui::SetCursorPosX(button1_x + 70.0f);
        }
        ImGui::Checkbox("##Mouse1", &left);
        ImGui::TableNextColumn();
        std::string text2     = "Mouse 2";
        auto        column2_x = (ImGui::GetCursorPosX() + 160 * 0.5 - ImGui::CalcTextSize(text2.c_str()).x);
        if(column2_x > ImGui::GetCursorPosX()) {
            ImGui::SetCursorPosX(column2_x + 10.0f);
        }
        ImGui::Text("%s", text2.c_str());
        auto button2_x = (ImGui::GetCursorPosX() + 160 * 0.5 - 20.0f);
        if(button2_x > ImGui::GetCursorPosX()) {
            ImGui::SetCursorPosX(button2_x);
        }
        ImGui::Checkbox("##Mouse2", &right);
        ImGui::TableNextColumn();
        ImGui::EndTable();
    }
    if(ImGui::BeginTable("top", 3)) {
        ImGui::TableNextRow();
        ImGui::TableNextColumn();
        ImGui::TableNextColumn();
        std::string text2     = "Sleep Time";
        auto        column3_x = (ImGui::GetCursorPosX() + 160 * 0.5 - ImGui::CalcTextSize(text2.c_str()).x);
        if(column3_x > ImGui::GetCursorPosX()) {
            ImGui::SetCursorPosX(column3_x + 20.0f);
        }
        ImGui::Text("%s", text2.c_str());
        auto column2_x = (ImGui::GetCursorPosX() + 160 * 0.5 - 60.0f);
        if(column2_x > ImGui::GetCursorPosX()) {
            ImGui::SetCursorPosX(column2_x + 20.0f);
        }
        ImGui::SetNextItemWidth(50.0f);
        ImGui::InputText("##Sleeptime", input_buf, 512);
        sleep_time = atoi(input_buf);

        std::string text      = "Apply";
        auto        column1_x = (ImGui::GetCursorPosX() + 160 * 0.5 - ImGui::CalcTextSize(text.c_str()).x);
        if(column1_x > ImGui::GetCursorPosX()) {
            ImGui::SetCursorPosX(column1_x - 2.0f);
        }
        ImGui::Button(text.c_str());
        ImGui::TableNextColumn();
        ImGui::EndTable();
    }
    ImGui::End();
}
