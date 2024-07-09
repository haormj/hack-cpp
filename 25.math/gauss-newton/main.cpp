#include <Eigen/Dense>
#include <iostream>
#include <opencv2/opencv.hpp>

int main() {
  double ar = 1.0, br = 2.0, cr = 1.0;
  double ae = 2.0, be = -1.0, ce = 5.0;
  int N = 100;
  double w_sigma = 1.0;
  double inv_sigma = 1 / w_sigma;
  cv::RNG rng;

  std::vector<double> x_data, y_data;
  for (int i = 0; i < N; i++) {
    double x = i / 100.0;
    x_data.push_back(x);
    y_data.push_back(exp(ar * x * x + br * x + cr) +
                     rng.gaussian(w_sigma * w_sigma));
  }

  int iterations = 100;
  double cost = 0, last_cost = 0;
  for (int i = 0; i < iterations; i++) {
    Eigen::Matrix3d H = Eigen::Matrix3d::Zero();
    Eigen::Vector3d b = Eigen::Vector3d::Zero();
    cost = 0;

    for (int j = 0; j < N; j++) {
      double xi = x_data[j], yi = y_data[j];
      double error = yi - exp(ae * xi * xi + be * xi + ce);
      Eigen::Vector3d J;
      J[0] = -xi * xi * exp(ae * xi * xi + be * xi + ce);
      J[1] = -xi * exp(ae * xi * xi + be * xi + ce);
      J[2] = -exp(ae * xi * xi + be * xi + ce);

      H += inv_sigma * inv_sigma * J * J.transpose();
      b += -inv_sigma * inv_sigma * error * J;
      cost += error * error;
    }

    Eigen::Vector3d dx = H.ldlt().solve(b);
    if (std::isnan(dx[0])) {
      std::cout << "result is nan" << std::endl;
      break;
    }

    if (i > 0 && cost >= last_cost) {
      std::cout << "iter: " << i << ", cost: " << cost
                << ", last_cost: " << last_cost << std::endl;
      break;
    }

    ae += dx[0];
    be += dx[1];
    ce += dx[2];

    last_cost = cost;
    std::cout << "a: " << ae << ", b: " << be << ", c: " << ce << std::endl;
  }
  return 0;
}