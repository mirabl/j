#include <fstream>
#include <topcoder>
#include "PillarsDivTwo.cpp"
namespace tc = TopCoder;

int main(int argc, char const *argv[]) {
  try {
    std::ifstream ifs(argv[1]);
    vector<int> height; tc::read(ifs, height); tc::next(ifs);
    int w; tc::read(ifs, w);
    ifs.close();

    std::ofstream ofs(argv[2]);
    PillarsDivTwo solver;
    tc::show(ofs, solver.maximalLength(height, w));
    ofs.close();
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
