#include <windows.h>

// 窗口过程函数
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// 注册窗口类
	const char CLASS_NAME[] = "Sample Window Class";
	
	WNDCLASS wc = { };
	wc.lpfnWndProc = WindowProc;
	wc.hInstance = hInstance;
	wc.lpszClassName = CLASS_NAME;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	
	RegisterClass(&wc);
	
	// 创建窗口
	HWND hwnd = CreateWindowEx(
							   0,                              // 扩展窗口样式
							   CLASS_NAME,                     // 窗口类
							   "Learn to Program Windows",     // 窗口标题
							   WS_OVERLAPPEDWINDOW,            // 窗口样式
							   
							   // 位置和大小
							   CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
							   
							   NULL,       // 父窗口
							   NULL,       // 菜单
							   hInstance,  // 实例句柄
							   NULL        // 附加数据
							   );
	
	if (hwnd == NULL)
		return 0;
	
	// 显示窗口
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);
	
	// 消息循环
	MSG msg = { };
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	
	return 0;
}

// 窗口过程函数，处理消息
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_PAINT:
		{
			PAINTSTRUCT ps;
			HDC hdc = BeginPaint(hwnd, &ps);
			// 在这里绘制窗口
			FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW+1));
			EndPaint(hwnd, &ps);
		}
		return 0;
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
