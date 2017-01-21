#include <fstream>
#include <topcoder>
#include "ArcadeManao.cpp"
namespace tc = TopCoder;

int main(int argc, char const *argv[]) {
  try {
    std::ifstream ifs(argv[1]);
    vector<string> level; tc::read(ifs, level); tc::next(ifs);
    int coinRow; tc::read(ifs, coinRow); tc::next(ifs);
    int coinColumn; tc::read(ifs, coinColumn);
    ifs.close();

    std::ofstream ofs(argv[2]);
    ArcadeManao solver;
    tc::show(ofs, solver.shortestLadder(level, coinRow, coinColumn));
    ofs.close();
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
