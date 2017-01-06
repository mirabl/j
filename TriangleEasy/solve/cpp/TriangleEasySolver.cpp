#include <fstream>
#include <topcoder>
#include "TriangleEasy.cpp"
namespace tc = TopCoder;

int main(int argc, char const *argv[]) {
  try {
    std::ifstream ifs(argv[1]);
    int n; tc::read(ifs, n); tc::next(ifs);
    vector<int> x; tc::read(ifs, x); tc::next(ifs);
    vector<int> y; tc::read(ifs, y);
    ifs.close();

    std::ofstream ofs(argv[2]);
    TriangleEasy solver;
    tc::show(ofs, solver.find(n, x, y));
    ofs.close();
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
