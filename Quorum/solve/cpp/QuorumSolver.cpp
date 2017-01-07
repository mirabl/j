#include <fstream>
#include <topcoder>
#include "Quorum.cpp"
namespace tc = TopCoder;

int main(int argc, char const *argv[]) {
  try {
    std::ifstream ifs(argv[1]);
    vector<int> arr; tc::read(ifs, arr); tc::next(ifs);
    int k; tc::read(ifs, k);
    ifs.close();

    std::ofstream ofs(argv[2]);
    Quorum solver;
    tc::show(ofs, solver.count(arr, k));
    ofs.close();
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
