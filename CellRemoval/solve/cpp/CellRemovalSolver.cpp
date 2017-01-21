#include <fstream>
#include <topcoder>
#include "CellRemoval.cpp"
namespace tc = TopCoder;

int main(int argc, char const *argv[]) {
  try {
    std::ifstream ifs(argv[1]);
    vector<int> parent; tc::read(ifs, parent); tc::next(ifs);
    int deletedCell; tc::read(ifs, deletedCell);
    ifs.close();

    std::ofstream ofs(argv[2]);
    CellRemoval solver;
    tc::show(ofs, solver.cellsLeft(parent, deletedCell));
    ofs.close();
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
