#include <fstream>
#include <topcoder>
#include "JumpFurther.cpp"
namespace tc = TopCoder;

int main(int argc, char const *argv[]) {
  try {
    std::ifstream ifs(argv[1]);
    int N; tc::read(ifs, N); tc::next(ifs);
    int badStep; tc::read(ifs, badStep);
    ifs.close();

    std::ofstream ofs(argv[2]);
    JumpFurther solver;
    tc::show(ofs, solver.furthest(N, badStep));
    ofs.close();
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
