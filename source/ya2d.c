#include "ya2d_main.h"

/* Variables */
    //ya2d
        static u8  ya2d_inited = 0;
		u32* ya2d_textureMem = NULL;
		u32* ya2d_texturePointer = NULL;
	//User usable
/* Functions */


    int ya2d_init()
    {
        if(ya2d_inited) return 1;
        
		ioPadInit(7);
	//Tiny 3D
			tiny3d_Init(1024 * 1024);
			
			ya2d_textureMem = tiny3d_AllocTexture(64*1024*1024); 
			ya2d_texturePointer = ya2d_textureMem ;
			
			//Load default font
				ResetFont();
				ya2d_texturePointer =
				   (u32 *) AddFontFromBitmapArray((u8 *) msxfont, (u8 *) ya2d_texturePointer,  0, 254,  8,  8, 1, BIT7_FIRST_PIXEL);
				SetCurrentFont(YA2D_DEFAULT_FONT);
				SetFontColor(0xffffffff, 0x0);
				SetFontSize(8, 12);

		//Load modules
			sysModuleLoad(SYSMODULE_FS);
			sysModuleLoad(SYSMODULE_PNGDEC);
			sysModuleLoad(SYSMODULE_JPGDEC);
			
		ya2d_inited = 1;
        return 1;
    }


    int ya2d_deinit()
    {
		ioPadEnd();
		tiny3d_Exit();
		//Unload modules
			sysModuleUnload(SYSMODULE_FS);
			sysModuleUnload(SYSMODULE_PNGDEC);
			sysModuleUnload(SYSMODULE_JPGDEC);
			ya2d_inited = 0;
        return 1;
    }


	void ya2d_readControls()
	{
		
	}

	void ya2d_error(char *t)
	{
		ya2d_screenClear(RGB(0, 50, 255)); //BSoD
		DrawFormatString(15, 15, "%s%s", t, "   -   Press HOME to exit.");
		ya2d_screenFlip();
		while(1)
		{
			sysUsleep(500);
		}
	}
