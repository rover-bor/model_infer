#include <iostream>
#include <vector>
#include <algorithm>
#include "Detector.h"
using namespace std;

struct Param
{
    /* super param for inference */
    const float conf_thres = 0.25f;
    const float iou_thres = 0.5f;
    vector<int> input_size = {640, 640};
};

Param sp_param;

int main(int argc, char* argv[]){
    const char* model_path = argv[1];
    const char* image_path = argv[2];
    cout << "model path: " << model_path << endl;
    cout << "image path: " << image_path << endl;
    cout << "initialize model ..." << endl;
    YOLODetector yolo_model(model_path);

    cout << "data preprocess ..." << endl;
    cv::Mat image = preProcess(image_path, sp_param.input_size);
    // cout << image.data << endl;
    // cout << "dims: " << image.dims << endl;
    // cout << "size: " << image.size << endl;
    // cout << image.step1(0) << endl;
    // cout << image.step1(1) << endl;
    // cout << image.step[0] << endl;
    // cout << image.step[1] << endl;
    // cout << image.elemSize() << endl;
    // cout << image.elemSize1() << endl;
    // double minVal, maxVal;
    // minMaxLoc(image, &minVal, &maxVal);
    // cout << minVal << endl;
    // cout << maxVal << endl;

    cout << "onnx inference ..." << endl;

    cout << "prediction postprocess ..." << endl;

    cout << "output and plot result ..." << endl;

    cout << "done!!!" << endl;

    return 0;
}