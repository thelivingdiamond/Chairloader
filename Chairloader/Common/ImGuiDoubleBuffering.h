#pragma once
#include <imgui.h>

//! A custom version of ImDrawList. Keeps references to buffers in ImRendDrawData.
struct ImRendDrawList
{
	ImDrawListFlags flags;
	int cmdOffset;
	int cmdCount;
	int idxOffset;
	int idxCount;
	int vtxOffset;
	int vtxCount;
};

//! A custom version of ImDrawData. Keeps all draw list data as vectors to reuse allocated memory.
struct ImRendDrawBuffer
{
	ImVec2 displayPos;
	ImVec2 displaySize;
	ImVec2 framebufferScale;
	std::vector<ImRendDrawList> drawLists;
	std::vector<ImDrawCmd> drawCmds;
	std::vector<ImDrawIdx> idxBuffer;
	std::vector<ImDrawVert> vtxBuffer;
	ImDrawData a;
	std::mutex mutex;

	//! Clears currently stored data.
	void Clear()
	{
		drawLists.clear();
		drawCmds.clear();
		idxBuffer.clear();
		vtxBuffer.clear();
	}

	//! Copies render data (ImGui::GetDrawData()) for current ImGui context to the buffer
	void FillForCurrentContext()
	{
		Clear();

		const ImDrawData& imDrawData = *ImGui::GetDrawData();
		displayPos = imDrawData.DisplayPos;
		displaySize = imDrawData.DisplaySize;
		framebufferScale = imDrawData.FramebufferScale;
		drawLists.reserve(imDrawData.CmdListsCount);

		for (int n = 0; n < imDrawData.CmdListsCount; n++)
		{
			const ImDrawList& imDrawList = *imDrawData.CmdLists[n];
			ImRendDrawList& drawList = drawLists.emplace_back();
			drawList.flags = imDrawList.Flags;

			drawList.cmdOffset = (int)drawCmds.size();
			drawCmds.insert(drawCmds.end(), imDrawList.CmdBuffer.begin(), imDrawList.CmdBuffer.end());
			drawList.cmdCount = (int)drawCmds.size() - drawList.cmdOffset;

			drawList.idxOffset = (int)idxBuffer.size();
			idxBuffer.insert(idxBuffer.end(), imDrawList.IdxBuffer.begin(), imDrawList.IdxBuffer.end());
			drawList.idxCount = (int)idxBuffer.size() - drawList.idxOffset;

			drawList.vtxOffset = (int)vtxBuffer.size();
			vtxBuffer.insert(vtxBuffer.end(), imDrawList.VtxBuffer.begin(), imDrawList.VtxBuffer.end());
			drawList.vtxCount = (int)vtxBuffer.size() - drawList.vtxOffset;
		}
	}
};
