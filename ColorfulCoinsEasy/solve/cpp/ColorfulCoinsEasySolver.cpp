#include <fstream>
#include <topcoder>
#include "ColorfulCoinsEasy.cpp"
namespace tc = TopCoder;

int main(int argc, char const *argv[]) {
  try {
    std::ifstream ifs(argv[1]);
    vector<int> values; tc::read(ifs, values);
    ifs.close();

    std::ofstream ofs(argv[2]);
    ColorfulCoinsEasy solver;
    tc::show(ofs, solver.isPossible(values));
    ofs.close();
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
