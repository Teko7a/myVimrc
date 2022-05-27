template <class T, class... Args> auto multivector(size_t n, Args &&...args) {
  if constexpr (sizeof...(args) == 1) {
    return std::vector<T>(n, args...);
  } else {
    return std::vector(n, multivector<T>(args...));
  }
}

