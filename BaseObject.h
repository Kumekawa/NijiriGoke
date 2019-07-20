#pragma once

class BaseObject {
protected:
	int x;
	int y;
public:
	virtual void Update() = 0;
	virtual void Draw() = 0;
};
