#define _WINSOCKAPI_
#include <cassert>
#include <winsock2.h>
#include <Windows.h>
#include "mswsock_proxy.h"

#define DLLEXPORT __declspec(dllexport)

struct sockaddr;

namespace {

using FnGetAcceptExSockaddrs = void (__stdcall *)(PVOID lpOutputBuffer, DWORD dwReceiveDataLength, DWORD dwLocalAddressLength,
	DWORD dwRemoteAddressLength, struct sockaddr **LocalSockaddr, LPINT LocalSockaddrLength,
	struct sockaddr **RemoteSockaddr, LPINT RemoteSockaddrLength);

using FnAcceptEx = BOOL(__stdcall *)(SOCKET sListenSocket, SOCKET sAcceptSocket, PVOID lpOutputBuffer,
	DWORD dwReceiveDataLength, DWORD dwLocalAddressLength, DWORD dwRemoteAddressLength, LPDWORD lpdwBytesReceived,
	LPOVERLAPPED lpOverlapped);

HMODULE hWS = nullptr;
FnGetAcceptExSockaddrs pfn_GetAcceptExSockaddrs = nullptr;
FnAcceptEx pfn_AcceptEx = nullptr;
}


void MSWSProxy_Init() {
	hWS = LoadLibraryA("C:\\Windows\\System32\\mswsock.DLL");
	assert(hWS);
	pfn_GetAcceptExSockaddrs = reinterpret_cast<FnGetAcceptExSockaddrs>(GetProcAddress(hWS, "GetAcceptExSockaddrs"));
	pfn_AcceptEx = reinterpret_cast<FnAcceptEx>(GetProcAddress(hWS, "AcceptEx"));
}

void MSWSProxy_Shutdown() {
	
	FreeLibrary(hWS);
}

extern "C" {
	DLLEXPORT
		VOID
		PASCAL FAR
		GetAcceptExSockaddrs(
			_In_reads_bytes_(dwReceiveDataLength + dwLocalAddressLength + dwRemoteAddressLength) PVOID lpOutputBuffer,
			_In_ DWORD dwReceiveDataLength,
			_In_ DWORD dwLocalAddressLength,
			_In_ DWORD dwRemoteAddressLength,
			_Outptr_result_bytebuffer_(*LocalSockaddrLength) struct sockaddr **LocalSockaddr,
			_Out_ LPINT LocalSockaddrLength,
			_Outptr_result_bytebuffer_(*RemoteSockaddrLength) struct sockaddr **RemoteSockaddr,
			_Out_ LPINT RemoteSockaddrLength
		) {
		pfn_GetAcceptExSockaddrs(
			lpOutputBuffer, dwReceiveDataLength,
			dwLocalAddressLength, dwRemoteAddressLength,
			LocalSockaddr, LocalSockaddrLength,
			RemoteSockaddr, RemoteSockaddrLength
		);
	}

	DLLEXPORT
		BOOL
		PASCAL FAR
		AcceptEx(
			_In_ SOCKET sListenSocket,
			_In_ SOCKET sAcceptSocket,
			_Out_writes_bytes_to_(dwReceiveDataLength + dwLocalAddressLength + dwRemoteAddressLength,
				*lpdwBytesReceived) PVOID lpOutputBuffer,
			_In_ DWORD dwReceiveDataLength,
			_In_ DWORD dwLocalAddressLength,
			_In_ DWORD dwRemoteAddressLength,
			_Out_ LPDWORD lpdwBytesReceived,
			_Inout_ LPOVERLAPPED lpOverlapped
		) {
		return pfn_AcceptEx(sListenSocket, sAcceptSocket, lpOutputBuffer, dwReceiveDataLength,
			dwLocalAddressLength, dwRemoteAddressLength, lpdwBytesReceived, lpOverlapped);
	}
}