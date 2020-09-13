#include <functional>
#include <algorithm>

template <class ForwardIt, class BinaryPredicate>
ForwardIt my_adjacent_find(ForwardIt first, ForwardIt last, BinaryPredicate p) {
  if (first == last) return last;

  ForwardIt next = first;
  ++next;
  for (; next != last; ++next, ++first) {
    if (p(*first, *next)) {
      return first;
    }
  }
  return last;
}

template <class ForwardIt>
ForwardIt my_adjacent_find(ForwardIt first, ForwardIt last) {
  typedef typename std::iterator_traits<ForwardIt>::value_type _v;
  return my_adjacent_find(first, last, std::equal_to<_v>());
}

template <class ForwardIt, class BinaryPredicate>
ForwardIt my_unique(ForwardIt first, ForwardIt last, BinaryPredicate p) {
  first = my_adjacent_find(first, last, p);
  if (first == last) return last;

  ForwardIt result = first;
  ++first;
  while (++first != last) {
    if (!p(*result, *first)) {
      *++result = std::move(*first);
    }
  }
  return ++result;
}

template <class ForwardIt>
ForwardIt my_unique(ForwardIt first, ForwardIt last) {
  typedef typename std::iterator_traits<ForwardIt>::value_type _v;
  return my_unique(first, last, std::equal_to<_v>());
}

template <class ForwardIt, class BinaryPredicate>
ForwardIt my_unique_slow(ForwardIt first, ForwardIt last, BinaryPredicate p) {
  if (first == last) return last;

  ForwardIt result = first;
  while (++first != last) {
    if (!p(*result, *first) && ++result != first) {
      *result = std::move(*first);
    }
  }
  return ++result;
}

template <class ForwardIt>
ForwardIt my_unique_slow(ForwardIt first, ForwardIt last) {
  typedef typename std::iterator_traits<ForwardIt>::value_type _v;
  return my_unique_slow(first, last, std::equal_to<_v>());
}

template <class ForwardIt>
ForwardIt my_rotate(ForwardIt first, ForwardIt n_first, ForwardIt last) {
  if (first == n_first) return last;
  if (n_first == last) return first;

  ForwardIt read = n_first;
  ForwardIt write = first;
  ForwardIt next_read = first; // Read position for when read hits last

  while (read != last) {
    if (write == next_read) next_read = read; // Track where first went
    std::iter_swap(write++, read++);
  }

  // Rotate the remaining sequence
  (my_rotate)(write, next_read, last);
  return write;
}