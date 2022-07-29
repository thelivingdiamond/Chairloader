// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryAction/IGameObject.h>

// Header: Override
// Prey/GameDll/ark/iface/IArkEmotionExtension.h
class IArkEmotionExtension : public IGameObjectExtension // Id=800D7C5 Size=64
{
public:
	virtual void SetEmotion(uint64_t arg0, float arg1) = 0;
	virtual void ClearEmotion(float arg0) = 0;
	virtual uint64_t GetCurrentEmotion() const = 0;
	virtual ~IArkEmotionExtension();
};

