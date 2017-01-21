#include <fstream>
#include <topcoder>
#include "ConnectedComponentConstruction.cpp"
namespace tc = TopCoder;

int main(int argc, char const *argv[]) {
  try {
    std::ifstream ifs(argv[1]);
    vector<int> s; tc::read(ifs, s);
    ifs.close();

    std::ofstream ofs(argv[2]);
    ConnectedComponentConstruction solver;
    tc::show(ofs, solver.construct(s));
    ofs.close();
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
