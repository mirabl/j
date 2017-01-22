#include <fstream>
#include <topcoder>
#include "BoxesDiv2.cpp"
namespace tc = TopCoder;

int main(int argc, char const *argv[]) {
  try {
    std::ifstream ifs(argv[1]);
    vector<int> candyCounts; tc::read(ifs, candyCounts);
    ifs.close();

    std::ofstream ofs(argv[2]);
    BoxesDiv2 solver;
    tc::show(ofs, solver.findSize(candyCounts));
    ofs.close();
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
