#pragma once

#include<iostream>
#include <Windows.h>
#include <unordered_map>

#include "HotKey.h"

namespace KeyBoardKit {
	namespace HotKeyKit {
		class HotKeyManager
		{
			typedef KeyBoardKit::HotKeyKit::HotKey HotKey;

		public:
			HotKeyManager(HWND associatedWindow = NULL);
			~HotKeyManager();

			HotKeyIndentifier registerHotKey(const HotKey &hotkey);

			void unregisterHotKey(HotKeyIndentifier hotkey_id);

			void unregisterAllHotkeys();

			void *findActionByHotKeyId(HotKeyIndentifier hotkey_id);

		private:
			HWND m_associatedWindow;
			std::unordered_map<HotKeyIndentifier, HotKey> m_hotkeys;
			HotKeyIndentifier m_nextHotKeyIdentifier;

		};
	}
}
