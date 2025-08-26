#include <Windows.h>

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1200

HICON icons[] = {
    LoadIcon(NULL, IDI_ERROR),
    LoadIcon(NULL, IDI_WARNING),
    LoadIcon(NULL, IDI_INFORMATION),
    LoadIcon(NULL, IDI_QUESTION),
};

size_t s_icons = sizeof(icons) / sizeof(icons[0]);

void DrawIcons() {
    HWND hWnd = GetDesktopWindow();
    HDC hdc = GetWindowDC(hWnd);

    int x = 100;
    int y = 100;

    for (size_t i = 0; i < s_icons; ++i) {
        if (icons[i]) {
            DrawIcon(hdc, x, y, icons[i]);
            x += 100;
        }
    }

    ReleaseDC(hWnd, hdc);
}

int main() {
    DrawIcons();
    return 0;
}
