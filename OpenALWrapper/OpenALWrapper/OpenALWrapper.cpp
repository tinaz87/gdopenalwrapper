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

	wprintf( L"\n-Press ENTER to Play ");
	wprintf( L"\n-Press CANC to Stop  ");
	wprintf( L"\n-Press P to Pause  ");
	wprintf( L"\n-Press R or ENTER  to Resume\n");

	wprintf( L"\n-Press LEFT ARROW to move the listener to the left from the source ");
	wprintf( L"\n-Press RIGHT ARROW to move the listener to the right from the source ");

	wprintf( L"\n-Press UP ARROW to increase Volume ");
	wprintf( L"\n-Press DOWN ARROW to decrease Volume ");

	wprintf( L"\n-Press O to increase Pitch ");
	wprintf( L"\n-Press L to decrease Pitch ");

	wprintf( L"\n-Press A to move the Source to the left from the Listener ");
	wprintf( L"\n-Press D to move the Source to the right from the Listener ");

	wprintf( L"\n-Press T to Reset Volume ");
	wprintf( L"\n-Press Y to Reset Pitch ");
	

	short pause = VkKeyScanExW('p', hkl );
	short resume = VkKeyScanExW('r', hkl );
	short left = VkKeyScanExW('a', hkl );
	short right = VkKeyScanExW('d', hkl );
	short pitchUp = VkKeyScanExW('o', hkl );
	short pitchDown = VkKeyScanExW('l', hkl );
	short resVolume = VkKeyScanExW('t', hkl );
	short resPitch = VkKeyScanExW('y', hkl );

	sound->LoadSound("../Wavs/MusicMono.wav");

	sound->LoopSound(true);

	while( !GetAsyncKeyState( VK_ESCAPE ) ){

		if (GetAsyncKeyState( pause ) && !sound->isPaused() && !sound->isStopped() )
		{
			wprintf( L"\nKey Pause pressed");

			sound->Pause();
		}

		if (GetAsyncKeyState( resume ) && sound->isPaused())
		{
			wprintf( L"\nKey Resume pressed");
			
			sound->Resume();
		}

		if (GetAsyncKeyState( VK_RETURN ) && !sound->isPlaying() )
		{
			wprintf( L"\nKey Play pressed");		

			sound->Play();
		}

		if (GetAsyncKeyState(VK_DELETE) && !sound->isStopped() && sound->isPlaying() )
		{
			wprintf( L"\nKey Stop pressed");
			
			sound->Stop();
		}

		if (GetAsyncKeyState(VK_LEFT))
		{
			sound->TranslateListenerPosition(-0.00001f,0,0);
			
		}

		if (GetAsyncKeyState(VK_RIGHT))
		{
			sound->TranslateListenerPosition(0.00001f,0,0);
			
		}

		if (GetAsyncKeyState( left ))
		{
			sound->TranslateSourcePosition(-0.00001f,0,0);
		}

		if (GetAsyncKeyState( right ))
		{
			sound->TranslateSourcePosition(0.00001f,0,0);
		}

		if (GetAsyncKeyState(VK_UP))
		{
			sound->IncreaseVolume();
		}

		if (GetAsyncKeyState(VK_DOWN))
		{
			sound->DecreaseVolume();
		}

		if (GetAsyncKeyState( pitchUp ))
		{
			sound->IncreasePitch();
		}

		if (GetAsyncKeyState( pitchDown ))
		{
			sound->DecreasePitch();
		}

		if (GetAsyncKeyState( resVolume ))
		{
			sound->ResetVolume();
		}

		if (GetAsyncKeyState( resPitch ))
		{
			sound->ResetPitch();
		}
	}
	return 0;
}

