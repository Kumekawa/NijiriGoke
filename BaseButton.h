#pragma once
#include "BaseObject.h"
#include "MasterButton.h"

class BaseButton :public BaseObject ,public MasterButton{
public:
	bool GetClick();
	bool GetClickNow();
	bool GetMouseOn();
};
