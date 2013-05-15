#include "ya2d_main.h"

/* Variables */
    //GU
    //Frame counting
        static unsigned int ya2d_frameCount = 0;
        static clock_t ya2d_currentTime = 0, ya2d_lastTime = 0, ya2d_deltaTime = 0;
        static float   ya2d_FPS = 0.0f;
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
				ya2d_textureMem =
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

    float ya2d_getFPS()
    {
		return ya2d_FPS;
	}

	void ya2d_readControls()
	{
		
	}

	void ya2d_error(char *t, ...)
	{
		va_list args;
		va_start(args, t);
		char buffer[YA2D_ERROR_BUFSIZE];
		vsnprintf(buffer, YA2D_ERROR_BUFSIZE, t, args);
		ya2d_screenClear(RGB(0, 50, 255)); //BSoD
		printf(buffer);
		printf("   -   Press HOME to exit.");
		ya2d_screenFlip();
		while(1)
		{
			//usleep(100);
		}
	}
