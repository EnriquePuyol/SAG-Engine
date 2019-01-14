#include "ComponentMaterial.h"
#include "Application.h"

ComponentMaterial::ComponentMaterial(GameObject* parent) : Component(parent)
{
	type = Material;

	uID = App->GenerateUUID();
}

ComponentMaterial::ComponentMaterial(unsigned material)
{
	this->material = material;

	uID = App->GenerateUUID();
}

ComponentMaterial::ComponentMaterial(ComponentMaterial * component)
{
	type = Material;
	active = component->active;
	owner = component->owner;

	uID = component->uID;
}

ComponentMaterial::~ComponentMaterial()
{
}

void ComponentMaterial::Draw(int id)
{
	ImGui::Spacing();
	ImGui::SetCursorPosX(ImGui::GetWindowWidth() / 2 - ImGui::CalcTextSize("MATERIAL").x / 2);
	ImGui::Text("MATERIAL");

	ImGui::PushID(id);
	if (!defaultMat)
	{
		ImGui::SameLine();
		ImGui::SetCursorPosX(ImGui::GetWindowWidth() - ImGui::CalcTextSize("     X     ").x / 2);
		if (ImGui::Button("X"))
		{
			Delete();
		}
	}
	ImGui::Text("ToDo: Material");

	ImGui::PopID();
}
