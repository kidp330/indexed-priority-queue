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
  friend class indexed_priority_queue;
  using _st = vector<_Priority>::size_type;

  // id -> priority
  std::vector<_Priority> _priorities;
  // _heap: node -> id
  // _heap_position: id -> node
  // these vectors are inverse maps of each other
  std::vector<_st> _heap, _heap_position;
  _Compare comp;

  _Base_IPQ(const std::vector<_Priority>& s, const _Compare& c)
  : _priorities(s), comp(c) {
    _heap.resize(size());
    _heap_position.resize(size());

    std::iota(_heap.begin(), heap.end(), 0);
    std::make_heap(_heap.begin(), _heap.end(), id_compare);
    for (_st i = 0, n = size(); i < n; ++i)
      _heap_position[_heap[i]] = i;
  }

  // think up a better name
  bool id_compare(const _st& a, const _st& b) const {
    return comp(_priorities[a], _priorities[b]);
  }

  inline _st size() const {
    return _priorities.size();
  }
  inline _st parent(const _st& v) const {
    return (v - 1) >> 1;
  }
  inline _st lchild(const _st& v) const {
    return (v << 1) + 1;
  }
  inline _st rchild(const _st& v) const {
    return (v << 1) + 2;
  }

  void push(const _Priority& p) {
    _heap.push_back(size());
    _heap_position.push_back(heap_push());
    _priorities.push_back(p);
  }

  // Fix swim & sink to also update _heap_position
  void swim(_st& v) {
    for (p = parent(v); 
         id_compare(_heap[p], _heap[v]);
         p = parent(v)) {
      swap(_heap[p], _heap[v]);
      v = p;
    }
  }

  void sink(_st& v) {
    for (_st l = lchild(v), r = rchild(v);
         id_compare(_heap[v], _heap[l]) || id_compare(_heap[v], _heap[r]);
         _st l = lchild(v), r = rchild(v)) {
      
      _st smaller = l;
      if (!id_compare(_heap[l], _heap[r]))
        smaller = r;
      
      swap(_heap[v], _heap[smaller]);
      v = smaller;
    }
  }

  _st heap_push() {
    _st node = size()-1;
    swim(node);
    return node;
  }



};

// This is the general IPQ definition
// Basically _Base_IPQ + bimap
// Will not support duplicate key values
template <typename _Key, typename _Priority, typename _Sequence = std::vector<_Priority>,
          typename _Compare = std::less<_Priority>>
class indexed_priority_queue {

};

int main() {
  std::priority_queue<int> Q;
}