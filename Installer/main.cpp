#include <windows.h>
#include <filesystem>
#include <iostream>
#include <optional>
#include <string>
#include <vector>

namespace fs = std::filesystem;

static std::optional<fs::path> steamPathFromRegistry() {
    wchar_t value[32768]{};
    DWORD size = sizeof(value);
    DWORD type = 0;

    const LONG status = RegGetValueW(
        HKEY_CURRENT_USER,
        L"Software\\Valve\\Steam",
        L"SteamPath",
        RRF_RT_REG_SZ,
        &type,
        value,
        &size
    );

    if (status != ERROR_SUCCESS) return std::nullopt;
    return fs::path(value);
}

static bool isTf2Install(const fs::path& path) {
    return fs::exists(path / L"tf_win64.exe") &&
           fs::exists(path / L"tf") &&
           fs::exists(path / L"bin");
}

int wmain() {
    std::wcout << L"TF2 Admin Tools - installation detector\n";
    std::wcout << L"This utility does not modify or inject into the game.\n\n";

    const auto steam = steamPathFromRegistry();
    if (!steam) {
        std::wcerr << L"Steam installation was not found in the current user's registry.\n";
        return 1;
    }

    std::wcout << L"Steam: " << steam->wstring() << L"\n";

    const std::vector<fs::path> candidates = {
        *steam / L"steamapps/common/Team Fortress 2",
        *steam / L"steamapps/common/Team Fortress 2 (64-bit)"
    };

    for (const auto& candidate : candidates) {
        if (isTf2Install(candidate)) {
            std::wcout << L"TF2 detected: " << candidate.wstring() << L"\n";
            std::wcout << L"No files were changed.\n";
            return 0;
        }
    }

    std::wcout << L"TF2 was not found in the default Steam library.\n";
    std::wcout << L"Additional Steam library folders will be supported in a later version.\n";
    return 2;
}
