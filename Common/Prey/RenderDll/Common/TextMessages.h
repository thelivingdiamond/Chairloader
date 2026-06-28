// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Copyright 2001-2016 Crytek GmbH / Crytek Group. All rights reserved.

#ifndef _TEXTMESSAGES_H_
#define _TEXTMESSAGES_H_

// compact buffer to store text messages for a frame and render them each frame
// (replacement for the former PodArray<text_info_struct> m_listMessages[2], cleaner/more cache friendly,less memory,faster,typesafe)
// todo: can release memory in case this is needed
class CTextMessages
{
public:
	CTextMessages() : m_dwCurrentReadPos() {}

	class CTextMessageHeader;

	// iteration should not be started yet
	// Arguments
	//   vPos - WorldSpace position
	//   szText - must not be 0
	//   nDrawFlags - EDrawTextFlags
	void PushEntry_Text(const Vec3& vPos, const ColorB col, const float fFontSize, const int nDrawFlags, const char* szText);

	// usually called every frame
	// resets/ends iteration
	void Clear(bool posonly = false);

	// todo: improve interface
	// starts the iteration
	// Returns
	//   0 if there are no more entries
	const CTextMessageHeader* GetNextEntry();

	uint32                    ComputeSizeInMemory() const;

	//
	bool empty() const { return m_TextMessageData.empty(); }

	// -------------------------------------------------------------

	struct SText;

	class CTextMessageHeader
	{
	public:
		const SText* CastTo_Text() const { return (SText*)this; }

		uint16       GetSize() const     { return m_Size; }

	protected:       // ---------------------------------------------
		uint16 m_Size; // including attached text
	};

	// ---------------------------------------------

	struct SText : public CTextMessageHeader
	{
		void        Init(const uint32 paddedSize) { assert(paddedSize < 65535); m_Size = paddedSize; }
		const char* GetText() const               { return (char*)this + sizeof(*this); }

		Vec3   m_vPos;
		ColorB m_Color;
		float  m_fFontSize;
		uint32 m_nDrawFlags;      // EDrawTextFlags
	};

private: // ------------------------------------------------------

	// each call the former returned pointer might be invalid
	// Arguments
	//   dwBytes >0 and dividable by 4
	// Returns
	//   0 if there is not enough space
	uint8* PushData(const uint32 dwBytes);

	// ------------------------------------------------------

	std::vector<uint8> m_TextMessageData;           // consists of many 4 byte aligned STextMessageHeader+ZeroTermintedText
	uint32             m_dwCurrentReadPos;          // in bytes, !=0 interation started

	CryCriticalSection m_TextMessageLock;
};

#endif // #ifndef _TEXTMESSAGES_H_
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryMath/Cry_Color.h>
#include <_unknown/CryLockT.h>

class ICrySizer;

// CTextMessages
// Header:  CryEngine/renderdll/common/TextMessages.h
// Include: Prey/RenderDll/Common/TextMessages.h
class CTextMessages
{ // Size=72 (0x48)
public:
	// CTextMessages::CTextMessageHeader
	// Header:  CryEngine/renderdll/common/TextMessages.h
	class CTextMessageHeader
	{ // Size=2 (0x2)
	public:
		uint16_t m_Size;

	#if 0
		const CTextMessages::SText* CastTo_Text() const;
		uint16_t GetSize() const;
	#endif
	};

	// CTextMessages::SText
	// Header:  CryEngine/renderdll/common/TextMessages.h
	struct SText : public CTextMessages::CTextMessageHeader
	{ // Size=28 (0x1C)
		Vec3 m_vPos;
		ColorB m_Color;
		float m_fFontSize;
		unsigned m_nDrawFlags;

	#if 0
		void Init(const unsigned _arg0_);
		const char* GetText() const;
	#endif
	};

	std::vector<unsigned char> m_TextMessageData;
	unsigned m_dwCurrentReadPos;
	CryCriticalSection m_TextMessageLock;

	void PushEntry_Text(const Vec3& vPos, const ColorB col, const float fFontSize, const int nDrawFlags, const char* szText) { FPushEntry_Text(this, vPos, col, fFontSize, nDrawFlags, szText); }
	void Clear(bool posonly) { FClear(this, posonly); }
	const CTextMessages::CTextMessageHeader* GetNextEntry() { return FGetNextEntry(this); }

#if 0
	CTextMessages();
	unsigned ComputeSizeInMemory() const;
	bool empty() const;
	void GetMemoryUsage(ICrySizer* _arg0_) const;
	uint8_t* PushData(const unsigned _arg0_);
#endif

	static inline auto FPushEntry_Text = PreyFunction<void(CTextMessages* const _this, const Vec3& vPos, const ColorB col, const float fFontSize, const int nDrawFlags, const char* szText)>(0xFEDC90);
	static inline auto FClear = PreyFunction<void(CTextMessages* const _this, bool posonly)>(0xFEDBE0);
	static inline auto FGetNextEntry = PreyFunction<const CTextMessages::CTextMessageHeader* (CTextMessages* const _this)>(0xFEDC60);
};
#endif // !MOONCRASH
