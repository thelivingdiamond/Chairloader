#pragma once

struct IGameObjectExtensionCreatorBase
{
	// <interfuscator:shuffle>
	virtual ~IGameObjectExtensionCreatorBase() {}
	virtual IGameObjectExtensionPtr Create() = 0;
	virtual void                    GetGameObjectExtensionRMIData(void** ppRMI, size_t* nCount) = 0;
	// </interfuscator:shuffle>
};
