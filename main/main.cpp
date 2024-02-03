#include "../includes.h"

void commandInput(const std::string& message) {
	for (char c : message) {
		short keyCode = VkKeyScanA(c);
		keybd_event(keyCode, MapVirtualKeyA(keyCode, 0), 0, 0);
		keybd_event(keyCode, MapVirtualKeyA(keyCode, 0), KEYEVENTF_KEYUP, 0);
		Sleep(50);
	}
}

void moveMouseTo(int x, int y) {
	INPUT input = { 0 };
	input.type = INPUT_MOUSE;
	input.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE;
	input.mi.dx = (LONG)((x * 65536) / GetSystemMetrics(SM_CXSCREEN));
	input.mi.dy = (LONG)((y * 65536) / GetSystemMetrics(SM_CYSCREEN));
	SendInput(1, &input, sizeof(INPUT));
}

int main() {
	static bool mode;
	std::cout << "" << std::endl;
	POINT cursorPos;

	HWND hwnd = nullptr;
	LPCWSTR message = L"Você deseja inciar o programa?";
	LPCWSTR title = L"MEMORY PIXELMON";
	UINT style = MB_YESNO | MB_ICONQUESTION;

	int a1 = MessageBox(hwnd, message, title, style);

	if (a1 == IDYES) {
		std::string comando1 = "pokeheal";
		std::string slash = "/";

		POINT currentMousePos;
		GetCursorPos(&currentMousePos);

		int screenWidth = GetSystemMetrics(SM_CXSCREEN);
		int screenHeight = GetSystemMetrics(SM_CYSCREEN);

		int centerX = screenWidth / 2;
		int centerY = screenHeight / 2;

		int x = 0;
		int y = 120;

		//int times_ptr;

		for (size_t t = 0; t < 50; t++) { // O PROGRAMA VAI FAZER 50 REPETIÇÕES

			/*std::cout << "COMECANDO EM ALGUNS SEGUNDOS..." << std::endl;*/

			Sleep(5000);

			SetCursorPos(centerX, centerY);

			keybd_event(VK_SPACE, MapVirtualKeyA(VK_SPACE, 0), 0, 0); //anti-afk (key down)
			Sleep(100);
			keybd_event(VK_SPACE, MapVirtualKeyA(VK_SPACE, 0), KEYEVENTF_KEYUP, 0); //anti-afk (key up)

			Sleep(1000);

			keybd_event(VK_ESCAPE, MapVirtualKeyA(VK_ESCAPE, 0), 0, 0); //menu

			Sleep(500);

			mouse_event(MOUSEEVENTF_MOVE, x, y, 0, 0);

			Sleep(300);

			SetCursorPos(centerX, centerY);

			Sleep(300);

			keybd_event(VK_ESCAPE, MapVirtualKeyA(VK_ESCAPE, 0), KEYEVENTF_KEYUP, 0); //menu

			Sleep(1000);

			keybd_event(VK_ESCAPE, MapVirtualKeyA(VK_ESCAPE, 0), 0, 0); //menu

			Sleep(100);

			keybd_event(VK_ESCAPE, MapVirtualKeyA(VK_ESCAPE, 0), KEYEVENTF_KEYUP, 0); //menu

			Sleep(2000);

			commandInput("R");

			Sleep(1000);

			SetCursorPos(centerX, centerY);

			Sleep(200);

			mouse_event(MOUSEEVENTF_MOVE, x, y, 0, 0);

			for (size_t i = 0; i < 50; i++)
			{
				Sleep(100);
				mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
				Sleep(100);
				mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
			}
			Sleep(1000);

			commandInput(slash); // init

			Sleep(100);

			commandInput(comando1); // pokeheal

			keybd_event(VK_RETURN, MapVirtualKeyA(VK_RETURN, 0), 0, 0);

			Sleep(1000);

			keybd_event(VK_RETURN, MapVirtualKeyA(VK_RETURN, 0), KEYEVENTF_KEYUP, 0);

			SetCursorPos(centerX, centerY);

		}


		return 0;
	}
}