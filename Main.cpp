#include <string>
#include <thread>

#include <Shlwapi.h>

int CALLBACK wWinMain(
	_In_ HINSTANCE hInstance,
	_In_ HINSTANCE hPrevInstance,
	_In_ LPTSTR     lpCmdLine,
	_In_ int       nCmdShow
	)
{
	if (lpCmdLine == TEXT("")) return 1;

	const std::wstring parameter(lpCmdLine);
	const auto position = parameter.find(L" ");
	if (position == std::wstring::npos) return 2;

	const auto root = parameter.substr(0, position);
	const auto key = parameter.substr(position + 1);

	if (root.empty() || key.empty()) return 3;

	while (true)
	{
		if (root == L"HKCU")
		{
			const auto result = SHDeleteKey(HKEY_CURRENT_USER, key.c_str());
		}
		else if (root == L"HKLM")
		{
			const auto result = SHDeleteKey(HKEY_LOCAL_MACHINE, key.c_str());
		}
		else if (root == L"HKCR")
		{
			const auto result = SHDeleteKey(HKEY_CLASSES_ROOT, key.c_str());
		}
		else if (root == L"HKU")
		{
			const auto result = SHDeleteKey(HKEY_USERS, key.c_str());
		}
		else if (root == L"HKCC")
		{
			const auto result = SHDeleteKey(HKEY_CURRENT_CONFIG, key.c_str());
		}
		else
		{
			return 4;
		}

		std::this_thread::sleep_for(std::chrono::seconds(5));
	}
}