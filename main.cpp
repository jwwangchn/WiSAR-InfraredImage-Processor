#include"InfraredProccesor.h"
#define SHOWIMG



int T_GRAY = 114;
int T_AREA_LOW = 68;
int T_AREA_UP = 128;
void onGrayChange(int a,void* b)
{
	;
}

void onAreaLowerChange(int a, void* b)
{
	;
}
void onAreaUpperChange(int a, void* b)
{
	;
}
int main(int argc, char ** argv)
{

 
	VideoCapture vcap;
	VideoWriter* videoWriter = NULL;


	namedWindow("ROI");

 
	createTrackbar("T_GRAY","ROI",&T_GRAY,255,onGrayChange);
	createTrackbar("T_AREA_LOW", "ROI", &T_AREA_LOW, 255, onAreaLowerChange);
	createTrackbar("T_AREA_UP", "ROI", &T_AREA_UP, 255, onAreaUpperChange);
	onGrayChange(T_GRAY,0);
	onAreaLowerChange(T_AREA_LOW,0);
	onAreaUpperChange(T_AREA_UP, 0);
	InfraredImageProcessor infraredImageProc;
	vcap.open("../Video/IR01.avi");
	Mat frame;
	Rect mROI;
	namedWindow("ROI", 1);
	VideoWriter output_cap("Video/IR01-result.avi", vcap.get(CV_CAP_PROP_FOURCC),
		vcap.get(CV_CAP_PROP_FPS),
		cv::Size(vcap.get(CV_CAP_PROP_FRAME_WIDTH),
		vcap.get(CV_CAP_PROP_FRAME_HEIGHT)));

	while ( vcap.isOpened())
	{
		vcap.read(frame);
		if (frame.empty()) continue;
		mROI = infraredImageProc.getProposalROI(frame,T_GRAY,T_AREA_LOW,T_AREA_UP);
	
#ifdef SHOWIMG
		imshow("ROI", frame);
		output_cap.write(frame);

		waitKey(100);
#endif

		

	}

	if (vcap.isOpened())
		vcap.release();
	if (videoWriter->isOpened())
		videoWriter->release();
	if (videoWriter)
		delete videoWriter;



	//    Mat src = imread("/home/kelfor/Desktop/IR_4.jpg");
	//    infraredImageProc.getProposalROI(src);
	//
	//    imshow("ROI",src);
	//    waitKey();

}
