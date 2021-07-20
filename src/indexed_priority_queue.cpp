#include "indexed_priority_queue.hpp"
#include <vector>
#include <functional>
#include <queue>

// This is supposed to be a base that only operates on size_t keys
// thus removing the need for a bimap and only focusing on the
// heap-centric functionality of the structure.
// The _Priority type needs to be comparable.
template<typename _Priority, typename _Compare>
class _Base_IPQ {
  // sassert _Priority type has defined compare operators
  static_assert()

private:


  // CONSTRUCTORS
  _Base_IPQ() {}

  // void push(p) {
  // push new element with key size & priority p, size += 1
  //}

};

// This is the general IPQ definition
// Basically _Base_IPQ + bimap
// Will not support duplicate key values
template <typename _KTp, typename _PTp, typename _Sequence = std::vector<_Tp>,
          typename _Compare = std::less<_PTp>>
class indexed_priority_queue {

}

int main() {
  priority_queue<int> Q;
}