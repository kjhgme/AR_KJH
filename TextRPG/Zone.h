#pragma once

#include "Object.h"
#include "Enums.h"

class UZone : public UObject
{
public:
	void InMsgPrint();
	void ZonePrint();

	bool InterConnecting(UZone* _LinkZone);
	bool Connecting(UZone* _LinkZone);
	bool IsConnecting(UZone* _LinkZone);
	void ConnectingPrint();

	UZone* ConnectingProgress();
	virtual UZone* InPlayer()
	{
		return nullptr;
	}

protected:
	inline UZone* GetZone(int _Index)
	{
		return ConnectingZones[_Index];
	}

private:
	UZone* ConnectingZones[static_cast<int>(Enums::MAXS::ZONELINKMAX)] = { nullptr, };
	int SelectMax = 0;
};