#pragma once
#include <Prey/CryCore/smartptr.h>
#include <Prey/CryNetwork/ISerialize.h>

#define NUM_ASPECTS 32

enum ERMIAttachmentType
{
	eRAT_PreAttach = 0x0,
	eRAT_PostAttach = 0x1,
	eRAT_NoAttach = 0x2,
	eRAT_Urgent = 0x3,
	eRAT_Independent = 0x4,
	eRAT_NumAttachmentTypes = 0x5,
};

enum ENetReliabilityType
{
	eNRT_ReliableOrdered = 0x0,
	eNRT_ReliableUnordered = 0x1,
	eNRT_UnreliableOrdered = 0x2,
	eNRT_UnreliableUnordered = 0x3,
	eNRT_NumReliabilityTypes = 0x4,
};

struct IProtocolBuilder;
struct INetAtSyncItem;
struct INetChannel;
struct SNetMessageDef;
struct IRMIListener;
struct IRMICppLogger;

typedef uint8       ChannelMaskType;
typedef uint32 NetworkAspectType;
typedef uint8       NetworkAspectID;

struct ISerializableInfo : public CMultiThreadRefCount, public ISerializable {};
typedef _smart_ptr<ISerializableInfo> ISerializableInfoPtr;