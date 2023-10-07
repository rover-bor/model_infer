#include "utils.h"


void plotImage(cv::Mat image, bool show=false)
{
    if (show)
    {
        cv::imshow("image", image);
        cv::waitKey(0);
    }
    else
    {
        cv::imwrite("image.jpg", image);
    }
}