// Header file automatically created from a PDB.
#pragma once

class CDeviceCommandList;

// CRenderItemDrawer
// Header:  CryEngine/renderdll/common/RenderItemDrawer.h
// Include: Prey/RenderDll/Common/RenderItemDrawer.h
class CRenderItemDrawer
{ // Size=96 (0x60)
public:
	// CRenderItemDrawer::SRenderListCollection
	// Header:  CryEngine/renderdll/common/RenderItemDrawer.h
	struct SRenderListCollection
	{ // Size=96 (0x60)
		std::vector<SGraphicsPipelinePassContext> rendList;
		SGraphicsPipelinePassContext* pStart;
		SGraphicsPipelinePassContext* pEnd;
		std::vector<std::unique_ptr<CDeviceCommandList>> pCommandLists;
		JobManager::SJobState jobState;

		void WaitForJobs() { FWaitForJobs(this); }

#if 0
		void Init();
		void Reserve(uint64_t _arg0_);
		void Expand(const SGraphicsPipelinePassContext& _arg0_);
		void PrepareJobs(unsigned _arg0_);
#endif

		static inline auto FWaitForJobs = PreyFunction<void(CRenderItemDrawer::SRenderListCollection* const _this)>(0xEAD7F0);
	};

	CRenderItemDrawer::SRenderListCollection m_CoalescedContexts;

	void DrawCompiledRenderItems(const SGraphicsPipelinePassContext& passContext) const { FDrawCompiledRenderItems(this, passContext); }
	void InitDrawSubmission() { FInitDrawSubmission(this); }
	void JobifyDrawSubmission(bool bForceImmediateExecution) { FJobifyDrawSubmission(this, bForceImmediateExecution); }
	void WaitForDrawSubmission() { FWaitForDrawSubmission(this); }

	static inline auto FDrawCompiledRenderItems = PreyFunction<void(const CRenderItemDrawer* const _this, const SGraphicsPipelinePassContext & passContext)>(0xEACFF0);
	static inline auto FInitDrawSubmission = PreyFunction<void(CRenderItemDrawer* const _this)>(0x120E390);
	static inline auto FJobifyDrawSubmission = PreyFunction<void(CRenderItemDrawer* const _this, bool bForceImmediateExecution)>(0xEAD2C0);
	static inline auto FWaitForDrawSubmission = PreyFunction<void(CRenderItemDrawer* const _this)>(0xEAD7D0);
};
