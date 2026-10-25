// Header file automatically created from a PDB.
#pragma once

struct IAIDebugRecord;

// IAIRecordable
// Header:  _unknown/IAIRecordable.h
// Include: Prey/CryAISystem/IAIRecorder.h
struct IAIRecordable
{ // Size=8 (0x8)
	enum e_AIDbgEvent
	{
		E_NONE = 0,
		E_RESET = 1,
		E_SIGNALRECIEVED = 2,
		E_SIGNALRECIEVEDAUX = 3,
		E_SIGNALEXECUTING = 4,
		E_GOALPIPESELECTED = 5,
		E_GOALPIPEINSERTED = 6,
		E_GOALPIPERESETED = 7,
		E_BEHAVIORSELECTED = 8,
		E_BEHAVIORDESTRUCTOR = 9,
		E_BEHAVIORCONSTRUCTOR = 10,
		E_ATTENTIONTARGET = 11,
		E_ATTENTIONTARGETPOS = 12,
		E_REGISTERSTIMULUS = 13,
		E_HANDLERNEVENT = 14,
		E_ACTIONSTART = 15,
		E_ACTIONSUSPEND = 16,
		E_ACTIONRESUME = 17,
		E_ACTIONEND = 18,
		E_EVENT = 19,
		E_REFPOINTPOS = 20,
		E_AGENTPOS = 21,
		E_AGENTDIR = 22,
		E_LUACOMMENT = 23,
		E_PERSONALLOG = 24,
		E_HEALTH = 25,
		E_HIT_DAMAGE = 26,
		E_DEATH = 27,
		E_SIGNALEXECUTEDWARNING = 28,
		E_PRESSUREGRAPH = 29,
		E_BOOKMARK = 30,
		E_COUNT = 31,
	};

	// IAIRecordable::RecorderEventData
	// Header:  _unknown/IAIRecordable.h
	struct RecorderEventData
	{ // Size=32 (0x20)
		const char* pString;
		Vec3 pos;
		float val;
		void* pExtraData;

	#if 0
		RecorderEventData(const char* _arg0_);
		RecorderEventData(const Vec3& _arg0_);
		RecorderEventData(float _arg0_);
	#endif
	};

	virtual ~IAIRecordable();
	virtual void RecordEvent(IAIRecordable::e_AIDbgEvent event, const IAIRecordable::RecorderEventData* pEventData) = 0;
	virtual void RecordSnapshot() = 0;
	virtual IAIDebugRecord* GetAIDebugRecord() = 0;
};

