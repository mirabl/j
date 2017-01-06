#include <fstream>
#include <topcoder>
#include "GridSort.cpp"
namespace tc = TopCoder;

int main(int argc, char const *argv[]) {
  try {
    std::ifstream ifs(argv[1]);
    int n; tc::read(ifs, n); tc::next(ifs);
    int m; tc::read(ifs, m); tc::next(ifs);
    vector<int> grid; tc::read(ifs, grid);
    ifs.close();

    std::ofstream ofs(argv[2]);
    GridSort solver;
    tc::show(ofs, solver.sort(n, m, grid));
    ofs.close();
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
