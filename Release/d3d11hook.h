/*
	d3d11hook.h / d3d11hook.lib
	
	Documentation: https://github.com/Rebzzel/Universal-D3D11-Hook/blob/master/README.md

	Initializing Example:
		CreateThread(nullptr, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(pd3dHook->Install()), nullptr, 0, nullptr);

	Copyright (c) 2015 - 2017 Rebzzel. All rights reserved.

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	SOFTWARE.
*/

#ifndef _D3D11_HOOK_H_
#define _D3D11_HOOK_H_

#include <d3d11.h>

#pragma comment(lib, "d3d11.lib")

#define PRESENT_FUNC

#define SAFE_RELEASE(p) { if((p)) { (p)->Release(); (p) = NULL; } }
#define SAFE_DELETE(a) { if((a)) { delete (a); (a) = NULL; } }

extern PRESENT_FUNC void Present(IDXGISwapChain* swapChain, ID3D11Device* device, ID3D11DeviceContext* context); // swapChain, device and context automatically transferred by hook

class D3D11Hook
{
public:
	D3D11Hook(const char* windowName);
	~D3D11Hook();

	ID3D11Device* GetDevice() const { _device; }
	ID3D11DeviceContext* GetContext() const { _context; }
	IDXGISwapChain* GetSwapChain() const { _swapChain; }

	int __stdcall Install();
	int __stdcall Uninstall();

private:
	static ID3D11Device* _device;
	static ID3D11DeviceContext* _context;
	static IDXGISwapChain* _swapChain;
};

#endif // !_D3D11_HOOK_H_
