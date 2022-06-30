#ifndef __CSTATS
#define __CSTATS

#define FUNC_IncrementStat						0x55C180

class CStats
{
public:
	static void			IncrementStat(WORD statID, float value);
};

#endif