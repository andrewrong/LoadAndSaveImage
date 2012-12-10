#ifndef MYIMAGESTRUCT_H
#define MYIMAGESTRUCT_H
#define UINT32 int
#define UCHAR  unsigned char
struct s_Image
{
    UINT32 width;
    UINT32 height;
    UINT32 channelNum;
    UCHAR* storeBuf; 
    UCHAR** data;
};
typedef struct s_Image s_Image;
#endif
