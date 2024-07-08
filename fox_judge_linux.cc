#pragma region PRE
#include <bits/stdc++.h>
#define DEBUG
using namespace std;
using ll = long long;
using ld = long double;
using pr = pair<int, int>;
#define SZ(x) (int(x.size()))
#define MS(a, b) memset(a, b, sizeof(a))
#define UNIQUE(x) sort((x).begin(), (x).end()), (x).erase(unique((x).begin(), (x).end()), (x).end())
inline void _readAt(int index)
{
    return;
}
template <typename T, typename... Args>
inline void _readAt(int index, T arr, Args... rest)
{
    cin >> arr[index];
    _readAt(index, rest...);
}

template <typename T, typename... Args>
inline void _read(int n, T arr, Args... rest)
{
    for (int i = 0; i < n; i++)
        _readAt(i, arr, rest...);
}
#pragma endregion PRE

string pname;
int st, ed;
string inSuffix;
string ansSuffix;
string outSuffix = "_foxJudgeOut.txt";

void split_line()
{
    cout << "---------------------" << endl;
}

void getYesNo(char &c)
{
    do
    {
        cin >> c;
    } while (c != 'y' && c != 'n');
}

bool isEnd;

void Test()
{
    cout << "被测试程序名" << endl;
    cin >> pname;
    cout << "测试点起始标号" << endl;
    cin >> st;
    cout << "测试点终止标号" << endl;
    cin >> ed;
    cout << "输入数据后缀" << endl;
    cin >> inSuffix;
    cout << "是否与标准答案检验(y/n)" << endl;
    char c;
    getYesNo(c);
    if (c == 'y')
    {
        cout << "标准答案后缀" << endl;
        cin >> ansSuffix;
    }
    else
    {
        cout << "输出后缀" << endl;
        cin >> outSuffix;
    }
    cout << endl;
    split_line();
    for (int i = st; i <= ed; i++)
    {
        string infile = to_string(i) + inSuffix;
        string outfile = to_string(i) + outSuffix;
        auto t1 = clock();
        system(("./" + pname + " < " + infile + " > " + outfile).data());
        auto t2 = clock();
        int checkRes = 0;
        string res = "";
        string ansfile = "";
        if (c == 'y')
        {
            ansfile = to_string(i) + ansSuffix;
            checkRes = system(("diff -Z " + outfile + " " + ansfile + " ").data());
            if (checkRes)
            {
                res = "WA";
            }
            else
            {
                res = "AC";
            }
            res = "result : " + res;
        }
        cout << "Test case " << i << " " << res << "  | used time : " << t2 - t1 << " milisec" << endl;
        if (c == 'y' && checkRes)
        {
            system(("cmp " + outfile + " " + ansfile).data());
        }
        split_line();
    }
    if (c == 'y')
    {
        cout << "是否删除临时输出文件?(ID_foxJudgeOut.txt) (y/n)" << endl;
        char d;
        getYesNo(d);
        if (d == 'y')
        {
            for (int i = st; i <= ed; i++)
            {
                string outfile = to_string(i) + outSuffix;
                system(("rm " + outfile).data());
            }
        }
        cout << "是否删除所有测试用例(ID" << inSuffix << ")/(ID" << ansSuffix << ")" << endl;
        getYesNo(d);
        if (d == 'y')
        {
            for (int i = st; i <= ed; i++)
            {
                string infile = to_string(i) + inSuffix;
                string ansfile = to_string(i) + ansSuffix;
                system(("rm " + infile).data());
                system(("rm " + ansfile).data());
            }
        }
    }
    cout << "继续测试? (y/n)" << endl;
    getYesNo(c);
    if (c == 'n')
    {
        isEnd = true;
    }
}

void __Main__()
{
    isEnd = false;
    while (!isEnd)
    {
        outSuffix = "_foxJudgeOut.txt";
        Test();
    }
    // freopen("config.ini", "r", stdin);
}

#pragma region SUF
signed main()
{
    ios ::sync_with_stdio(false);
    cin.tie(nullptr);
    __Main__();
#ifndef ONLINE_JUDGE
    // system("pause");
#endif
    return 0;
}
#pragma endregion SUF