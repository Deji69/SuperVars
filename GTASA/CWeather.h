#ifndef __CWEATHER
#define __CWEATHER

#define	VAR_AmountOfRain			*(float*)	0xC81324

class CWeather
{
public:
	static	bool		IsRaining();
};

#endif