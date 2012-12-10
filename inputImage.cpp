#include "myImageStruct.h"
#include "cv.h"
#include <string>
#include <iostream>
#include <assert.h>

using namespace std;

void LoadImage(s_Image& myImage,const string filename)
{
    IplImage *inputImage;

    inputImage = cvLoadImage(filename.c_str(),-1);
    
    if(inputImage == NULL)
    {
	cerr<<filename<<"doesn't exist"<<endl;
	exit(1);
    }

    switch(inputImage->nChannels)
    {
	case 1:
	    {
		myImage.channelNum = 1;
		break;
	    }
	case 2:
	    {
		myImage.channelNum = 2;
		break;
	    }
	case 3:
	    {
		myImage.channelNum = 3;
		break;
	    }
	case 4:
	    {
		myImage.channelNum = 4;
		break;
	    }
    }

    myImage.width = inputImage->width;
    myImage.height = inputImage->height;
    assert(myImage.width >= 0 && myImage.height >= 0);

    myImage.storeBuf = new UCHAR[myImage.width * myImage.height * myImage.channelNum]();
    assert(myImage.storeBuf != NULL);
    
    myImage.data = new UCHAR*[myImage.height]();
    assert(myImage.data != NULL);

    for(int i = 0; i < myImage.height; i++)
    {
	myImage.data[i] = myImage.storeBuf[i * myImage.width * myImage.channelNum];
	UCHAR* pimg = reinterpret_cast<UCHAR*>(inputImage->imageData + inputImage->widthStep * i);
	for(int j = 0; j < myImage.width * myImage.channelNum; j++)
	{
	    myImage.data[i][j] =  pimg[j];
	}
    }

    cvReleaseImage(&inputImage);
}
