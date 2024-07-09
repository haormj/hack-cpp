#include <ceres/ceres.h>

#include <iostream>
#include <opencv2/opencv.hpp>

struct CURVE_FITTING_COST {
  CURVE_FITTING_COST(double x, double y) : x_(x), y_(y) {}

  template <typename T>
  bool operator()(const T* const abc, T* residual) const {
    residual[0] = T(y_) - ceres::exp(abc[0] * x_ * x_ + abc[1] * x_ + abc[2]);
    return true;
  }

  const double x_, y_;
};

int main() {
  double ar = 1.0, br = 2.0, cr = 1.0;
  double ae = 2.0, be = -1.0, ce = 5.0;
  int N = 100;
  double sigma = 1.0;
  cv::RNG rng;

  std::vector<double> x_data, y_data;
  for (int i = 0; i < N; i++) {
    double x = i / 100.0;
    x_data.push_back(x);
    y_data.push_back(exp(ar * x * x + br * x + cr) +
                     rng.gaussian(sigma * sigma));
  }

  double abc[3] = {ae, be, ce};

  ceres::Problem problem;
  for (int i = 0; i < N; i++) {
    problem.AddResidualBlock(
        new ceres::AutoDiffCostFunction<CURVE_FITTING_COST, 1, 3>(
            new CURVE_FITTING_COST(x_data[i], y_data[i])),
        nullptr, abc);
  }

  ceres::Solver::Options options;
  options.linear_solver_type = ceres::DENSE_NORMAL_CHOLESKY;
  options.minimizer_progress_to_stdout = true;

  ceres::Solver::Summary summary;
  ceres::Solve(options, &problem, &summary);
  std::cout << summary.BriefReport() << std::endl;
  for (auto x : abc) {
    std::cout << x << std::endl;
  }

  return 0;
}