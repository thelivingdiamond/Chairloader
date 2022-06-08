#pragma once

class PerfOverlay {
public:
	PerfOverlay();

	void Update();
	void ShowMenu();
	void SetEnabled(bool state);
	void SetFrameTimeVisible(bool state);

private:
	static constexpr float FILTER_K = 0.2f;
	bool m_bEnabled = false;
	bool m_bFrameTime = false;
	float m_LastFrameTime = 0;
};