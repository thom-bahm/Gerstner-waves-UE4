#pragma once

class GerstnerWavesVars
{
public:

private:
	float WaveLength;
	float Amplitude;
	float Speed;
	float NumWaves;
	float Steepness;
	float array[2] Direction;

	inline float GetWaveLength{ return WaveLength; };
};