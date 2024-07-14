#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    // 打开视频文件
    VideoCapture cap("/home/zqm/公共的/1.mp4");

    // 检查视频是否成功打开
    if (!cap.isOpened()) {
        cerr << "Error: Could not open video file." << endl;
        return -1;
    }

    // 创建窗口以显示视频
    namedWindow("Video Player", WINDOW_NORMAL);

    while (true) {
        Mat frame;
        // 从视频流中读取帧
        if (!cap.read(frame)) {
            cerr << "Error: Could not read frame." << endl;
            break;
        }

        // 显示帧
        imshow("Video Player", frame);

        // 按ESC键退出
        if (waitKey(30) == 27) {
            break;
        }
    }

    // 释放视频流和窗口
    cap.release();
    destroyAllWindows();

    return 0;
}
