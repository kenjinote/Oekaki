#include <windows.h>
#include <uxtheme.h>
#include <vsstyle.h>
#include <vssym32.h>
#include "VersionDialog.h"
#include "resource.h"

VersionDialog::VersionDialog()
{
}

VersionDialog::~VersionDialog()
{
}

INT_PTR VersionDialog::DialogProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	static HFONT hFont;
	switch (msg)
	{
	case WM_INITDIALOG:
		{
			HTHEME hTheme = OpenThemeData(hWnd, VSCLASS_AEROWIZARD);
			LOGFONTW lf = { 0 };
			GetThemeFont(hTheme, NULL, AW_HEADERAREA, 0, TMT_FONT, &lf);
			hFont = CreateFontIndirectW(&lf);
			CloseThemeData(hTheme);
		}
		return TRUE;
	case WM_PAINT:
		{
			const int nDrawIconSize = 64;
			PAINTSTRUCT ps;
			HDC hdc = BeginPaint(hWnd, &ps);
			HICON hIcon = (HICON)LoadImage(GetModuleHandle(0), MAKEINTRESOURCE(IDI_ICON1), IMAGE_ICON, nDrawIconSize, nDrawIconSize, LR_DEFAULTCOLOR);
			DrawIconEx(hdc, 16, 16, hIcon, nDrawIconSize, nDrawIconSize, 0, 0, DI_NORMAL);
			DestroyIcon(hIcon);
			WCHAR szText[1024];
			LoadStringW(GetModuleHandle(0), IDS_STRING105, szText, _countof(szText));
			HFONT hOldFont = (HFONT)SelectObject(hdc, hFont);
			RECT rect;
			GetClientRect(hWnd, &rect);
			rect.left = 16 + nDrawIconSize + 16;
			rect.top = 16 + 8; // 8 ‚Í‚È‚ñ‚Æ‚È‚­
			int nOldBkMode = SetBkMode(hdc, TRANSPARENT);
			DrawText(hdc, szText, lstrlenW(szText), &rect, DT_NOCLIP);
			SetBkMode(hdc, nOldBkMode);
			SelectObject(hdc, hOldFont);
			EndPaint(hWnd, &ps);
		}
		break;
	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hWnd, LOWORD(wParam));
			return TRUE;
		}
		break;
	case WM_DESTROY:
		DeleteObject(hFont);
		break;
	}
	return FALSE;
}

INT_PTR VersionDialog::ShowDialog(HWND hParent)
{
	return DialogBox(GetModuleHandle(0), MAKEINTRESOURCE(IDD_DIALOG1), hParent, DialogProc);
}
