#include <fstream>
#include <topcoder>
#include "MazeWanderingEasy.cpp"
namespace tc = TopCoder;

int main(int argc, char const *argv[]) {
  try {
    std::ifstream ifs(argv[1]);
    vector<string> maze; tc::read(ifs, maze);
    ifs.close();

    std::ofstream ofs(argv[2]);
    MazeWanderingEasy solver;
    tc::show(ofs, solver.decisions(maze));
    ofs.close();
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
