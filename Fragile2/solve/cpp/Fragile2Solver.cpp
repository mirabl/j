#include <fstream>
#include <topcoder>
#include "Fragile2.cpp"
namespace tc = TopCoder;

int main(int argc, char const *argv[]) {
  try {
    std::ifstream ifs(argv[1]);
    vector<string> graph; tc::read(ifs, graph);
    ifs.close();

    std::ofstream ofs(argv[2]);
    Fragile2 solver;
    tc::show(ofs, solver.countPairs(graph));
    ofs.close();
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
