# include "flat_set.hh"

using namespace std;
int main(void)
{
  std::flat_set<int> fs;
  fs.insert(42);
  fs.insert(30);
  std::flat_set<int> fs2;
  fs2 = fs;

  return 0;
}
