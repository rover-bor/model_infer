#include "Detector.h"
#include "utils.h"


YOLODetector::YOLODetector(const char* model_path)
{
    env = Ort::Env(OrtLoggingLevel::ORT_LOGGING_LEVEL_WARNING, "ONNX_DETECTION");
    // sessionOptions = Ort::SessionOptions();
    session = Ort::Session(env, model_path, sessionOptions);
}


cv::Mat preProcess(const char* image_path, std::vector<int> img_size)
{
    cv::Mat image = cv::imread(image_path);
    cv::cvtColor(image, image, cv::COLOR_BGR2RGB);
    cv::Mat image_resized = letterBox(image, img_size);
    plotImage(image_resized, true);
    return image;
}


cv::Mat letterBox(cv::Mat image, std::vector<int> img_size)
{
    cv::Size img_size_cv = {640, 640};
    cv::resize(image, image, img_size_cv);
    return image;
}