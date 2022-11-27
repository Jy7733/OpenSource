#include <Windows.h>
#include <tchar.h>
#include "../Project3/resource.h"


LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

BOOL CALLBACK Dlg1(HWND hDlg, UINT iMSG, WPARAM wParam, LPARAM lParam); //대화상자1
BOOL CALLBACK Dlg2(HWND hDlg, UINT iMSG, WPARAM wParam, LPARAM lParam); //대화상자2
HINSTANCE hInst;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdline, int nCmdShow)
{
	HWND hwnd;
	MSG msg;
	WNDCLASS WndClass;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	WndClass.lpfnWndProc = WndProc;
	hInst = hInstance;
	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hInstance = hInstance;
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.lpszMenuName = NULL;
	WndClass.lpszClassName = _T("Window Class Name");
	RegisterClass(&WndClass);
	hwnd = CreateWindow(_T("Window Class Name"),
		_T("DIARY"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL
	);

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return (int)msg.wParam;
}

//대화상자1
BOOL CALLBACK Dlg1(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	switch (iMsg)
	{
	case WM_INITDIALOG: //처음 생성될때 아무 일도 하지 않고 함수 끝냄
		return 1;
	case WM_COMMAND: 
		switch (LOWORD(wParam))
		{
		case IDOK: //확인버튼 
			EndDialog(hDlg, 0); //대화상자 삭제
			break;
		case IDCANCEL: //취소버튼
			EndDialog(hDlg, 0);
			break;
		}
		break;
	}
	return 0;
}

//대화상자2
BOOL CALLBACK Dlg2(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	switch (iMsg)
	{
	case WM_INITDIALOG: //처음 생성될때 아무 일도 하지 않고 함수 끝냄
		return 1;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDOK: //확인버튼 
			EndDialog(hDlg, 0); //대화상자 삭제
			break;
		case IDCANCEL: //취소버튼
			EndDialog(hDlg, 0);
			break;
		}
		break;
	}
	return 0;
}




LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;

	switch (iMsg)
	{
	case WM_CREATE:
		CreateWindow(
			_T("BUTTON"), //버튼 컨트롤의 윈도우 클래스 이름
			_T("버튼"), //버튼 컨트롤의 캡션
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, //생성되는 윈도우는 자식 윈도우이고 누르는 버튼형태
			210,
			90, //부모 윈도우의 좌표
			150,
			40, //버튼 크기 너비*높이
			hwnd, //부모 윈도우 핸들
			(HMENU)0, //버튼 컨트롤 id
			hInst, //커널이 부여한 프로그램의 인스턴스값
			NULL //생성되는 윈도우를 위한 부가정보
		);

			CreateWindow(
				_T("BUTTON"), //버튼 컨트롤의 윈도우 클래스 이름
				_T("버튼"), //버튼 컨트롤의 캡션
				WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, //생성되는 윈도우는 자식 윈도우이고 누르는 버튼형태
				210,
				150, //부모 윈도우의 좌표
				150,
				40, //버튼 크기 너비*높이
				hwnd, //부모 윈도우 핸들
				(HMENU)1, //버튼 컨트롤 id
				hInst, //커널이 부여한 프로그램의 인스턴스값
				NULL //생성되는 윈도우를 위한 부가정보
		);
		return 0;
		break;


	case WM_COMMAND :
		switch (LOWORD(wParam))
		{
		case 0 :
			hdc = GetDC(hwnd);
			DialogBox(hInst, MAKEINTRESOURCE(IDD1), hwnd, Dlg1);
			break;
		case 1 :
			hdc = GetDC(hwnd);
			DialogBox(hInst, MAKEINTRESOURCE(IDD1), hwnd, Dlg2);
			break;
		}
		
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps); 
		TextOut(hdc, 200, 60, _T("PHOTO DIARY"), _tcslen(_T("PHOTO DIARY")));
		EndPaint(hwnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}
