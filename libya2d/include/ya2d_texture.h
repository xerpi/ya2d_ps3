#ifndef _YA2D_TEXTURE_H_
#define _YA2D_TEXTURE_H_


#include <tiny3d.h>
#include <malloc.h>
#include <string.h>
#include <pngdec/pngdec.h>
#include <jpgdec/jpgdec.h>



#include "ya2d_main.h"
#include "ya2d_utils.h"
#include "ya2d_globals.h"

#define YA2D_TEXTURE_SLICE 32

typedef struct
{
	int imageWidth, imageHeight;
	int textureWidth, textureHeight;
	int centerX, centerY;
    uint32_t rowBytes, dataLength;
	void *rel_ptr, *data; //data is absolute VRAM pointer
	int bitDepth, colorType, format;
	u32 textureOffset;
	uint8_t hasAlpha, isSwizzled;
}ya2d_Texture;



ya2d_Texture* ya2d_createTexture(int w, int h, int format);
void ya2d_swizzleTexture(ya2d_Texture *texp);
inline void ya2d_setTexture(ya2d_Texture *texp);

ya2d_Texture* ya2d_loadPNGfromFile(char* filename);
ya2d_Texture* ya2d_loadPNGfromBuffer(void *buffer, u32 buf_size);
ya2d_Texture* ya2d_loadJPGfromFile(char* filename);
ya2d_Texture* ya2d_loadJPGfromBuffer(void *buffer, u32 buf_size);

void ya2d_drawTexture(ya2d_Texture *texp, int x, int y);
void ya2d_drawBlendTexture(ya2d_Texture *texp, int x, int y, u32 color);
void ya2d_drawRotateTexture(ya2d_Texture *texp, int x, int y, float angle);


void ya2d_freeTexture(ya2d_Texture *texp);

#endif
