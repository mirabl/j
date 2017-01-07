#include <fstream>
#include <topcoder>
#include "NonDeterministicSubstring.cpp"
namespace tc = TopCoder;

int main(int argc, char const *argv[]) {
  try {
    std::ifstream ifs(argv[1]);
    string A; tc::read(ifs, A); tc::next(ifs);
    string B; tc::read(ifs, B);
    ifs.close();

    std::ofstream ofs(argv[2]);
    NonDeterministicSubstring solver;
    tc::show(ofs, solver.ways(A, B));
    ofs.close();
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
