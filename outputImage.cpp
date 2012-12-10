#include "myImageStruct.h"
#include <string>
#include <iostream>
#include <assert.h>

void SaveImage(const s_Image& image,const string filename)
{
    IplImage* img;

    img = cvCreateImage(cvSize(image.width,image.height),image.channelNum);
    assert(img != NULL);

    for(int i = 0; i < image.height; i++)
    {
	UCHAR* pimg = reinterpret_cast<UCHAR*>(img->imageData + img->widthStep * i);

	for(int j = 0; j < image.width * image.channelNum;j++)
	{
	    pimg[j] = image.data[i][j];
	}
    }
    cvSaveImage(filename.c_str(),img);
    cvReleaseImage(&img);
}

