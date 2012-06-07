#pragma once
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <al.h>
#include <alc.h>
#include <alut.h>


#define NUM_BUFFERS 1
#define NUM_SOURCES 1
#define NUM_ENVIRONMENTS 1


class Sound{

public:

	Sound();

	~Sound();

	void LoadSound(char* filename);

	void PlaySound();
	void StopSound();
	void PauseSound();
	void ResumeSound();

	void UpdateSound(float time);

	void SetSourcePosition(float x,float y,float z);
	void SetSourceVelocity(float x,float y,float z);
	void SetListenerPosition(float x,float y,float z);

private:

	// Listener
	ALfloat	listenerPos[3];
	ALfloat listenerVel[3];
	ALfloat listenerOri[6];
	
	// Source
	ALfloat	sourcePos[3];
	ALfloat	sourceVel[3];


	ALuint  Buffer;
	ALuint  Source;
	ALuint  environment[NUM_ENVIRONMENTS];

	ALsizei size,freq;
	ALenum  format;
	ALvoid  *data;
	ALboolean loop;


};