#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    // 读取图像
    Mat image = imread("/home/zqm/图片/截图/a.png");

    if(image.empty()) {
        cout << "Could not open or find the image" << endl;
        return -1;
    }

    // 获取图像的高度和宽度
    int height = image.rows;
    int width = image.cols;

    // 定义旋转角度（正值表示逆时针旋转）
    double angle = 45.0;

    // 计算旋转中心点
    Point2f center(static_cast<float>(width / 2), static_cast<float>(height / 2));

    // 获取旋转矩阵
    Mat rotation_matrix = getRotationMatrix2D(center, angle, 1.0);

    // 执行仿射变换
    Mat rotated_image;
    warpAffine(image, rotated_image, rotation_matrix, Size(width, height));

    // 显示原始图像和旋转后的图像
    namedWindow("Original Image", WINDOW_NORMAL);
    namedWindow("Rotated Image", WINDOW_NORMAL);

    imshow("Original Image", image);
    imshow("Rotated Image", rotated_image);

    waitKey(0);
    destroyAllWindows();

    return 0;
}
