#ifndef __CRENDERWARE
#define __CRENDERWARE

#include "gamesa_renderware.h"

class CRenderWare
{
public:
	CRenderWare();

	RpClumpForAllAtomics_t				RpClumpForAllAtomics;
	RpGeometryForAllMaterials_t			RpGeometryForAllMaterials;
	RpMaterialSetTexture_t				RpMaterialSetTexture;
};

#endif