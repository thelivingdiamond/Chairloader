// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/INetwork.h>

struct SHostMigrationInfo;

// Header: MadeUp
// _unknown/IHostMigrationEventListener.h
struct IHostMigrationEventListener // Id=80007D7 Size=8
{
	enum class EHostMigrationReturn
	{
		Listener_Done = 0,
		Listener_Wait = 1,
		Listener_Terminate = 2,
	};

	virtual ~IHostMigrationEventListener();
	virtual IHostMigrationEventListener::EHostMigrationReturn OnInitiate(SHostMigrationInfo &arg0, unsigned &arg1) = 0;
	virtual IHostMigrationEventListener::EHostMigrationReturn OnDisconnectClient(SHostMigrationInfo &arg0, unsigned &arg1) = 0;
	virtual IHostMigrationEventListener::EHostMigrationReturn OnDemoteToClient(SHostMigrationInfo &arg0, unsigned &arg1) = 0;
	virtual IHostMigrationEventListener::EHostMigrationReturn OnPromoteToServer(SHostMigrationInfo &arg0, unsigned &arg1) = 0;
	virtual IHostMigrationEventListener::EHostMigrationReturn OnReconnectClient(SHostMigrationInfo &arg0, unsigned &arg1) = 0;
	virtual IHostMigrationEventListener::EHostMigrationReturn OnFinalise(SHostMigrationInfo &arg0, unsigned &arg1) = 0;
	virtual IHostMigrationEventListener::EHostMigrationReturn OnTerminate(SHostMigrationInfo &arg0, unsigned &arg1) = 0;
	virtual void OnComplete(SHostMigrationInfo &arg0) = 0;
	virtual IHostMigrationEventListener::EHostMigrationReturn OnReset(SHostMigrationInfo &arg0, unsigned &arg1) = 0;
};

