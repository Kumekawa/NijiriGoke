#pragma once

class BaseObject {
protected:
	int x;
	int y;
	int xSize;
	int ySize;
public:
	virtual void Update() = 0;
	virtual void Draw() = 0;
};
