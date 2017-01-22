#include <fstream>
#include <topcoder>
#include "RollingDiceDivTwo.cpp"
namespace tc = TopCoder;

int main(int argc, char const *argv[]) {
  try {
    std::ifstream ifs(argv[1]);
    vector<string> rolls; tc::read(ifs, rolls);
    ifs.close();

    std::ofstream ofs(argv[2]);
    RollingDiceDivTwo solver;
    tc::show(ofs, solver.minimumFaces(rolls));
    ofs.close();
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
