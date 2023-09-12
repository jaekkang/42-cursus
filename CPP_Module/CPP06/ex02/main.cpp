#include "Base.hpp"

int main(void) {
  Base *a;
  Base *b;

  a = generate();
  b = generate();
  identify(a);
  identify(*b);

  delete a;
  delete b;
  //   system("leaks program");
}
