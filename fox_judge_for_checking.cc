#pragma region PRE
#include <bits/stdc++.h>
#define DEBUG
using namespace std;
using ll = long long;
using ld = long double;
using pr = pair<int, int>;
#define SZ(x) (int(x.size()))
#define MS(a, b) memset(a, b, sizeof(a))
#define UNIQUE(x)               \
  sort((x).begin(), (x).end()), \
      (x).erase(unique((x).begin(), (x).end()), (x).end())
inline void _readAt(int index) { return; }
template <typename T, typename... Args>
inline void _readAt(int index, T arr, Args... rest) {
  cin >> arr[index];
  _readAt(index, rest...);
}

template <typename T, typename... Args>
inline void _read(int n, T arr, Args... rest) {
  for (int i = 0; i < n; i++) _readAt(i, arr, rest...);
}
#pragma endregion PRE


void split_line() { cout << "---------------------" << endl; }

void getYesNo(char &c) {
  do {
    cin >> c;
  } while (c != 'y' && c != 'n');
}

bool isEnd;

void Test(string testee_prog, int test_start_idx, int test_end_idx,
          string input_suffix, string ans_suffix, string output_suffix,
          string input_prefix = "", string ans_prefix = "",
          string output_prefix = "") {
  assert(test_start_idx <= test_end_idx);

  auto get_input_file_name = [&](int i) -> string {
    return input_prefix + to_string(i) + input_suffix;
  };
  auto get_output_file_name = [&](int i) -> string {
    return output_prefix + to_string(i) + output_suffix;
  };
  auto get_ans_file_name = [&](int i) -> string {
    return ans_prefix + to_string(i) + ans_suffix;
  };

  cout << "Testee program: " << testee_prog << endl;
  split_line();
  for (int i = test_start_idx; i <= test_end_idx; i++) {
    string infile = get_input_file_name(i);
    string outfile = get_output_file_name(i);
    auto t1 = clock();
    system(("./" + testee_prog + " < " + infile + " > " + outfile).data());
    auto t2 = clock();
    int checkRes = 0;
    string ansfile = get_ans_file_name(i);
    checkRes = system(("diff -Z " + outfile + " " + ansfile + " ").data());
    string res = [&]() -> string {
      if (checkRes) {
        return "WA";
      } else {
        return "AC";
      }
    }();
    res = "result : " + res;
    cout << "Test case " << i << " " << res << "  | used time : " << t2 - t1
         << " milisec" << endl;
    if (checkRes) {
      system(("cmp " + outfile + " " + ansfile).data());
      exit(1);
    }
    system(("rm " + outfile).data());
    split_line();
  }
}

void __Main__(int argc, char **argv) {
  if (argc <= 5) {
    std::cout << "usage " << argv[0]
              << " testee_prog test_start_idx test_end_idx input_suffix "
                 "ans_suffix [input_prefix] [ans_prefix]"
              << std::endl;
    exit(1);
  }
  string testee_prog = argv[1];
  int test_start_idx = atoi(argv[2]);
  int test_end_idx = atoi(argv[3]);
  string input_suffix = argv[4];
  string ans_suffix = argv[5];
  string output_suffix = "_foxJudgeOut.txt";
  string input_prefix = "";
  string ans_prefix = "";
  if (argc > 6) input_prefix = argv[6];
  if (argc > 7) ans_prefix = argv[7];
  Test(testee_prog, test_start_idx, test_end_idx, input_suffix, ans_suffix,
       output_suffix, input_prefix, ans_prefix);
}

#pragma region SUF
signed main(int argc, char **argv) {
  ios ::sync_with_stdio(false);
  cin.tie(nullptr);
  __Main__(argc, argv);
#ifndef ONLINE_JUDGE
  // system("pause");
#endif
  return 0;
}
#pragma endregion SUF