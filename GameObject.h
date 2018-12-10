#ifndef __GameObject_h__
#define __GameObject_h__

#include "Component.h"
#include <list>

using namespace std;

enum NextPreReturn
{
	GO_NONE,
	GO_DELETED,
	GO_COPY,
	GO_CUT,
	GO_PASTE
};

class GameObject
{
public:
	GameObject(const char name[40] = "Empty");
	~GameObject();

	NextPreReturn PreUpdate();
	void Update();
	void CleanUp();
	void Delete();
	void AddComponent(Type type);

	void Draw();
	void DrawComponents();

public:

	// General info
	char name[40] = "";
	bool selected = false;
	bool enable;
	NextPreReturn nextPreReturn = GO_NONE;

	// ImGui property
	bool openNode = false;

	// Hierarchy info
	GameObject* parent;
	list<GameObject*> childs;

	// Inspector info
	list<Component*> components;

};

#endif // !__GameObject_h__