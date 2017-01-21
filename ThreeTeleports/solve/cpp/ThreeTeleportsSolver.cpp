#include <fstream>
#include <topcoder>
#include "ThreeTeleports.cpp"
namespace tc = TopCoder;

int main(int argc, char const *argv[]) {
  try {
    std::ifstream ifs(argv[1]);
    int xMe; tc::read(ifs, xMe); tc::next(ifs);
    int yMe; tc::read(ifs, yMe); tc::next(ifs);
    int xHome; tc::read(ifs, xHome); tc::next(ifs);
    int yHome; tc::read(ifs, yHome); tc::next(ifs);
    vector<string> teleports; tc::read(ifs, teleports);
    ifs.close();

    std::ofstream ofs(argv[2]);
    ThreeTeleports solver;
    tc::show(ofs, solver.shortestDistance(xMe, yMe, xHome, yHome, teleports));
    ofs.close();
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
