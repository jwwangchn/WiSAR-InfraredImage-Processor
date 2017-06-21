#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;

class InfraredImageProcessor
{

public:
	InfraredImageProcessor();
	~InfraredImageProcessor();
	Rect getProposalROI(Mat &src_, int , int , int );

private:
	Rect mROI;

};

