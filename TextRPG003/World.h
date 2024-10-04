#pragma once

class UWorld
{
public:
	void InPlayer(class UPlayer& _Player);

private:
	void PlayerNameSelect(UPlayer& _Player);
	void PlayerZonePlay(UPlayer& _Player);
};

