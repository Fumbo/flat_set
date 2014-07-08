# include "flat_set.hh"
# include <iostream>

using namespace std;
int main(void)
{
  std::flat_set<int> fs;
  fs.insert(2);
  fs.insert(1);
  fs.insert(3);
  std::flat_set<int> fs2 = flat_set<int>(fs);
  for (auto it : fs2)
    std::cout << it << '\n';

  return 0;
}
