#pragma once
class VersionDialog
{
public:
	VersionDialog();
	~VersionDialog();
	static INT_PTR CALLBACK DialogProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam);
	INT_PTR ShowDialog(HWND hParent);
};

