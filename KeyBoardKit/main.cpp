// main.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <Windows.h>

#include "include\HotKeyAbstractInterface\HotKey.h"
#include "include\HotKeyAbstractInterface\HotKeyManager.h"

using KeyBoardKit::HotKeyKit::HotKeyManager;
using KeyBoardKit::HotKeyKit::HotKey;
using KeyBoardKit::HotKeyKit::HotKeyIndentifier;

static HotKeyManager g_HotKeyManager;

static void ListenToApplicationEvents() {
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0) != 0) {
		if (msg.message == WM_HOTKEY) {
			HotKeyIndentifier hotkeyId = msg.wParam;

			void *func = g_HotKeyManager.findActionByHotKeyId(hotkeyId);
			((void(*)())func)();
		}
		else {
			DispatchMessage(&msg);
		}
	}
}

void func_001() {

	printf("hello world\n");
	keybd_event(VK_SPACE, 0, 0, 0);
	// C key
	keybd_event(0x43, 0, 0, 0);
	keybd_event(VK_SPACE, 0, KEYEVENTF_KEYUP, 0);
	keybd_event(0x43, 0, KEYEVENTF_KEYUP, 0);
}

int main()
{
	HotKey *hk = HotKey::CreateHotKeyByKeyString("Ctrl+T", func_001);
	g_HotKeyManager.registerHotKey(*hk);
	ListenToApplicationEvents();
	g_HotKeyManager.unregisterAllHotkeys();
    return 0;
}

