#ifndef __CTXDSTORE
#define __CTXDSTORE

#define FUNC_PushCurrentTxd						0x7316A0
#define FUNC_PopCurrentTxd						0x7316B0
#define FUNC_FindTxdSlot						0x731850
#define FUNC_SetCurrentTxd						0x7319C0
#define FUNC_AddTxdRef							0x731A00
#define FUNC_AddTxdSlot							0x731C80
#define FUNC_LoadTxd							0x7320B0

class CTxdStore
{
public:
	static void			PushCurrentTxd();
	static void			PopCurrentTxd();
	static int			FindTxdSlot(char *name);
	static void			SetCurrentTxd(int slot);
	static void			AddRef(int index);
	static int			AddTxdSlot(char *slotName);
	static void			LoadTxd(int slot, char *fp);
};

#endif