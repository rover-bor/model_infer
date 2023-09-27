#include <opencv2/opencv.hpp>
#include <onnxruntime_cxx_api.h>
#include <vector>


struct DetectRes
{
    /* data */
    cv::Rect boxes;
    float conf;
    int cls_id;
};


class YOLODetector
{
public:
    YOLODetector(const char* model_path);

    // ~YOLODetector();

private:
    Ort::Env env{nullptr};
    Ort::SessionOptions sessionOptions{nullptr};
    Ort::Session session{nullptr};
};


cv::Mat preProcess(const char* image_path, std::vector<int> img_size);
cv::Mat letterBox(cv::Mat, std::vector<int> img_size);
