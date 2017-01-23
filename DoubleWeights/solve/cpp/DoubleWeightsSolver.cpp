#include <fstream>
#include <topcoder>
#include "DoubleWeights.cpp"
namespace tc = TopCoder;

int main(int argc, char const *argv[]) {
  try {
    std::ifstream ifs(argv[1]);
    vector<string> weight1; tc::read(ifs, weight1); tc::next(ifs);
    vector<string> weight2; tc::read(ifs, weight2);
    ifs.close();

    std::ofstream ofs(argv[2]);
    DoubleWeights solver;
    tc::show(ofs, solver.minimalCost(weight1, weight2));
    ofs.close();
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
