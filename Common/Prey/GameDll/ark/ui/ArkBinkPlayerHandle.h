// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once

// Header: Override
// Prey/GameDll/ark/ui/ArkBinkPlayerHandle.h
struct ArkBinkPlayerHandle // Id=8001A61 Size=8
{
	enum class Constants
	{
		kInvalidHandle = 0,
	};

	unsigned m_handle;
	unsigned m_instanceId;
	
#if 0
	bool operator==(ArkBinkPlayerHandle const &arg0) const;
	bool IsValid() const;
	void Invalidate();
#endif
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

// ArkBinkPlayerHandle
// Header:  Prey/GameDll/ark/ui/ArkBinkPlayerHandle.h
struct ArkBinkPlayerHandle
{ // Size=8 (0x8)
	enum class Constants
	{
		kInvalidHandle = 0,
	};

	unsigned m_handle;
	unsigned m_instanceId;

#if 0
	ArkBinkPlayerHandle();
	bool operator==(const ArkBinkPlayerHandle& _arg0_) const;
	bool IsValid() const;
	void Invalidate();
#endif
};
#endif // !MOONCRASH
