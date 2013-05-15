#include "ya2d_draw.h"




void ya2d_drawRect(int x, int y, int w, int h, u32 color)
{
	tiny3d_SetPolygon(TINY3D_LINE_LOOP);
		tiny3d_VertexColor(color);
		tiny3d_VertexPos(x, y, 65535);
		tiny3d_VertexPos(x, y+h, 65535);
		tiny3d_VertexPos(x+w, y+h, 65535);
		tiny3d_VertexPos(x+w, y, 65535);
	tiny3d_End();	
}

void ya2d_drawFillRect(int x, int y, int w, int h, u32 color)
{
	tiny3d_SetPolygon(TINY3D_TRIANGLE_STRIP);
		tiny3d_VertexColor(color);
		tiny3d_VertexPos(x, y, 65535);
		tiny3d_VertexPos(x, y+h, 65535);
		tiny3d_VertexPos(x+w, y, 65535);
		tiny3d_VertexPos(x+w, y+h, 65535);
	tiny3d_End();
}
