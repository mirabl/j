#include <fstream>
#include <topcoder>
#include "AlphabetOrderDiv2.cpp"
namespace tc = TopCoder;

int main(int argc, char const *argv[]) {
  try {
    std::ifstream ifs(argv[1]);
    vector<string> words; tc::read(ifs, words);
    ifs.close();

    std::ofstream ofs(argv[2]);
    AlphabetOrderDiv2 solver;
    tc::show(ofs, solver.isOrdered(words));
    ofs.close();
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
