// Demo73.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "LoveMoneyJARS.h"
#include <windowsX.h>
#include <winuser.h>
#include <commctrl.h>
#include<windows.system.h>
#pragma comment(linker,"\"/manifestdependency:type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#pragma comment(lib, "ComCtl32.lib")

#define MAX_LOADSTRING 100
void OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify);
void OnPaint(HWND hwnd);
void OnDestroy(HWND hwnd);
BOOL OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name

												// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);


HWND txtTienLuong;
HWND txtTienPhaiChi;
HWND txtTienTietKiem;
HWND txtTienGiaoDuc;
HWND txtTienTuDoTaiChinh;
HWND txtTienHuongThu;
HWND txtTienTuThien;

int APIENTRY _tWinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPTSTR    lpCmdLine,
	int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: Place code here.
	//InitCommonControls();

	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_LOVEMONEYJARS, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LOVEMONEYJARS));

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int)msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
//  COMMENTS:
//
//    This function and its usage are only necessary if you want this code
//    to be compatible with Win32 systems prior to the 'RegisterClassEx'
//    function that was added to Windows 95. It is important to call this function
//    so that the application will get 'well formed' small icons associated
//    with it.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDC_LOVEMONEYJARS));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_BTNFACE + 1);
	wcex.lpszMenuName = MAKEINTRESOURCE(IDC_LOVEMONEYJARS);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;

	hInst = hInstance; // Store instance handle in our global variable

	hWnd = CreateWindowEx(0, szWindowClass, L"LoveMoneyJARS",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, 500, 400, NULL, NULL, hInstance, NULL);

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		HANDLE_MSG(hWnd, WM_CREATE, OnCreate);
		HANDLE_MSG(hWnd, WM_COMMAND, OnCommand);
		HANDLE_MSG(hWnd, WM_PAINT, OnPaint);
		HANDLE_MSG(hWnd, WM_DESTROY, OnDestroy);

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	return 0;
}

// Message handler for about box.
/*
hDlg : handle dialog
message: type of message
wParam: pointer
*/
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}



BOOL OnCreate(HWND hWnd, LPCREATESTRUCT lpCreateStruct)
{
	INITCOMMONCONTROLSEX icc;
	icc.dwSize = sizeof(icc);
	icc.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&icc);

	// Lấy font hệ thống
	LOGFONT lf;
	GetObject(GetStockObject(DEFAULT_GUI_FONT), sizeof(LOGFONT), &lf);
	HFONT hFont = CreateFont(lf.lfHeight, lf.lfWidth,
		lf.lfEscapement, lf.lfOrientation, lf.lfWeight,
		lf.lfItalic, lf.lfUnderline, lf.lfStrikeOut, lf.lfCharSet,
		lf.lfOutPrecision, lf.lfClipPrecision, lf.lfQuality,
		lf.lfPitchAndFamily, lf.lfFaceName);
	// create windows

	HWND hwnd = CreateWindowEx(0, L"STATIC", L"Số tiền: ", WS_CHILD | WS_VISIBLE | SS_LEFT, 10, 10, 100, 40, hWnd, NULL, hInst, NULL);
	SendMessage(hwnd, WM_SETFONT, WPARAM(hFont), TRUE);

	hwnd = CreateWindowEx(0, L"BUTTON", L"Tính toán: ", WS_CHILD | WS_VISIBLE |BS_PUSHBUTTON|SS_LEFT, 320, 10, 100, 30, hWnd, (HMENU)IDC_BUTTON1, hInst, NULL);
	SendMessage(hwnd, WM_SETFONT, WPARAM(hFont), TRUE);

	hwnd = CreateWindowEx(0, L"STATIC", L"Tài khoản thu chi cần thiết: ", WS_CHILD | WS_VISIBLE | SS_LEFT, 10, 70, 100, 40, hWnd, NULL, hInst, NULL);
	SendMessage(hwnd, WM_SETFONT, WPARAM(hFont), TRUE);

	hwnd = CreateWindowEx(0, L"STATIC", L"Tài khoản tiết kiệm: ", WS_CHILD | WS_VISIBLE | SS_LEFT, 10, 110, 100, 40, hWnd, NULL, hInst, NULL);
	SendMessage(hwnd, WM_SETFONT, WPARAM(hFont), TRUE);

	hwnd = CreateWindowEx(0, L"STATIC", L"Tài khoản giáo dục: ", WS_CHILD | WS_VISIBLE | SS_LEFT, 10, 150, 100, 40, hWnd, NULL, hInst, NULL);
	SendMessage(hwnd, WM_SETFONT, WPARAM(hFont), TRUE);

	hwnd = CreateWindowEx(0, L"STATIC", L"Tài khoản tự do tài chính: ", WS_CHILD | WS_VISIBLE | SS_LEFT, 10, 190, 100, 40, hWnd, NULL, hInst, NULL);
	SendMessage(hwnd, WM_SETFONT, WPARAM(hFont), TRUE);

	hwnd = CreateWindowEx(0, L"STATIC", L"Tài khoản hưởng thụ: ", WS_CHILD | WS_VISIBLE | SS_LEFT, 10, 230, 100, 40, hWnd, NULL, hInst, NULL);
	SendMessage(hwnd, WM_SETFONT, WPARAM(hFont), TRUE);

	hwnd = CreateWindowEx(0, L"STATIC", L"Tài khoản từ thiện: ", WS_CHILD | WS_VISIBLE | SS_LEFT, 10, 270, 100, 40, hWnd, NULL, hInst, NULL);
	SendMessage(hwnd, WM_SETFONT, WPARAM(hFont), TRUE);

	txtTienLuong = CreateWindowEx(0, L"EDIT", L"", WS_CHILD | WS_VISIBLE | WS_BORDER | SS_LEFT | SS_CENTER, 110, 10, 200, 30, hWnd, NULL, hInst, NULL);
	SendMessage(txtTienLuong, WM_SETFONT, WPARAM(hFont), TRUE);
	
	txtTienPhaiChi = CreateWindowEx(0, L"STATIC", L"0", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_CENTER, 110, 70, 200, 30, hWnd, NULL, hInst, NULL);
	SendMessage(txtTienPhaiChi, WM_SETFONT, WPARAM(hFont), TRUE);

	txtTienTietKiem = CreateWindowEx(0, L"STATIC", L"0", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_CENTER, 110, 110, 200, 30, hWnd, NULL, hInst, NULL);
	SendMessage(txtTienTietKiem, WM_SETFONT, WPARAM(hFont), TRUE);

	txtTienGiaoDuc = CreateWindowEx(0, L"STATIC", L"0", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_CENTER, 110, 150, 200, 30, hWnd, NULL, hInst, NULL);
	SendMessage(txtTienGiaoDuc, WM_SETFONT, WPARAM(hFont), TRUE);

	txtTienTuDoTaiChinh = CreateWindowEx(0, L"STATIC", L"0", WS_CHILD | WS_VISIBLE | SS_LEFT| SS_CENTER, 110, 190, 200, 30, hWnd, NULL, hInst, NULL);
	SendMessage(txtTienTuDoTaiChinh, WM_SETFONT, WPARAM(hFont), TRUE);


	txtTienHuongThu = CreateWindowEx(0, L"STATIC", L"0", WS_CHILD | WS_VISIBLE | SS_CENTER | SS_LEFT, 110, 230, 200, 30, hWnd, NULL, hInst, NULL);
	SendMessage(txtTienHuongThu, WM_SETFONT, WPARAM(hFont), TRUE);


	txtTienTuThien = CreateWindowEx(0, L"STATIC", L"0", WS_CHILD | WS_VISIBLE |SS_CENTER| SS_LEFT , 110, 270, 200, 30, hWnd, NULL, hInst, NULL);
	SendMessage(txtTienTuThien, WM_SETFONT, WPARAM(hFont), TRUE);

	return true;
}

void OnCommand(HWND hWnd, int id, HWND hwndCtl, UINT codeNotify)
{
	WCHAR* buffer1 = NULL;
	WCHAR* bufferKQ = NULL;
	int size1;
	int tienLuong;
	switch (id)
	{
	case IDM_ABOUT:
		DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
		break;
	case IDM_EXIT:
		DestroyWindow(hWnd);
		break;
	case IDC_BUTTON1:
		size1 = GetWindowTextLength(txtTienLuong);
		buffer1 = new WCHAR[size1 + 1];
		bufferKQ = new WCHAR[255];

		GetWindowText(txtTienLuong, buffer1, size1 + 1);
		tienLuong = _wtoi(buffer1);

		if (tienLuong < 0) {
			wsprintf(bufferKQ, L" Thông tin đã nhập không đúng.");
			SetWindowText(txtTienPhaiChi, bufferKQ);
		}
		else {
			wsprintf(bufferKQ, L" %d", tienLuong*55/100);
			SetWindowText(txtTienPhaiChi, bufferKQ);

			wsprintf(bufferKQ, L" %d", tienLuong * 10 / 100);
			SetWindowText(txtTienTietKiem, bufferKQ);
			SetWindowText(txtTienGiaoDuc, bufferKQ);
			SetWindowText(txtTienTuDoTaiChinh, bufferKQ);
			SetWindowText(txtTienHuongThu, bufferKQ);
			
			wsprintf(bufferKQ, L" %d", tienLuong * 5 / 100);
			SetWindowText(txtTienTuThien, bufferKQ);
		}
		
		break;
	}

	if (!buffer1)
		delete[] buffer1;
	if (!bufferKQ)
		delete[] bufferKQ;

}

void OnPaint(HWND hWnd)
{
	PAINTSTRUCT ps;
	HDC hdc;
	hdc = BeginPaint(hWnd, &ps);
	// TODO: Add any drawing code here...
	EndPaint(hWnd, &ps);
}

void OnDestroy(HWND hwnd)
{
	PostQuitMessage(0);
}
