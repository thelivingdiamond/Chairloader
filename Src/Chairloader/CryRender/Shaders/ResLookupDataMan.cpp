#include <Prey/RenderDll/Common/ResFileLookupDataMan.h>

void CResFileLookupDataMan::chair_RemoveData(uint32 CRC)
{
	{
		TFileResDirDataMap tmpData;
		for (TFileResDirDataMap::iterator it = m_Data.begin(); it != m_Data.end(); ++it)
		{
			SResFileLookupData& data = it->second;
			if (data.m_CRC32 != CRC)
				tmpData[it->first] = data;
		}
		m_Data.swap(tmpData);
	}

	{
		TFileCFXDataMap tmpData;
		for (TFileCFXDataMap::iterator it = m_CFXData.begin(); it != m_CFXData.end(); ++it)
		{
			SCFXLookupData& data = it->second;
			if (data.m_CRC32 != CRC)
				tmpData[it->first] = data;
		}
		m_CFXData.swap(tmpData);
	}
}
