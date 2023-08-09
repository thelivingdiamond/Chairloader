#pragma once
#include <pugixml.hpp>

struct IUserProjectSettings
{
	//! Name of the XML file.
	static constexpr char FILE_NAME[] = "UserSettings.xml";

	//! The invalid value for size and position.
	static constexpr int INVALID_SIZE = -65536;

    virtual ~IUserProjectSettings() {}

	//! Non-maximized window pos and size
	//! @{
	virtual const Vec2i& GetWindowRestoredPos() const = 0;
	virtual void SetWindowRestoredPos(const Vec2i& val) = 0;

	virtual const Vec2i& GetWindowRestoredSize() const = 0;
	virtual void SetWindowRestoredSize(const Vec2i& val) = 0;
	//! @}

	//! @returns whether the window was maximized.
	virtual bool IsWindowMaximized() const = 0;
	virtual void SetWindowMaximized(bool val) = 0;
};
