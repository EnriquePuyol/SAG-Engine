#ifndef __ComponentTransform_h__
#define __ComponentTransform_h__

#include "Component.h"
#include "MathGeoLib.h"

class ComponentTransform : public Component
{
public:
	ComponentTransform(GameObject* parent);
	~ComponentTransform();

public:
	float3 position;
	float3 rotation;
	float3 scale;
};

#endif // !__ComponentTransform_h__