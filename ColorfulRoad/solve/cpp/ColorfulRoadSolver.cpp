#include <fstream>
#include <topcoder>
#include "ColorfulRoad.cpp"
namespace tc = TopCoder;

int main(int argc, char const *argv[]) {
  try {
    std::ifstream ifs(argv[1]);
    string road; tc::read(ifs, road);
    ifs.close();

    std::ofstream ofs(argv[2]);
    ColorfulRoad solver;
    tc::show(ofs, solver.getMin(road));
    ofs.close();
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
