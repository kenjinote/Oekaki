#include <windows.h>
#include "VersionDialog.h"
#include "resource.h"

VersionDialog::VersionDialog()
{
}


VersionDialog::~VersionDialog()
{
}

INT_PTR VersionDialog::DialogProc(HWND hDlg, unsigned msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_INITDIALOG:
		//CenterWindow(hDlg);
		return TRUE;
	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return TRUE;
		}
		break;
	}
	return FALSE;
}

INT_PTR VersionDialog::ShowDialog(HWND hParent)
{
	return DialogBox(GetModuleHandle(0), MAKEINTRESOURCE(IDD_DIALOG1), hParent, DialogProc);
}
