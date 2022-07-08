// Copyright 2001-2016 Crytek GmbH / Crytek Group. All rights reserved.

#ifndef CRY_ASSERT_H_INCLUDED
#define CRY_ASSERT_H_INCLUDED
#include <cassert>

// TODO: Add CryEngine's Assert
#define CRY_ASSERT assert
#define CRY_ASSERT_TRACE(cond, msg) assert(cond)
#define CRY_ASSERT_MESSAGE(cond, msg) assert(cond)

#endif
