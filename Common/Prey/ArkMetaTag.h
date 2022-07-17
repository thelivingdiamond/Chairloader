#pragma once
class IArkMetaTagListener
{
public:
	virtual void OnMetaTagAdded(unsigned int, const unsigned __int64) = 0;
	virtual void OnMetaTagRemoved(unsigned int, const unsigned __int64) = 0;
	virtual void OnMetaTagsAdded(unsigned int) = 0;
	virtual void OnAllDynamicMetaTagsRemoved(unsigned int) = 0;


};