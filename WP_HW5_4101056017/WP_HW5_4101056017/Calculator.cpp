/***************************
4101056017 邱冠喻 第五次作業 12/10
4101056017 Chiu Guan-Yu TheFifthHomework 12/10

This cpp file only contains main function,check out Calculator.h for my works
***************************/

#include "Calculator.h"
#include <windows.h>

using namespace WP_HW5_4101056017;

int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
              LPSTR lpStrCmdString, int nCmdShow)
{
    // Create, show and run the form, enabling visual styles on the fly
	Calculator^ gui = gcnew Calculator();
	
    System::Windows::Forms::Application::EnableVisualStyles();
    System::Windows::Forms::Application::Run( gcnew Calculator() );

    return 0;
}

/***************************
4101056017 邱冠喻 第五次作業 12/10
4101056017 Chiu Guan-Yu TheFifthHomework 12/10
***************************/