#ifndef __CDOOR
#define __CDOOR

//006f47e0      public: FLOAT __thiscall CDoor::GetAngleOpenRatio(void)const 
#define FUNC_GetAngleOpenRatio      0x6F47E0
//006f4800      public: bool __thiscall CDoor::IsClosed(void)const 
#define FUNC_IsClosed               0x6F4800
//006f4820      public: bool __thiscall CDoor::IsFullyOpen(void)const 
#define FUNC_IsFullyOpen            0x6F4820
//006f4790      public: void __thiscall CDoor::Open(FLOAT)
#define FUNC_Open                   0x6F4790

class CDoor		// sizeof: 0x18
{
public:
    FLOAT m_fOpenAngle;
    FLOAT m_fClosedAngle;
    // got 2 8bit vars next so might as well make this 16bit and get more flags
    WORD m_nDirn;
    BYTE m_nAxis;
    BYTE m_nDoorState;
    // simulation variables
    FLOAT m_fAngle;
    FLOAT m_fPrevAngle;
    FLOAT m_fAngVel;
};

#endif