#include <Prey/RenderDll/Common/RenderThread.h>
#include <Prey/RenderDll/Common/RenderAuxGeom.h>

namespace
{

// SRenderThread::ProcessCommands
auto s_SRenderThread_ProcessCommands = PreyFunction<void(SRenderThread* _this)>(0xFBD460);

// Points into the while loop, before switch statement
auto s_SRenderThread_ProcessCommands_CmdLoop = PreyFunction<void()>(0xFBD530);

auto s_SRenderThread_ProcessCommands_Hook = s_SRenderThread_ProcessCommands.MakeHook();
auto s_SRenderThread_ProcessCommands_CmdLoop_Hook = s_SRenderThread_ProcessCommands_CmdLoop.MakeHook();

// Local variables of the SRenderThread_ProcessCommands hook
// Since it's split into two funcs with some asm code, use globals for them
SRenderThread* thisPtr = nullptr;
int processedCmdBytes = 0; //!< Number of bytes processed

}

// Implemented in RenderCommandHook.asm
extern "C" void SRenderThread_ProcessCommandsHook();

// Pointer to trampoline back into CmdLoop
extern "C" uintptr_t SRenderThread_ProcessCommands_CmdLoopTrampoline = 0;

TArray<byte> SRenderThread::m_CustomCommands[RT_COMMAND_BUF_COUNT];

static void SRenderThread_ProcessCommands_Hook(SRenderThread* _this)
{
	thisPtr = _this;
	processedCmdBytes = 0;

	s_SRenderThread_ProcessCommands_Hook.InvokeOrig(_this);

	// Clear custom command list
	TArray<byte>& cmdBuf = SRenderThread::m_CustomCommands[_this->m_nCurThreadProcess];
	CRY_ASSERT(processedCmdBytes == cmdBuf.Num());
	cmdBuf.SetUse(0);

	thisPtr = nullptr;
}

// Called from asm
extern "C" void SRenderThread_CustomCommandHandler(int origN)
{
	int threadId = thisPtr->m_nCurThreadProcess;
	if ((int)thisPtr->m_Commands[threadId].Num() == 0)
		return;

	byte* pOrigP = &thisPtr->m_Commands[threadId][origN];
	origN += sizeof(int);
	byte nOrigC = (byte) * ((int*)pOrigP);

	if (nOrigC == eRC_Custom)
	{
		TArray<byte>& cmdBuf = SRenderThread::m_CustomCommands[threadId];
		int n = processedCmdBytes;
		byte* pP = &cmdBuf[n];
		n += sizeof(int);
		byte nC = (byte) * ((int*)pP);

		switch (nC)
		{
		case eRCC_AuxFlush:
		{
			IRenderAuxGeomImpl* pAux = thisPtr->ReadCommand<IRenderAuxGeomImpl*>(n);
			CAuxGeomCB::SAuxGeomCBRawData* pData = thisPtr->ReadCommand<CAuxGeomCB::SAuxGeomCBRawData*>(n);
			size_t begin = thisPtr->ReadCommand<size_t>(n);
			size_t end = thisPtr->ReadCommand<size_t>(n);
			bool reset = thisPtr->ReadCommand<uint32>(n) != 0;

			if (thisPtr->m_eVideoThreadMode == SRenderThread::eVTM_Disabled)
			{
				SAuxGeomCBRawDataPackaged data = SAuxGeomCBRawDataPackaged(pData);
				pAux->RT_Flush(data, begin, end, reset);
			}
			break;
		}
		default:
		{
			CRY_ASSERT(false);
		}
		}

		processedCmdBytes = n;
	}
}

void SRenderThread_InstallCommandHandler()
{
	s_SRenderThread_ProcessCommands_Hook.SetHookFunc(&SRenderThread_ProcessCommands_Hook);
	s_SRenderThread_ProcessCommands_CmdLoop_Hook.SetHookFunc(&SRenderThread_ProcessCommandsHook);
}

void SRenderThread_RemoveCommandHandler()
{
	s_SRenderThread_ProcessCommands_Hook.RemoveHook();
	s_SRenderThread_ProcessCommands_CmdLoop_Hook.RemoveHook();
}

void SRenderThread_PostHook()
{
	SRenderThread_ProcessCommands_CmdLoopTrampoline = (uintptr_t)s_SRenderThread_ProcessCommands_CmdLoop_Hook.GetOrig();
}