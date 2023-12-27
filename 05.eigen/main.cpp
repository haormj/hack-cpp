#include <iostream>
#include <Eigen/Dense>

int main() {
	Eigen::Vector3d v(1, 2, 3);
	// 定义向量
	std::cout << "v:" << v << std::endl;
	// 归一化
	auto normalized_v = v.normalized();
	std::cout << "normalized_v: " << normalized_v  << std::endl;
	// 归一化之后，L2范数为0
	std::cout << "l2: " << normalized_v.norm() << std::endl;

	// 求两个向量之间的夹角, 下面这两个向量明显是正交的，所以他们的夹角为 90°
	// a · b = ||a|| ||b|| cos𝜽
	// cos𝜽 = (a · b) / (||a|| ||b||)
	// 𝜽 = arccos((a · b) / (||a|| ||b||))
	Eigen::Vector3d v1(1, 0, 0);
	Eigen::Vector3d v2(0, 1, 0);
	auto v1_v2_rad = acos(v1.dot(v2)/(v1.norm()*v2.norm()));
	std::cout << "向量夹角弧度：" << v1_v2_rad << std::endl;
	std::cout << "向量夹角度数：" << v1_v2_rad * 180 / M_PI << std::endl;

	return 0;
}