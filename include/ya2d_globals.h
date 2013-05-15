#ifndef _YA2D_GLOBALS_H_
#define _YA2D_GLOBALS_H_

#ifndef RGBA
	#define RGBA(r,g,b,a) ((r<<24) |(g<<16)|(b<<8)|(a))
#endif

#ifndef RGB
	#define RGB(r,g,b) RGBA(r,g,b,255)
#endif

#define YA2D_ERROR_BUFSIZE 256

#define YA2D_DEFAULT_FONT 0

extern u32* ya2d_textureMem;
extern u32* ya2d_texturePointer;
extern unsigned char msxfont[];

#endif
