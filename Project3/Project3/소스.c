#include <Windows.h>
#include <tchar.h>
#include "../Project3/resource.h"


LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

BOOL CALLBACK Dlg1(HWND hDlg, UINT iMSG, WPARAM wParam, LPARAM lParam); //��ȭ����1
BOOL CALLBACK Dlg2(HWND hDlg, UINT iMSG, WPARAM wParam, LPARAM lParam); //��ȭ����2
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

//��ȭ����1
BOOL CALLBACK Dlg1(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	switch (iMsg)
	{
	case WM_INITDIALOG: //ó�� �����ɶ� �ƹ� �ϵ� ���� �ʰ� �Լ� ����
		return 1;
	case WM_COMMAND: 
		switch (LOWORD(wParam))
		{
		case IDOK: //Ȯ�ι�ư 
			EndDialog(hDlg, 0); //��ȭ���� ����
			break;
		case IDCANCEL: //��ҹ�ư
			EndDialog(hDlg, 0);
			break;
		}
		break;
	}
	return 0;
}

//��ȭ����2
BOOL CALLBACK Dlg2(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	switch (iMsg)
	{
	case WM_INITDIALOG: //ó�� �����ɶ� �ƹ� �ϵ� ���� �ʰ� �Լ� ����
		return 1;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDOK: //Ȯ�ι�ư 
			EndDialog(hDlg, 0); //��ȭ���� ����
			break;
		case IDCANCEL: //��ҹ�ư
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
			_T("BUTTON"), //��ư ��Ʈ���� ������ Ŭ���� �̸�
			_T("��ư"), //��ư ��Ʈ���� ĸ��
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, //�����Ǵ� ������� �ڽ� �������̰� ������ ��ư����
			210,
			90, //�θ� �������� ��ǥ
			150,
			40, //��ư ũ�� �ʺ�*����
			hwnd, //�θ� ������ �ڵ�
			(HMENU)0, //��ư ��Ʈ�� id
			hInst, //Ŀ���� �ο��� ���α׷��� �ν��Ͻ���
			NULL //�����Ǵ� �����츦 ���� �ΰ�����
		);

			CreateWindow(
				_T("BUTTON"), //��ư ��Ʈ���� ������ Ŭ���� �̸�
				_T("��ư"), //��ư ��Ʈ���� ĸ��
				WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, //�����Ǵ� ������� �ڽ� �������̰� ������ ��ư����
				210,
				150, //�θ� �������� ��ǥ
				150,
				40, //��ư ũ�� �ʺ�*����
				hwnd, //�θ� ������ �ڵ�
				(HMENU)1, //��ư ��Ʈ�� id
				hInst, //Ŀ���� �ο��� ���α׷��� �ν��Ͻ���
				NULL //�����Ǵ� �����츦 ���� �ΰ�����
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
