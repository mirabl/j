#include <fstream>
#include <topcoder>
#include "PathGameDiv2.cpp"
namespace tc = TopCoder;

int main(int argc, char const *argv[]) {
  try {
    std::ifstream ifs(argv[1]);
    vector<string> board; tc::read(ifs, board);
    ifs.close();

    std::ofstream ofs(argv[2]);
    PathGameDiv2 solver;
    tc::show(ofs, solver.calc(board));
    ofs.close();
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
