// OpenALWrapper.cpp : definisce il punto di ingresso dell'applicazione console.
//

#include "stdafx.h"
#include "sound.h"
#include <Windows.h>

int _tmain(int argc, _TCHAR* argv[])
{		
	alutInit(NULL, 0);

	HKL hkl =LoadKeyboardLayoutW(L"00000410",KLF_ACTIVATE); // 00000410 codice tastira italiana

	Sound* sound = new Sound();

	short pause = VkKeyScanExW('p', hkl );
	short resume = VkKeyScanExW('r', hkl );

	sound->LoadSound("FancyPants.wav");

	while( !GetAsyncKeyState( VK_ESCAPE ) ){

		if (audioWrapper->IsPlaing())
		{
			
		}



		if (GetAsyncKeyState( pause ) && !audioWrapper->IsPaused() && !audioWrapper->IsStopped() )
		{
			wprintf( L"\nKey Pause pressed: ");
			

		}

		if (GetAsyncKeyState( resume ) && audioWrapper->IsPaused())
		{
			wprintf( L"\nKey Resume pressed: ");
			

		}

		if (GetAsyncKeyState( VK_RETURN ) && !audioWrapper->IsPlaing() )
		{
			wprintf( L"\nKey Play pressed: ");

			

			//audioWrapper1->PlayAudio();


		}

		if (GetAsyncKeyState(VK_DELETE) && !audioWrapper->IsStopped() )
		{
			wprintf( L"\nKey Stop pressed:");
			

		}


		if (GetAsyncKeyState(VK_LEFT))
		{
			
		}

		if (GetAsyncKeyState(VK_RIGHT))
		{
			
		}

		if (GetAsyncKeyState(VK_UP))
		{
			
		}

		if (GetAsyncKeyState(VK_DOWN))
		{
			
		}
	}
	return 0;
}

