#ifndef __GAMESA_RENDERWARE
#define __GAMESA_RENDERWARE

#include "../GTASA/RenderWare.h"

/*****************************************************************************/
/** Renderware functions                                                    **/
/*****************************************************************************/

/* RenderWare macros */
#define RpGetFrame(__c)            ((RwFrame*)(((RwObject *)(__c))->parent))
#define RpSetFrame(__c,__f)        ((((RwObject *)(__c))->parent) = (void *)(__f))

/* RenderWare function defines */
typedef void					(__cdecl *RpMaterialSetTexture_t)				(RpMaterial * mat, RwTexture * tex);

typedef RpClump*				(__cdecl *RpClumpForAllAtomics_t)				(RpClump *clump, void* callback, void* pData);
typedef RpClump*				(__cdecl *RpGeometryForAllMaterials_t)			(RpGeometry *geometry, void* callback, void* pData);

#endif