#include "Detector.h"
#include "utils.h"
#include <algorithm>
#include <iostream>
#include <vector>

const double norm = 0.00392156862745098;


YOLODetector::YOLODetector(const char* model_path)
{
    env = Ort::Env(OrtLoggingLevel::ORT_LOGGING_LEVEL_WARNING, "ONNX_DETECTION");
    // sessionOptions = Ort::SessionOptions();
    session = Ort::Session(env, model_path, sessionOptions);
}


cv::Mat preProcess(const char* image_path, std::vector<int> img_size)
{
    cv::Mat image = cv::imread(image_path);
    cv::Mat image_resized = letterBox(image, img_size);
    // image = image_resized;
    // // std::cout << image.data << std::endl;
    // std::cout << image.size << std::endl;
    // std::cout << image.channels() << std::endl;
    // std::cout << image.step[0] << std::endl;
    // std::cout << image.step[1] << std::endl;
    // std::cout << image.elemSize() << std::endl;
    // std::cout << image.elemSize1() << std::endl;
    // plotImage(image_resized, false);
    // cv::cvtColor(image, image, cv::COLOR_BGR2RGB);
    // std::cout << image.dims << std::endl;
    cv::dnn::blobFromImage(image_resized, 1.0 / 255.0, image_resized.size(), cv::Scalar(0, 0, 0), true, false, CV_32F);
    // image_resized *= norm;
    return image_resized;
}


cv::Mat letterBox(cv::Mat image, const std::vector<int> img_size)
{
    float imw = image.size().width;
    float imh = image.size().height;
    float ratio = std::min(img_size[0]/imh, img_size[1]/imw);
    const cv::Size2d new_size = {imw*ratio, imh*ratio};
    cv::resize(image, image, new_size);
    int pad_w = (img_size[1] - new_size.width) / 2;
    int pad_h = (img_size[0] - new_size.height) / 2;
    cv::Scalar value(127, 127, 127);
    cv::copyMakeBorder( image, image, pad_h, pad_h, pad_w, pad_w, cv::BORDER_CONSTANT, value );
    return image;
}