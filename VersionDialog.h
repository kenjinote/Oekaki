#pragma once
class VersionDialog
{
public:
	VersionDialog();
	~VersionDialog();

	static INT_PTR CALLBACK DialogProc(HWND hDlg, unsigned msg, WPARAM wParam, LPARAM lParam);

	INT_PTR ShowDialog(HWND hParent);
};

