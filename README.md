# Universal-D3D11-Hook
[![GitHub release](https://img.shields.io/github/release/rebzzel/Universal-D3D11-Hook.svg?style=flat-square)](https://github.com/Rebzzel/Universal-D3D11-Hook/releases)
[![GitHub license](https://img.shields.io/badge/license-MIT-blue.svg?style=flat-square)](https://raw.githubusercontent.com/Rebzzel/Universal-D3D11-Hook/master/LICENSE)

## Methoths
`GetDevice() — return ID3D11Device`

`GetContext() — return ID3D11DeviceContext`

`GetSwapChain() — return IDXGISwapChain`

`Install() — for initialize hook`

`Uninstall() — for deinitialize hook`

## Example
```C++
#include <Windows.h>
#include "d3d11hook.h"

#pragma comment(lib, "d3d11hook.lib")

D3D11Hook* pd3dHook = new D3D11Hook("BrokeProtocol");

PRESENT_FUNC void Present(IDXGISwapChain* swapChain, ID3D11Device* device, ID3D11DeviceContext* context)
{
  // Here your magic
}

BOOL WINAPI DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpvReserved)
{
  switch(dwReason)
  {
    case DLL_PROCESS_ATTACH:
      // Init hook
      CreateThread(nullptr, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(pd3dHook->Install()), nullptr, 0, nullptr);
      break;
    case DLL_PROCESS_DETACH:
      pd3dHook->Uninstall();
      break;
  }
}
```
