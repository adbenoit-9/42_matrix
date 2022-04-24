#include "../Vector.hpp"
#include "../Matrix.hpp"

int main() {
    Vector<double>   u = {0., 0., 0.};
    std::cout   << "{0., 0., 0.}" << std::endl
                << "norm_1 = " << u.norm_1() << std::endl
                << "norm = " << u.norm() << std::endl
                << "norm_inf = " << u.norm_inf() << std::endl
                << std::endl;
    
    u = {1., 2., 3.};
    std::cout   << "{1., 2., 3.}" << std::endl
                << "norm_1 = " << u.norm_1() << std::endl
                << "norm = " << u.norm() << std::endl
                << "norm_inf = " << u.norm_inf() << std::endl
                << std::endl;
    
    u = {-1., -2.};
    std::cout   << "{-1., -2.}" << std::endl
                << "norm_1 = " << u.norm_1() << std::endl
                << "norm = " << u.norm() << std::endl
                << "norm_inf = " << u.norm_inf() << std::endl
                << std::endl;
}
