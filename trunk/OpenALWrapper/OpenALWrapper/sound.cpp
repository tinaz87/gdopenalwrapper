#include "stdafx.h"
#include "sound.h"



Sound::Sound(){
	
	// Initialize OpenAL and clear the error bit.

	alutInit(NULL, 0);
	alGetError();


	listenerPos[0] =-2;
	listenerPos[1] = 0;
	listenerPos[2] = 0;


	listenerVel[0] = 0;
	listenerVel[1] = 0;
	listenerVel[2] = 0;

	listenerOri[0] = listenerOri[1] = 0;
	listenerOri[2] = -1.0f;
	listenerOri[3] = 0.0f;
	listenerOri[4] = 1.0f;
	listenerOri[5] = 0.0f;


	sourcePos[0] = -2.0f;
	sourcePos[1] = sourcePos[2] = 0;

	sourceVel[0] = sourceVel[1] = sourceVel[2] = 0;

	alListenerfv(AL_POSITION,listenerPos);
	alListenerfv(AL_VELOCITY,listenerVel);
	alListenerfv(AL_ORIENTATION,listenerOri);

	alGetError(); // clear any error messages

	
	



}

Sound::~Sound(){

	alDeleteSources(1,&Source);
	alDeleteBuffers(1,&Buffer);

	ALCcontext* Context=alcGetCurrentContext();

	//Get device for active context
	ALCdevice* Device=alcGetContextsDevice(Context);

	//Disable context
	alcMakeContextCurrent(NULL);

	//Release context(s)
	alcDestroyContext(Context);

	//Close device
	alcCloseDevice(Device);

}


void Sound::LoadSound(char* filename){

	// Generate buffers, or else no sound will happen!
	// Load wav data into a buffer.

	alGenBuffers(1, &Buffer);

	if(alGetError() != AL_NO_ERROR)
		return ;

	
	alutLoadWAVFile(filename, &format, &data, &size, &freq, &loop);
	alBufferData(Buffer, format, data, size, freq);
	alutUnloadWAV(format, data, size, freq);

	// Bind the buffer with the source.

	alGenSources(1, &Source);

	if(alGetError() != AL_NO_ERROR)
		return ;

	alSourcei (Source, AL_BUFFER,   Buffer   );
	alSourcef (Source, AL_PITCH,    1.0      );
	alSourcef (Source, AL_GAIN,     1.0      );
	alSourcefv(Source, AL_POSITION, sourcePos);
	alSourcefv(Source, AL_VELOCITY, sourceVel);
	alSourcei (Source, AL_LOOPING,  loop     );

	// Do another error check and return.

	if(alGetError() != AL_NO_ERROR)
		return ;



}

void Sound::UpdateSound(float time){

	
	

}

void Sound::SetListenerPosition(float x,float y,float z){

	listenerPos[0] = x;
	listenerPos[1] = y;
	listenerPos[2] = z;
}


void Sound::SetSourcePosition(float x,float y,float z){

	sourcePos[0] = x;
	sourcePos[1] = y;
	sourcePos[2] = z;

	alSourcefv(Source, AL_POSITION, sourcePos);
}

void Sound::SetSourceVelocity(float x,float y,float z){


	sourceVel[0] = x;
	sourceVel[1] = y;
	sourceVel[2] = z;

	alSourcefv(Source, AL_VELOCITY, sourceVel);
}


void Sound::PlaySound(){

	alSourcePlay(Source);

}

void Sound::StopSound(){

	alSourceStop(Source);
	alSourceRewind(Source);
	
}

void Sound::PauseSound(){

	alSourcePause(Source);
}

void Sound::ResumeSound(){

	Sound::PlaySound();
}