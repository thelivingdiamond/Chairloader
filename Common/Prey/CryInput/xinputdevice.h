// Header file automatically created from a PDB.

#pragma once
//#include <CryEngine/crycommon/multithread_containers.h>
#include <Prey/CryExtension/CryGUID.h>
#include <Prey/CryInput/IInput.h>
#include <Prey/CryInput/InputDevice.h>
#include "Prey/CryThreading/IThreadTask.h"
//#include <Prey/CryNetwork/IServiceNetwork.h>
//#include <Prey/CrySystem/ServiceNetwork.h>
#include <Prey/CryCore/StdAfx.h>
#include <Prey/CryCore/Platform/platform.h>

//FIXME: OH GOD NO PLEASE NO
typedef struct _XINPUT_GAMEPAD
{
    WORD                                wButtons;
    BYTE                                bLeftTrigger;
    BYTE                                bRightTrigger;
    SHORT                               sThumbLX;
    SHORT                               sThumbLY;
    SHORT                               sThumbRX;
    SHORT                               sThumbRY;
} XINPUT_GAMEPAD, *PXINPUT_GAMEPAD;

typedef struct _XINPUT_STATE
{
    DWORD                               dwPacketNumber;
    XINPUT_GAMEPAD                      Gamepad;
} XINPUT_STATE, *PXINPUT_STATE;

typedef struct _XINPUT_VIBRATION
{
    WORD                                wLeftMotorSpeed;
    WORD                                wRightMotorSpeed;
} XINPUT_VIBRATION, *PXINPUT_VIBRATION;

class CServiceNetwork;
class CServiceNetworkMessage;
struct IInput;
struct IServiceNetworkMessage;
struct SInputSymbol;

// Header: Exact
// CryEngine/cryinput/xinputdevice.h
class CXInputDevice : public CInputDevice // Id=800D0AF Size=168
{
public:
	int m_deviceNo;
	bool m_connected;
	bool m_forceResendSticks;
	_XINPUT_STATE m_state;
	_XINPUT_VIBRATION m_currentVibrationSettings;
	float m_basicLeftMotorRumble;
	float m_basicRightMotorRumble;
	float m_frameLeftMotorRumble;
	float m_frameRightMotorRumble;
	float m_fVibrationTimer;
	float m_fDeadZone;
	static inline auto ProductGUID = PreyGlobal<_GUID>(0x224BFF8);
	
	CXInputDevice(IInput &input, int deviceNo);
	virtual ~CXInputDevice();
	virtual int GetDeviceIndex() const;
	virtual bool Init();
	virtual void PostInit();
	virtual void Update(bool bFocus);
	virtual void ClearKeyState();
	virtual void ClearAnalogKeyState(std::vector<SInputSymbol *> &clearedSymbols);
	virtual bool SetForceFeedback(IFFParams params);
	virtual bool IsOfDeviceType(EInputDeviceType type) const;
	virtual void SetDeadZone(float fThreshold);
	virtual void RestoreDefaultDeadZone();
	bool SetVibration(uint16_t leftMotor, uint16_t rightMotor, float timing, EFFEffectId effectId) { return FSetVibration(this,leftMotor,rightMotor,timing,effectId); }
	void ProcessAnalogStick(SInputSymbol *pSymbol, int16_t prev, int16_t current, int16_t threshold) { FProcessAnalogStick(this,pSymbol,prev,current,threshold); }
	
#if 0
	void UpdateConnectedState(bool arg0);
	float GetClampedLeftMotorAccumulatedVibration() const;
	float GetClampedRightMotorAccumulatedVibration() const;
#endif
	
	static inline auto FGetDeviceIndex = PreyFunction<int(CXInputDevice const *const _this)>(0x9D8AD0);
	static inline auto FInit = PreyFunction<bool(CXInputDevice *const _this)>(0x9D8AE0);
	static inline auto FPostInit = PreyFunction<void(CXInputDevice *const _this)>(0x9D90D0);
	static inline auto FUpdate = PreyFunction<void(CXInputDevice *const _this, bool bFocus)>(0x9D9610);
	static inline auto FClearKeyState = PreyFunction<void(CXInputDevice *const _this)>(0x9D8A20);
	static inline auto FClearAnalogKeyState = PreyFunction<void(CXInputDevice *const _this, std::vector<SInputSymbol *> &clearedSymbols)>(0x9D85F0);
	static inline auto FSetForceFeedback = PreyFunction<bool(CXInputDevice *const _this, IFFParams params)>(0x9D92E0);
	static inline auto FIsOfDeviceType = PreyFunction<bool(CXInputDevice const *const _this, EInputDeviceType type)>(0x9D9020);
	static inline auto FSetDeadZone = PreyFunction<void(CXInputDevice *const _this, float fThreshold)>(0x9D92B0);
	static inline auto FRestoreDefaultDeadZone = PreyFunction<void(CXInputDevice *const _this)>(0x9D9290);
	static inline auto FSetVibration = PreyFunction<bool(CXInputDevice *const _this, uint16_t leftMotor, uint16_t rightMotor, float timing, EFFEffectId effectId)>(0x9D9340);
	static inline auto FProcessAnalogStick = PreyFunction<void(CXInputDevice *const _this, SInputSymbol *pSymbol, int16_t prev, int16_t current, int16_t threshold)>(0x9D91D0);
};

// Header: FromCpp
// CryEngine/cryinput/xinputdevice.h
class CInputConnectionThreadTask : public IThreadTask // Id=800D0CB Size=80
{
public:
	IInput *m_pInput;
	volatile bool m_bQuit;
	SThreadTaskInfo m_TaskInfo;
	
	virtual void Stop();
	virtual void OnUpdate();
	virtual SThreadTaskInfo *GetTaskInfo();
	virtual ~CInputConnectionThreadTask();
	
	static inline auto FStop = PreyFunction<void(CInputConnectionThreadTask *const _this)>(0x9D9600);
	static inline auto FOnUpdate = PreyFunction<void(CInputConnectionThreadTask *const _this)>(0x9D9040);
	static inline auto FGetTaskInfo = PreyFunction<SThreadTaskInfo *(CInputConnectionThreadTask *const _this)>(0x12BDA70);
};

// Header: Exact
// CryEngine/cryinput/xinputdevice.h
/*
class CServiceNetworkConnection : public IServiceNetworkConnection // Id=800FF1E Size=304
{
public:
	static constexpr const unsigned kMaximumMessageSize = 2621440;
	static constexpr const uint64_t kInitializationPerior = 1000;
	static constexpr const uint64_t kKeepAlivePeriod = 2000;
	static constexpr const uint64_t kReconnectTryPerior = 1000;
	static constexpr const uint64_t hReconnectTimeOut = 30000;
	static constexpr const uint64_t kTimeout = 5000;
	
	enum EEndpoint
	{
		eEndpoint_Server = 0,
		eEndpoint_Client = 1,
	};

	enum EState
	{
		eState_Initializing = 0,
		eState_Valid = 1,
		eState_Lost = 2,
		eState_Closed = 3,
	};

	enum ECommand
	{
		eCommand_Data = 1,
		eCommand_KeepAlive = 2,
		eCommand_Initialize = 3,
	};

	struct Header // Id=800FF1F Size=5
	{
		uint8_t m_cmd;
		unsigned m_size;
		
#if 0
		void Swap();
#endif
	};

	struct InitHeader // Id=800FF20 Size=24
	{
		uint8_t m_cmd;
		uint8_t m_pad0;
		uint8_t m_pad1;
		uint8_t m_pad2;
		unsigned m_tryCount;
		uint64_t m_guid0;
		uint64_t m_guid1;
		
#if 0
		void Swap();
#endif
	};

	CServiceNetwork *m_pManager;
	CServiceNetworkConnection::EEndpoint m_endpointType;
	CServiceNetworkConnection::EState m_state;
	volatile int m_refCount;
	uint64_t m_socket;
	ServiceNetworkAddress m_localAddress;
	ServiceNetworkAddress m_remoteAddress;
	CryGUID m_connectionID;
	uint64_t m_lastReconnectTime;
	uint64_t m_lastKeepAliveSendTime;
	uint64_t m_lastMessageReceivedTime;
	uint64_t m_lastInitializationSendTime;
	unsigned m_reconnectTryCount;
	volatile unsigned m_statsNumPacketsSend;
	volatile unsigned m_statsNumPacketsReceived;
	volatile unsigned m_statsNumDataSend;
	volatile unsigned m_statsNumDataReceived;
	
	using TSendQueue = CryMT::CLocklessPointerQueue<CServiceNetworkMessage,std::allocator<CServiceNetworkMessage> >;
	
	CServiceNetworkMessage *m_pSendedMessages;
	CryMT::CLocklessPointerQueue<CServiceNetworkMessage,std::allocator<CServiceNetworkMessage> > m_pSendQueue;
	unsigned m_messageDataSentSoFar;
	volatile int m_sendQueueDataSize;
	
	using TReceiveQueue = CryMT::CLocklessPointerQueue<CServiceNetworkMessage,std::allocator<CServiceNetworkMessage> >;
	
	CryMT::CLocklessPointerQueue<CServiceNetworkMessage,std::allocator<CServiceNetworkMessage> > m_pReceiveQueue;
	unsigned m_receiveQueueDataSize;
	unsigned m_messageDataReceivedSoFar;
	unsigned m_messageReceiveLength;
	CServiceNetworkMessage *m_pCurrentReceiveMessage;
	unsigned m_messageDummyReadLength;
	bool m_bCloseRequested;
	bool m_bDisableCommunication;
	
	CServiceNetworkConnection(CServiceNetwork *manager, CServiceNetworkConnection::EEndpoint endpointType, uint64_t socket, CryGUID const &connectionID, ServiceNetworkAddress const &localAddress, ServiceNetworkAddress const &remoteAddress);
	virtual ~CServiceNetworkConnection();
	virtual ServiceNetworkAddress const &GetRemoteAddress() const;
	virtual ServiceNetworkAddress const &GetLocalAddress() const;
	virtual CryGUID const &GetGUID() const;
	virtual bool IsAlive() const;
	virtual unsigned GetMessageSendCount() const;
	virtual unsigned GetMessageReceivedCount() const;
	virtual uint64_t GetMessageSendDataSize() const;
	virtual uint64_t GetMessageReceivedDataSize() const;
	virtual bool SendMsg(IServiceNetworkMessage *message);
	virtual IServiceNetworkMessage *ReceiveMsg();
	virtual void FlushAndClose(const unsigned timeout);
	virtual void FlushAndWait();
	virtual void Close();
	virtual void AddRef();
	virtual void Release();
	void Update() { FUpdate(this); }
	void ProcessSendingQueue() { FProcessSendingQueue(this); }
	void ProcessReceivingQueue() { FProcessReceivingQueue(this); }
	void ProcessKeepAlive() { FProcessKeepAlive(this); }
	bool HandleTimeout(const uint64_t currentNetworkTime) { return FHandleTimeout(this,currentNetworkTime); }
	unsigned TryReceive(void *dataBuffer, unsigned dataSize, bool autoHandleErrors) { return FTryReceive(this,dataBuffer,dataSize,autoHandleErrors); }
	void Shutdown() { FShutdown(this); }
	void Reset() { FReset(this); }
	
#if 0
	bool IsInitialized() const;
	bool IsSendingQueueEmpty() const;
	CServiceNetwork *GetManager() const;
	void SendKeepAlive(const uint64_t arg0);
	bool HandleReconnect(uint64_t arg0, const unsigned arg1);
	unsigned TrySend(const void *arg0, unsigned arg1, bool arg2);
	bool TryReconnect();
	bool TryInitialize();
#endif
	
	static inline auto FGetRemoteAddress = PreyFunction<ServiceNetworkAddress const &(CServiceNetworkConnection const *const _this)>(0xD9C600);
	static inline auto FGetLocalAddress = PreyFunction<ServiceNetworkAddress const &(CServiceNetworkConnection const *const _this)>(0x10BDA70);
	static inline auto FGetGUID = PreyFunction<CryGUID const &(CServiceNetworkConnection const *const _this)>(0x10BDA20);
	static inline auto FIsAlive = PreyFunction<bool(CServiceNetworkConnection const *const _this)>(0xD9C680);
	static inline auto FGetMessageSendCount = PreyFunction<unsigned(CServiceNetworkConnection const *const _this)>(0xD9C5E0);
	static inline auto FGetMessageReceivedCount = PreyFunction<unsigned(CServiceNetworkConnection const *const _this)>(0x9D8AD0);
	static inline auto FGetMessageSendDataSize = PreyFunction<uint64_t(CServiceNetworkConnection const *const _this)>(0xD9C5F0);
	static inline auto FGetMessageReceivedDataSize = PreyFunction<uint64_t(CServiceNetworkConnection const *const _this)>(0xC27440);
	static inline auto FSendMsg = PreyFunction<bool(CServiceNetworkConnection *const _this, IServiceNetworkMessage *message)>(0xD9D870);
	static inline auto FReceiveMsg = PreyFunction<IServiceNetworkMessage *(CServiceNetworkConnection *const _this)>(0xD9CDA0);
	static inline auto FFlushAndClose = PreyFunction<void(CServiceNetworkConnection *const _this, const unsigned timeout)>(0xD9C2D0);
	static inline auto FFlushAndWait = PreyFunction<void(CServiceNetworkConnection *const _this)>(0xD9C3B0);
	static inline auto FClose = PreyFunction<void(CServiceNetworkConnection *const _this)>(0xD9BDF0);
	static inline auto FAddRef = PreyFunction<void(CServiceNetworkConnection *const _this)>(0xD9BD40);
	static inline auto FRelease = PreyFunction<void(CServiceNetworkConnection *const _this)>(0xD9CE80);
	static inline auto FUpdate = PreyFunction<void(CServiceNetworkConnection *const _this)>(0xD9DD40);
	static inline auto FProcessSendingQueue = PreyFunction<void(CServiceNetworkConnection *const _this)>(0xD9CC50);
	static inline auto FProcessReceivingQueue = PreyFunction<void(CServiceNetworkConnection *const _this)>(0xD9C990);
	static inline auto FProcessKeepAlive = PreyFunction<void(CServiceNetworkConnection *const _this)>(0xD9C6A0);
	static inline auto FHandleTimeout = PreyFunction<bool(CServiceNetworkConnection *const _this, const uint64_t currentNetworkTime)>(0xD9C620);
	static inline auto FTryReceive = PreyFunction<unsigned(CServiceNetworkConnection *const _this, void *dataBuffer, unsigned dataSize, bool autoHandleErrors)>(0xD9DCB0);
	static inline auto FShutdown = PreyFunction<void(CServiceNetworkConnection *const _this)>(0xD9D930);
	static inline auto FReset = PreyFunction<void(CServiceNetworkConnection *const _this)>(0xD9CEC0);
};

*/