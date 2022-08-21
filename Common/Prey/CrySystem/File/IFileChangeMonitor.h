// Copyright 2001-2019 Crytek GmbH / Crytek Group. All rights reserved.

#pragma once

struct IFileChangeListener
{
	enum EChangeType
	{
		eChangeType_Unknown,          //! Error or unknown change type.
		eChangeType_Created,          //! The file was created.
		eChangeType_Deleted,          //! The file was deleted.
		eChangeType_Modified,         //! The file was modified (size changed,write).
		eChangeType_RenamedOldName,   //! This is the old name of a renamed file.
		eChangeType_RenamedNewName    //! This is the new name of a renamed file.
	};

	virtual ~IFileChangeListener() {}
	virtual void OnFileChange(const char* sFilename, EChangeType eType) = 0;
};

struct IFileChangeMonitor
{
	virtual ~IFileChangeMonitor() {}
	// <interfuscator:shuffle>
	//! Register the path of a file or directory to monitor.
	//! Path is relative to game directory, e.g. "Libs/WoundSystem/" or "Libs/WoundSystem/HitLocations.xml".
	virtual bool RegisterListener(IFileChangeListener* pListener, const char* sMonitorItem) = 0;

	//! This function can be used to monitor files of specific type, e.g.
	//! RegisterListener(pListener, "Animations", "caf").
	virtual bool RegisterListener(IFileChangeListener* pListener, const char* sFolder, const char* sExtension) = 0;

	virtual bool UnregisterListener(IFileChangeListener* pListener) = 0;
	// </interfuscator:shuffle>
};
