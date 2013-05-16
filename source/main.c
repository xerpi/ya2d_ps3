#include <time.h>
#include <tiny3d.h>
#include "ya2d.h"
#include "pngsample_png.h"

#define SCREEN_W 848
#define SCREEN_H 512

s32 main(s32 argc, const char* argv[])
{
	ya2d_init();
	ya2d_Texture *texture = ya2d_loadPNGfromBuffer((void *)pngsample_png, pngsample_png_size);
	int x = 50, y = 100;
	int size = 50;
	float angle = 0.0f;
	while(1)
	{
		ya2d_screenClear();
		ya2d_screenBeginDrawing();
		ya2d_controlsRead();
		
		DrawFormatString(15, 15, "YA2D LIB -- by xerpi, thanks to deaphroat for testing ;)\nFPS: %.2f", ya2d_screenFPS());
		
		if(ya2d_paddata[0].BTN_RIGHT) x+=10;
		if(ya2d_paddata[0].BTN_LEFT)  x-=10;
		if(ya2d_paddata[0].BTN_DOWN)  y+=10;
		if(ya2d_paddata[0].BTN_UP)    y-=10;
		if(ya2d_paddata[0].BTN_CROSS)  ya2d_drawFillRect(200, 350, 100, 100, rand());
		
		if(x > (SCREEN_W-size)) x = SCREEN_W-size;
		if(x<0) x = 0;
		if(y > (SCREEN_H-size)) y = SCREEN_H-size;
		if(y<0) y = 0;
						
		
		ya2d_drawRotateTexture(texture, 50, 90, angle+= 0.05f);
		//ya2d_blitRotateTetxure(500, 310, angle, texture);
		
		ya2d_drawFillRect(x, y, size, size, 0xFF0000FF);
		
		DrawFormatString(450, 300, "MLG Bitchez");
		
		ya2d_screenFlip();
		if(ya2d_paddata[0].BTN_START) break;
	}
	ya2d_freeTexture(texture);
	ya2d_deinit();
	return 0;
}

