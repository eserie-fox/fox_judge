#include <bits/stdc++.h>

//断言接下来是换行
inline void assert_endl(){
  char ch;
  while(std::cin.get(ch)){
    if (ch == '\n' || ch == '\r') {
      while (std::cin.peek() == '\n' || std::cin.peek() == '\r')
        std::cin.get(ch);
      return;
    }
    assert(("Not endl", ch == ' '));
  }
  assert(("No endl", false));
}

//断言接下来没有换行
inline void assert_no_endl() {
  char ch;
  while ((ch = std::cin.peek()) != EOF) {
    assert(("Is endl", (ch != '\n' && ch != '\r')));
    if (ch == ' ') {
      std::cin.get(ch);
      continue;
    } else {
      break;
    }
  }
}

//读入一个数x，范围在[l, r]之间。
template <typename T>
inline void readin(T& x, T l, T r) {
  assert_no_endl();
  std::cin >> x;
  assert(l <= x);
  assert(x <= r);
}

//读入一个数x，范围在[l, r]之间，且之后换行。
template <typename T>
inline void readinln(T& x, T l, T r) {
  assert_no_endl();
  readin(x, l, r);
  assert_endl();
}

//读入一串字符串，并且string长度在[len_l, len_r]范围内。
inline void readin(std::string& str, std::size_t len_l, std::size_t len_r) {
  assert_no_endl();
  std::cin >> str;
  assert(len_l <= str.size());
  assert(str.size() <= len_r);
}

//读入一串字符串，并且string长度在[len_l, len_r]范围内，且之后换行。
inline void readinln(std::string& str, std::size_t len_l, std::size_t len_r) {
  assert_no_endl();
  readin(str, len_l, len_r);
  assert_endl();
}

// 读入一行，并且string长度在[len_l, len_r]范围内
inline void readline(std::string& str, std::size_t len_l, std::size_t len_r) {
  assert_no_endl();
  std::getline(std::cin, str);
  while (!str.empty() && (str.back() == '\r' || str.back() == '\n'))
    str.pop_back();
  assert(len_l <= str.size());
  assert(str.size() <= len_r);
}

//等价于assert_endl
inline void readinln(){
  assert_endl();
}
