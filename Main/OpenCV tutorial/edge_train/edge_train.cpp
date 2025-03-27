#include "edge_train.h"

int edge_train()
{
    VideoCapture cap("train (1).mp4");

    Mat img;
    Mat gray_img;
    Mat img_gaus;
    Mat img_canny;


    cap >> img;
    imshow("img", img);

    cvtColor(img, gray_img, COLOR_BGR2GRAY);
    imshow("gray", gray_img);

    GaussianBlur(gray_img, img_gaus, Size(5, 5), 1, 1);
    imshow("gaus", img_gaus);

    Canny(img_gaus, img_canny, 20, 100);
    imshow("canny", img_canny);

    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    findContours(img_canny, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

    double maxLength = 0;
    Rect longestBox;

    for (const auto& contour : contours) {
        double length = arcLength(contour, true);
        if (length > maxLength) {
            maxLength = length;
            longestBox = boundingRect(contour);
        }
    }

    Mat result;
    cvtColor(img_canny, result, COLOR_GRAY2BGR);
    if (maxLength > 0) {
        rectangle(result, longestBox, Scalar(0, 255, 0), 2);
    }

    imshow("result", result);

    waitKey(0);

    return 0;
}