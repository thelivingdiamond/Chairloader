#pragma once

class PerfOverlay : NoCopy {
public:
	PerfOverlay();
	~PerfOverlay();

	void Update();
	void ShowMenu();
	void SetEnabled(bool state);
	void SetFrameTimeVisible(bool state);

private:
	const std::string modName = "PerfOverlay";
	static constexpr float FILTER_K = 0.2f;
	int m_Enabled = 0;
	int m_ShowFrameTime = 0;
	float m_LastFrameTime = 0;
};