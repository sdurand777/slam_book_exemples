#include <opencv2/opencv.hpp>
#include <string>

using namespace std;

string image_file = "./src/imageBasics/distorted.png";   // 请确保路径正确

int main(int argc, char **argv) {

  // coefficients of the camera model
  double k1 = -0.28340811, k2 = 0.07395907, p1 = 0.00019359, p2 = 1.76187114e-05;
  double fx = 458.654, fy = 457.296, cx = 367.215, cy = 248.375;

  cv::Mat image = cv::imread(image_file, 0);
  int rows = image.rows, cols = image.cols;
  cv::Mat image_undistort = cv::Mat(rows, cols, CV_8UC1);

  for (int v = 0; v < rows; v++) {
    for (int u = 0; u < cols; u++) {
      // move from pixel coordinates to normalized coordinates
      double x = (u - cx) / fx, y = (v - cy) / fy;
      // polar coordinates
      double r = sqrt(x * x + y * y);
      // distortion
      double x_distorted = x * (1 + k1 * r * r + k2 * r * r * r * r) + 2 * p1 * x * y + p2 * (r * r + 2 * x * x);
      double y_distorted = y * (1 + k1 * r * r + k2 * r * r * r * r) + p1 * (r * r + 2 * y * y) + 2 * p2 * x * y;
      // pixel coordinates distorted
      double u_distorted = fx * x_distorted + cx;
      double v_distorted = fy * y_distorted + cy;

      if (u_distorted >= 0 && v_distorted >= 0 && u_distorted < cols && v_distorted < rows) {
        image_undistort.at<uchar>(v, u) = image.at<uchar>((int) v_distorted, (int) u_distorted);
      } else {
        image_undistort.at<uchar>(v, u) = 0;
      }
    }
  }

  // 画图去畸变后图像
  cv::imshow("distorted", image);
  cv::imshow("undistorted", image_undistort);
  cv::waitKey();
  return 0;
}
