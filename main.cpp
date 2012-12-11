#include "myImageStruct.h"
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    int testcaseNum = 0;
    string inputFilename;
    string outputFilename;
    string testFilename = "./testcase";

    ifstream inf(testFilename.c_str(),ios_base::in);
    if(!inf)
    {
	cerr<<"open file - "<<testFilename<<" error"<<endl;
	return -1;
    }

    inf>>testcaseNum;
    if(testcaseNum < 0)
    {
	cerr<<"testcase mustn't be less than 0"<<endl;
	return -1;
    }
    
    s_Image* imageArray = new s_Image[testcaseNum]();

    for(int i = 0; i < testcaseNum; i++)
    {
	inf>>inputFilename;
	inf>>outputFilename;
	MyLoadImage(imageArray[i],inputFilename);
	MySaveImage(imageArray[i],outputFilename);
    }

    for(int i = 0; i < testcaseNum; i++)
    {
	delete[] imageArray[i].storeBuf;
	delete[] imageArray[i].data;
    }
    delete[] imageArray;

    return 0;
}
