#include <fstream>
#include <topcoder>
#include "OrderOfOperationsDiv2.cpp"
namespace tc = TopCoder;

int main(int argc, char const *argv[]) {
  try {
    std::ifstream ifs(argv[1]);
    vector<string> s; tc::read(ifs, s);
    ifs.close();

    std::ofstream ofs(argv[2]);
    OrderOfOperationsDiv2 solver;
    tc::show(ofs, solver.minTime(s));
    ofs.close();
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
