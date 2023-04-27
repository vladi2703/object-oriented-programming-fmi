/**
 * Забележка:
 * std::pair<Kеy, Value> e структура, която има два член-данни: first и second.
 * first е от тип Key, а second е от тип Value.
 * Това е имплементация на класа Pair от STL подобна на тази, която видяхме в
 * час.
 */
#include <exception>  // std::exception
#include <iostream>   // std::cout, std::endl
#include <utility>    // std::pair

constexpr int MAX_SIZE_ = 200;  // compile-time константа
template <typename Key, typename Value>
class Dictionary {
 public:
  Dictionary() : size_(0) {}

  void add(const Key& key, const Value& value) {
    for (int i = 0; i < size_; ++i) {
      if (data_[i].first == key) {
        data_[i].second = value;
        return;
      }
    }
    if (size_ < MAX_SIZE_) {
      data_[size_] = std::pair<Key, Value>(key, value);
      ++size_;
    }
  }

  bool remove(const Key& key) {
    for (int i = 0; i < size_; ++i) {
      if (data_[i].first == key) {
        --size_;
        data_[i] = data_[size_];
        return true;
      }
    }
    return false;
  }

  // Функция, която ни позволява следната операция dict[1] = "one";
  Value& operator[](const Key& key) {
    for (int i = 0; i < size_; ++i) {
      if (data_[i].first == key) {
        return data_[i].seconddk;
      }
    }
    if (size_ < MAX_SIZE_) {
      data_[size_] = std::pair<Key, Value>(key, Value());
      ++size_;
      return data_[size_ - 1].second;
    }
    throw std::exception();
  }

  const Value& operator[](const Key& key) const {
    for (int i = 0; i < size_; ++i) {
      if (data_[i].first == key) {
        return data_[i].second;
      }
    }
    throw std::exception();
  }

  bool contains(const Key& key) const {
    for (int i = 0; i < size_; ++i) {
      if (data_[i].first == key) {
        return true;
      }
    }
    return false;
  }

  void clear() { size_ = 0; }

  size_t size() const { return size_; }

 private:
  std::pair<Key, Value> data_[MAX_SIZE_];
  int size_;
};
