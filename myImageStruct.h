#ifndef MYIMAGESTRUCT_H
#define MYIMAGESTRUCT_H
#define UINT32 int
#define UCHAR  unsigned char
#include <string>

struct s_Image
{
    UINT32 width;
    UINT32 height;
    UINT32 channelNum;
    UCHAR* storeBuf; 
    UCHAR** data;
};
typedef struct s_Image s_Image;

extern void MyLoadImage(s_Image& image,const std::string& filename);
extern void MySaveImage(const s_Image& image,const std::string& filename);
#endif
