#include <windows.h>
using namespace std;

#define HELP_MENU_DOUBLE 2
#define HELP_MENU_INTEGRAL 1
#define MENU_Exit 3

LRESULT CALLBACK WindowProcedure(HWND,UINT,WPARAM,LPARAM);

void AddMenus(HWND);
void AddControls(HWND);
void loadImages();

HMENU hMenu;
HWND hBG;
HBITMAP hBGImage,hLogoI,hLogoII,hExit; 

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args,int ncmdshow){
    WNDCLASSW wc = {0};

    wc.hbrBackground = (HBRUSH)COLOR_WINDOW ;
    wc.hCursor = LoadCursor(NULL,IDC_ARROW);
    wc.hInstance = hInst;
    wc.lpszClassName = L"Calculate";
    wc.lpfnWndProc =  WindowProcedure;  

    if(!RegisterClassW(&wc))
        return -1;

    CreateWindowW(L"Calculate",L"Calculate Integral",WS_MINIMIZEBOX|WS_SYSMENU|WS_VISIBLE,100,100,500,500,NULL,NULL,NULL,NULL);
    MSG msg = {0};

    while( GetMessage(&msg,NULL,NULL,NULL))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    } 
    return 0;
}

LRESULT CALLBACK WindowProcedure(HWND hwnd,UINT msg,WPARAM wp,LPARAM lp)
{
    int val;
    switch (msg)
    {
        case WM_COMMAND:

            switch (wp)
            {
                case HELP_MENU_DOUBLE:
                MessageBeep(MB_ICONINFORMATION);
                MessageBox(hwnd,"","Double Integral",MB_OK);
                break;
                case HELP_MENU_INTEGRAL:
                MessageBeep(MB_ICONINFORMATION);
                MessageBox(hwnd,"","Integral",MB_OK);
                break;
                case MENU_Exit:
                val = MessageBoxW(hwnd,L"Are you sure?",L"Message",MB_YESNO | MB_ICONWARNING);
                if(val==IDYES){
                    DestroyWindow(hwnd);
                }
                else if(val==IDNO){

                }
                break;
            }

            break;
        case WM_CREATE:
            loadImages();
            AddMenus(hwnd);
            AddControls(hwnd);
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            DefWindowProcW(hwnd,msg,wp,lp);
    }
}

void AddMenus(HWND hwnd)
{
    hMenu = CreateMenu();
    HMENU hHelpMenu = CreateMenu();
    AppendMenu(hHelpMenu,MF_STRING,HELP_MENU_INTEGRAL,"Integral");
    AppendMenu(hHelpMenu,MF_SEPARATOR,NULL,NULL);
    AppendMenu(hHelpMenu,MF_STRING,HELP_MENU_DOUBLE,"Space by Double Integral");
    
    AppendMenu(hMenu,MF_POPUP,(UINT_PTR)hHelpMenu,"Help");

    SetMenu(hwnd,hMenu);
}

void AddControls(HWND hwnd)
{
    hBG = CreateWindowW(L"Static",NULL,WS_VISIBLE|WS_CHILD|SS_BITMAP,0,0,0,0,hwnd,NULL,NULL,NULL);
    SendMessageW(hBG,STM_SETIMAGE,IMAGE_BITMAP,(LPARAM) hBGImage);
    HWND hButA = CreateWindowW(L"Button",L"INTEGRAL",WS_VISIBLE|WS_CHILD|BS_BITMAP,135,80,230,100,hwnd,NULL,NULL,NULL);
    SendMessageW(hButA,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM) hLogoI);
    HWND hButB = CreateWindowW(L"Button",L"DOUBLE INTEGRAL",WS_VISIBLE|WS_CHILD|BS_BITMAP,135,200,230,100,hwnd,NULL,NULL,NULL);
    SendMessageW(hButB,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM) hLogoII);
    HWND hButExit = CreateWindowW(L"Button",L"Exit",WS_VISIBLE|WS_CHILD|BS_BITMAP,200,340,100,50,hwnd,(HMENU) MENU_Exit,NULL,NULL);
    SendMessageW(hButExit,BM_SETIMAGE,IMAGE_BITMAP,(LPARAM) hExit);
}
    

void loadImages()
{
    hBGImage = (HBITMAP)LoadImageW(NULL,L"BG.bmp",IMAGE_BITMAP,492,450,LR_LOADFROMFILE);
    hLogoI = (HBITMAP)LoadImageW(NULL,L"LogoI.bmp",IMAGE_BITMAP,230,100,LR_LOADFROMFILE);
    hLogoII = (HBITMAP)LoadImageW(NULL,L"LogoII.bmp",IMAGE_BITMAP,230,100,LR_LOADFROMFILE);
    hExit = (HBITMAP)LoadImageW(NULL,L"Exit.bmp",IMAGE_BITMAP,100,50,LR_LOADFROMFILE);
}

