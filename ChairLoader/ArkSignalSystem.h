#pragma once
#include "pch.h"

#include "ArkProjectile.h"
#include "Prey/ArkPlayer.h"

namespace ArkSignalSystem {
	class PackageSignalRamp
	{
		const float m_ramp;
		const int m_maxRepeatCount;
		const float m_increaseTime;
		const float m_decreaseTime;
		const int m_decreaseCount;
		int m_repeatCount;
		float m_leftoverInterval;
		CTimeValue m_lastReceiveTime;
		CTimeValue m_lastIncrementTime;
	};
	class PackageSignalRampContainer
	{
		std::unordered_map<unsigned __int64, ArkSignalSystem::PackageSignalRamp> m_packageSignalRamps;
	};
	class CArkSignalContext
	{
		boost::variant<boost::blank, HitInfo const*, SExplosionContainer*> m_pInfo;
	};
	class Package
	{
		class Value
		{
			unsigned __int64 m_signalId;
			float m_value;
		};
		std::vector<ArkSignalSystem::Package::Value> m_values;
		unsigned __int64 m_id;
		unsigned int m_sourceId;
		ArkSignalSystem::CArkSignalContext m_context;
	};
	class Receiver
	{
	public:
		virtual ~Receiver() = 0;
		virtual void Init(const unsigned int*) = 0;
		virtual void OnReceiveSignal(const ArkSignalSystem::Package*) = 0;
		virtual ArkSignalSystem::PackageSignalRampContainer* GetPackageSignalRampContainer() = 0;
		virtual void OnKilled(unsigned int) = 0;


		unsigned int m_entityId;
	};
	
}


class ArkGooSignalReceiver : ArkSignalSystem::Receiver
{
public:


	CArkProjectileGoo* m_pOwnerGoo;
	unsigned __int64 m_damageSignalGroup;
};
