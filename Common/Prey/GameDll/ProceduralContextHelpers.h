// Copyright 2001-2016 Crytek GmbH / Crytek Group. All rights reserved.
// Based on CRYENGINE 5.2 GameSDK GameDll/ProceduralContextHelpers.h.
#pragma once
#include <Prey/CryCore/StdAfx.h>

namespace ProceduralContextHelpers
{

// ProceduralContextHelpers::CRequestList<T>
// Header:  _unknown/ProceduralContextHelpers__CRequestList.h
template<typename TRequestType>
class CRequestList
{ // Size=32 (0x20)
public:
	typedef std::vector<TRequestType> TRequestsVector;

	uint32 AddRequest(TRequestType& request)
	{
		request.id = m_nextId;
		m_requests.push_back(request);

		// It is extremely unlikely that we'll wrap around and get a clash with a current request, since requests will usually have a short life span.
		++m_nextId;

		return request.id;
	}

	void RemoveRequest(const uint32 cancelRequestId)
	{
		typename TRequestsVector::iterator itEnd = m_requests.end();
		for (typename TRequestsVector::iterator it = m_requests.begin(); it != itEnd; ++it)
		{
			const TRequestType& request = *it;
			if (cancelRequestId == request.id)
			{
				m_requests.erase(it);
				return;
			}
		}
	}

	const TRequestType& GetRequest(const size_t index) const
	{
		return m_requests[index];
	}

	const size_t GetCount() const
	{
		return m_requests.size();
	}

	uint32 m_nextId;
	TRequestsVector m_requests;
};

} // namespace ProceduralContextHelpers
