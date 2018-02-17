#include "types.h"
#include "registers.h"
#include "instructions.h"
#include "mrrm.h"
#include "files.h"

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

es32 main(void)
{

    es32 fSize = 0;
    es8 fName[64] = "tests/testfile01.exe";
    eu8 *pMem = NULL;

    fSize = e_fileOpenAndRead(fName, pMem);
    if (0 >= fSize)
    {
        printf("failed to open and read %s\n", fName);
        exit(1);
    }
    // now we have all the bytes :D

    eFileStructure fStructure = {0};
    e_fileProcess(&fStructure, pMem);

    // process file to find instructions section
    // pByte = some_function_call();
    // this condition is not going to be correct since we will skip some bytes

    eStatement statement;
	es32 bytes_processed = 0;
	es32 bytes_read = 0;
    while (bytes_processed < bytes_read)
    {
        memset(&statement, 0, sizeof(statement));
        // statement = process_instruction(pByte);
        // post_statement(statement);
    }
    
    return 0;
    
}

// compile with: /D_UNICODE /DUNICODE /DWIN32 /D_WINDOWS /c

#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>
#include "window.h"





// The main window class name.
static TCHAR szWindowClass[] = _T("Esrever");

// The string that appears in the application's title bar.
static TCHAR szTitle[] = _T("Esrever");

HINSTANCE hInst;

// Forward declarations of functions included in this code module:
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int CALLBACK WinMain(
	_In_ HINSTANCE hInstance,
	_In_ HINSTANCE hPrevInstance,
	_In_ LPSTR     lpCmdLine,
	_In_ int       nCmdShow
)
{

	WNDCLASSEX wcex = { 0 };
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, IDI_APPLICATION);

	if (!RegisterClassEx(&wcex))
	{
		MessageBox(NULL,
			_T("Call to RegisterClassEx failed!"),
			_T("Esrever"),
			NULL);

		return 1;
	}

	// Store instance handle in our global variable
	hInst = hInstance;

	// The parameters to CreateWindow explained:
	// szWindowClass: the name of the application
	// szTitle: the text that appears in the title bar
	// WS_OVERLAPPEDWINDOW: the type of window to create
	// CW_USEDEFAULT, CW_USEDEFAULT: initial position (x, y)
	// initial size (width, length)
	// NULL: the parent of this window
	// NULL: this application does not have a menu bar
	// hInstance: the first parameter from WinMain
	// NULL: not used in this application
	HWND hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, WINDOW_WIDTH, WINDOW_HEIGHT,
		NULL, NULL, hInstance, NULL);

	if (!hWnd)
	{
		MessageBox(NULL,
			_T("Call to CreateWindow failed!"),
			_T("Windows Desktop Guided Tour"),
			NULL);

		return 1;
	}

	// hWnd: the value returned from CreateWindow
	// nCmdShow: the fourth parameter from WinMain
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	// Main message loop:
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;

}

//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	TCHAR greeting[] = _T("thisismyapplication");

	RECT r1 =
	{
		.left = 20,
		.top = 20,
		.right = 400,
		.bottom = 100,
	};



	LPCWSTR s1 = (LPCWSTR)malloc(256 * sizeof(WCHAR));
	memset(s1, 0, 256 * sizeof(WCHAR));
	swprintf(s1, 256, L"0x%lx\t%x %x %x\t%s\t%s %s",
		0x80001234, 0xc3, 0xc2, 0x10, L"mov", L"eax", L"0x12");



	

	switch (message)
	{
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		// Here your application is laid out.
		// For this introduction, we just print out "Hello, Windows desktop!"
		// in the top left corner.
		DrawText(hdc, s1, -1, &r1, DT_CENTER | DT_EXPANDTABS);

		TextOut(hdc,
			50, 50,
			greeting, _tcslen(greeting));
		// End application-specific layout section.

		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}

	return 0;

}
