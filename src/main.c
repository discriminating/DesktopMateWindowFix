#include <windows.h>

static DWORD dwAttempts = 30;

BOOLEAN
WINAPI
DetermineStartup(
	VOID
)
{
	return GetTickCount64() < 60000; /* 60 seconds */
}

VOID
main(
	VOID
)
{
	HWND hWnd = 0;

	while (!hWnd && dwAttempts)
	{
		hWnd = FindWindowA(
			"UnityWndClass",
			"DesktopMate"
		);

		Sleep(DetermineStartup() ? 1000 : 400);

		dwAttempts--;
	}

	if (!hWnd)
	{
		DetermineStartup() ? "" : MessageBoxA(
			NULL,
			"DesktopMate not found",
			"Error",
			MB_ICONERROR
		);

		return;
	}

	/* Create a dummy owner window */
	HWND hOwner = CreateWindowExA(
		WS_EX_NOACTIVATE,
		"STATIC",
		"Dummy",
		0,
		0,
		0,
		0,
		0,
		NULL,
		0,
		0,
		0
	);

	if (!hOwner)
	{
		MessageBoxA(
			NULL,
			"Failed to create owner window",
			"Error",
			MB_ICONERROR
		);

		return;
	}

	/* Remove from taskbar */
	SetWindowLongPtr(
		hWnd,
		GWLP_HWNDPARENT,
		(LONG_PTR)hOwner
	);

	/* Fix the window style */
	SetWindowLong(
		hWnd,
		GWL_EXSTYLE,
		GetWindowLong(
			hWnd,
			GWL_EXSTYLE
		) & ~WS_EX_APPWINDOW | WS_EX_TOOLWINDOW
	);

	return;
}
