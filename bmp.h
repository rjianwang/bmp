/* \file bmp.h
 *  BMP image format
 *
 *  Author:	rjianwang
 *	Date:	2016-09-06
 *  Email:  rjianwang@foxmail.com
 */

#pragma once

#include <string>

typedef long			LONG;
typedef unsigned long	DWORD;
typedef int				BOOL;
typedef unsigned char   BYTE;
typedef unsigned short	WORD;
typedef BYTE			*LPBYTE;
typedef DWORD			*LPDWORD;


#pragma pack(1)
typedef struct tagRGBQUAD
{
	BYTE	rgbBlue;
	BYTE	rgbGreen;
	BYTE	rgbRed;
	BYTE	rgbReserved;
}RGBQUAD;

typedef struct  tagBITMAPFILEHEADER
{  
	WORD	bfType;				// 文件类型，必须是0x424D，即字符“BM”   
	DWORD	bfSize;				// 文件大小   
	WORD	bfReserved1;		// 保留字   
	WORD	bfReserved2;		// 保留字   
	DWORD	bfOffBits;			// 从文件头到实际位图数据的偏移字节数   
}BITMAPFILEHEADER;				// 位图文件头定义 

typedef struct tagBITMAPINFOHEADER
{  
	DWORD	biSize;				// 信息头大小   
	LONG	biWidth;			// 图像宽度   
	LONG	biHeight;			// 图像高度   
	WORD	biPlanes;			// 位平面数，必须为1   
	WORD	biBitCount;			// 每像素位数: 1, 2, 4, 8, 16, 24, 32
	DWORD	biCompression;		// 压缩类型   
	DWORD	biSizeImage;		// 压缩图像大小字节数   
	LONG	biXPelsPerMeter;	// 水平分辨率   
	LONG	biYPelsPerMeter;	// 垂直分辨率   
	DWORD	biClrUsed;			// 位图实际用到的色彩数   
	DWORD	biClrImportant;		// 本位图中重要的色彩数   
}BITMAPINFOHEADER;				// 位图信息头定义   
#pragma pack()

// class BMP
//
// BMP is an image file format that stores bitmap digital images and retains 
// information for each pixel of the image. The BMP format stores color data 
// for each pixel in the image without any compression. For example, a 10x10 
// pixel BMP image will include color data for 100 pixels. This method of 
// storing image information allows for crisp, high-quality graphics, but 
// also produces large file sizes. 
class BMP
{
	public:
		BMP();
		BMP(const std::string &location);

		~BMP();

	public:
		BYTE*	load(const std::string &location);
		void	save(const std::string &location);
	private:
		void	swap(BYTE **src, DWORD width, DWORD height, WORD channel);

	public:
		LONG	width();
		LONG	height();
		BYTE	depth();
		BYTE*	data();
		WORD	_channels();

	public:
		DWORD	rows;
		DWORD	cols;
		WORD	channels;

	private:
		BITMAPFILEHEADER	*head;  
		BITMAPINFOHEADER	*info;  
		RGBQUAD				*palette;   // color table
		BYTE				*pixels;	// iamge pixel data  

}; /* end for class BMP */
