#include <windows.h>

VOID
main(
	VOID
)
{
	HWND hWnd = FindWindowA(
		NULL,
		"DesktopMate"
	);

	if (!hWnd)
	{
		MessageBoxA(
			NULL,
			"DesktopMate not found",
			"Error",
			MB_ICONERROR
		);

		return;
	}

	LONG_PTR dwStyle = GetWindowLongPtrA(
		hWnd,
		GWL_STYLE
	);

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

	/* Fix specially for RetroBar */
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