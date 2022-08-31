// Copyright 2001-2016 Crytek GmbH / Crytek Group. All rights reserved.

// -------------------------------------------------------------------------
//  File name:   RegFactoryNode.h
//  Version:     v1.00
//  Created:     02/25/2009 by CarstenW
//  Description: Part of CryEngine's extension framework.
// -------------------------------------------------------------------------
//
////////////////////////////////////////////////////////////////////////////

#ifndef _REGFACTORYNODE_H_
#define _REGFACTORYNODE_H_

#pragma once

struct ICryFactory;
struct SRegFactoryNode;

extern SRegFactoryNode* g_pHeadToRegFactories;

struct SRegFactoryNode
{
	SRegFactoryNode()
	{
	}

	SRegFactoryNode(ICryFactory* pFactory)
		: m_pFactory(pFactory)
		, m_pNext(g_pHeadToRegFactories)
	{
		g_pHeadToRegFactories = this;
	}

	static void* operator new(size_t, void* p)
	{
		return p;
	}

	static void operator delete(void*, void*)
	{
	}

	ICryFactory*     m_pFactory;
	SRegFactoryNode* m_pNext;
};

#endif // #ifndef _REGFACTORYNODE_H_
