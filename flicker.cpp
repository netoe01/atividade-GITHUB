#include <iostream>
#include <stdlib.h>
#include <windows.h>

struct Desktop
{
public:

    int maxx = 0;
    int maxy = 0;

    Desktop()
    {
        this->GetDesktopResolution(this->maxx,this->maxy);
    }
    void GetDesktopResolution(int &horizontal , int& vertical)
    {
        RECT desktop;
        // Get a handle to the desktop window
        const HWND hDesktop = GetDesktopWindow();
        // Get the size of screen to the variable desktop
        GetWindowRect(hDesktop, &desktop);
        // The top left corner will have coordinates (0,0)
        // and the bottom right corner will have coordinates
        // (horizontal, vertical)
        horizontal = desktop.right;
        vertical = desktop.bottom;
    }

};

struct Mouse
{
public:
    int x;
    int y;

    Mouse()
    {
        this->getMousePos();
    }

    void getMousePos()
    {
        POINT mouse;

        GetCursorPos(&mouse);

        this->x = mouse.x;
        this->y = mouse.y;
    }

    bool verifyValidPosition(int x, int y, int maxx, int maxy)
    {
        if ((x > 0 && y > 0) && (x < maxx && y < maxy))
            return true;
        return false;
    }

    void flickCursor(Mouse *mouse,Desktop *desktop)
    {
        desktop->GetDesktopResolution(desktop->maxx,desktop->maxy);
        while (true)
        {
            SetCursorPos(rand() % desktop->maxx,rand() % desktop->maxy);
        }
    }
};

int main() 
{
    FreeConsole();
    Mouse mouse;
    Desktop desktop;

	/*
		POSSIBLE RESULTS!

        IDABORT      Abort button was selected.
        IDCANCEL     Cancel button was selected.
        IDCONTINUE   Continue button was selected.
        IDIGNORE     Ignore button was selected.
        IDNO         No button was selected.
        IDOK         OK button was selected.
        IDRETRY      Retry button was selected.
        IDTRYAGAIN   Try Again button was selected.
        IDYES        Yes button was selected.
	*/

    

	int getResult = MessageBox(NULL, L"The following program could be considered malware, do you want to run it?", L"Mouse Flicker!", MB_OKCANCEL);
        
    switch (getResult) 
    {
        case IDOK:
            mouse.flickCursor(&mouse, &desktop);
            break;

        case IDCANCEL:
            MessageBox(NULL, L"The program will exit!", L"Mouse Flicker", MB_OK);
            break;
        default:
            std::cout << "A undefined option! BUGGGGGGGGGG" << std::endl;
    };
  
	return 0;
}
