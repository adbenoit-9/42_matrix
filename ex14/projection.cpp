#include "../Vector.hpp"
#include "../Matrix.hpp"

ft::Matrix<double> projection(double fov, double ratio, double near, double far) {
    ft::Matrix<double> proj(4, 4, 0);

    proj[0][0] = 1 / (ratio * tan(fov * 0.5));
    proj[1][1] = 1 / tan(fov * 0.5);
    proj[2][2] = -(far + near) / (far - near);
    proj[3][2] = -(2 * far * near) / (far - near);
    proj[2][3] = -1;
    return proj;
}

int main() {
    ft::Matrix<double> p = projection(90, 0.8, 0.1, 100);
    for (size_t i = 0; i < 4; i++) {
        for (size_t j = 0; j < 4; j++) {
            if (j != 0)
                std::cout << ", ";
            std::cout << p[i][j];
        }
        std::cout << std::endl;
    }
}
