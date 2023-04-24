#include <iostream>
#include <cctype>
#include<cstring>
#include<cstdlib>
using namespace std;

const int LINELEN = 30;
const int NUM = 3;

int getProfit(int*&  cost, int***&  rev, bool*&  tmp_built, int*&  deg, int const n);
int getOutlinkSum(int**&  rev, int const degree, bool*&  tmp_built);
void handleInputLine(const char input[LINELEN], char*& fromStr, char*& toStr, int*& r);
int** addOneMoreElement(const int to, const int profit, const int n, int** arr);
int searchID(char*& name, char**& names, const int totalNameNum);
char* searchName(const int idx, char**& names, const int totalNameNum);
void sortNamesAndPrint(char**& names, const int ansNum);

//PDOGS 錯誤分析：
//RUNTIME ERROR: forgetting allocating the memory for '\0' -> char[NUM+1]
//WA: input 字串處理有問題，建議 getline() 先把整行資訊讀完再逐一切割將三個 keyword 取出來。
//此外，提醒 cost 跟航線資訊之間有一個斷行字元，如果 cost 的部分是 cin >> 而航線資訊是改用 getline，那
//cost 跟航線間的段行字元可用 git.ignore() 去忽略。

int main(int argc, char** argv){
    
    int nodeCnt = 0, flightCnt = 0;
    cin >> nodeCnt >> flightCnt;

    int *cost = new int[nodeCnt];
    int *degree = new int[nodeCnt];
    int ***rev = new int**[nodeCnt];
    char** names = new char*[nodeCnt];

    
    // input name
    for(int i = 0; i < nodeCnt; i++){
        names[i] = new char[NUM+1];
        cin >> names[i];
    }
    
    for (int i = 0; i < nodeCnt; i++)
    {
        cin >> cost[i];
        degree[i] = 0;
        rev[i] = nullptr;
    }

    cin.get();//for '\n'

    for (int i = 0; i < flightCnt; i++)
    { 
        char line[LINELEN];
        cin.getline(line, LINELEN);

        char *fromStr = new char[NUM+1];
        char *toStr = new char[NUM+1];
        int  *r = new int;

        handleInputLine(line, fromStr, toStr, r);

        int from = searchID(fromStr, names, nodeCnt);
        int to = searchID(toStr, names, nodeCnt);
        rev[from] = addOneMoreElement(to, *r, degree[from], rev[from]);
        rev[to] = addOneMoreElement(from, *r, degree[to], rev[to]);
        degree[from] += 1;        
        degree[to] += 1;

        delete [] fromStr;
        delete [] toStr;
        delete r;
    }

    
    // // check input
    // cout << "Input-----\n";
    // for (int i = 0; i < nodeCnt; i++)
    // {
    //     cout << "from: " << i << " to: ";
    //     for (int j = 0; j < degree[i]; j++)
    //     {
    //         cout << "(" << rev[i][j][0] << " ," << rev[i][j][1] << ") -> ";
    //     }
    //     cout << endl;
    // }
    
    //algorithm is the same as HW4
    bool* built = new bool[nodeCnt];
    for (int i = 0; i < nodeCnt; i++)
    {
        built[i] = 1;
    }
    bool removed_in_this_round = true;
    int opt_profit = getProfit(cost, rev, built, degree, nodeCnt);
    // cout << "Original opt_profit:" << opt_profit << endl;
    while (true)
    {
        int opt_spot = -1;
        removed_in_this_round = false;
        int oriProfitThisRnd = opt_profit;
        for (int tmp_rm_spot = 0; tmp_rm_spot < nodeCnt; tmp_rm_spot++)
        {
            if (built[tmp_rm_spot])
            {
                built[tmp_rm_spot] = 0;
            }
            else
            {
                continue;
            }

            int rm_spot_profit = 0;
            for (int i = 0; i < degree[tmp_rm_spot]; i++) //from: tmp_rm_spot
            {
                int to = rev[tmp_rm_spot][i][0];
                int r = rev[tmp_rm_spot][i][1];
                rm_spot_profit += r * built[to];
            }
            rm_spot_profit -= cost[tmp_rm_spot];
            int tmp_profit = oriProfitThisRnd - rm_spot_profit;
            if (tmp_profit > opt_profit)
            {
                opt_profit = tmp_profit;
                opt_spot = tmp_rm_spot;
                removed_in_this_round = true;
            }
            built[tmp_rm_spot] = 1;
        }
        if (removed_in_this_round)
        {
            built[opt_spot] = 0;
        }
        else
        {
            int ansNum = 0;
            for (int i = 0; i < nodeCnt; i++)
                ansNum += built[i];
            if(ansNum == 0)
            {
                cout << ";0" << endl;
                return 0;
            }
            bool first = true;
            char** ansNameArr = new char*[ansNum];
            int tmpCnt = 0;
            for (int i = 0; i < nodeCnt; i++)
            {
                if(first && built[i])
                {
                    char* tmp = searchName(i, names, nodeCnt);
                    ansNameArr[tmpCnt++] = tmp;
                    first = false;
                }
                else if(built[i])
                {
                    char* tmp = searchName(i, names, nodeCnt);
                    ansNameArr[tmpCnt++] = tmp;
                }
            }
            sortNamesAndPrint(ansNameArr, ansNum);
            cout << ";" << opt_profit << endl;
            break;
        }
    }
    return 0;
}

int getProfit(int*&  cost, int***&  rev, bool*&  tmp_built, int*&  deg, int const n)
{
    int tmp_total_rev = 0, tmp_total_cost = 0;
    for (int i = 0; i < n; i++)
    {
        tmp_total_cost += tmp_built[i] * cost[i];
    }
    for (int i = 0; i < n; i++)
    {
        tmp_total_rev += getOutlinkSum(rev[i], deg[i], tmp_built);
    }
    tmp_total_rev /= 2;
    return tmp_total_rev - tmp_total_cost;
}

int getOutlinkSum(int**&  rev, int const degree, bool*&  tmp_built)
{
    int totalRev = 0;
    for (int i = 0; i < degree; i++) //from: i
    {
        int to = rev[i][0];
        int r = rev[i][1];
        totalRev += r * tmp_built[to];
    }
    return totalRev;
}

int** addOneMoreElement(const int to, const int profit, const int n, int** arr)
{
    int** newArr = new int*[n+1];
    if (n != 0)
    {
        for (int i = 0; i < n; i++)
        {
            newArr[i] = new int[2];
            newArr[i][0] = arr[i][0];
            newArr[i][1] = arr[i][1];
        }
        for (int i = 0; i < n; i++)
        {
            delete [] arr[i];
        }
        delete [] arr;
    }
    
    newArr[n] = new int[2];
    newArr[n][0] = to;
    newArr[n][1] = profit;
    return newArr;
}

void handleInputLine(const char input[LINELEN], char*& fromStr, char*& toStr, int*& r)
{
    int quoteCnt = 0;
    int curPos = 0;
    int keywordCnt = 0;
    int sentenceCnt = strlen(input);
    char tmpProfit[3+1]; //1~100

    //handle input sentence
    for (int i = 0; i < sentenceCnt; i++)
    {
        char currentChar = input[i];
        if(currentChar == '\"')
        {
            quoteCnt++;
            continue;
        }
        if (currentChar == ' ' && (quoteCnt == 2 || quoteCnt == 4)) //space between keywords
        {
            keywordCnt = 0;
            continue;
        }
        if (currentChar != ' ' && quoteCnt < 4)
        {
            if (quoteCnt == 1) //fromStr
            {
                 fromStr[keywordCnt++] = toupper(currentChar);
                 if (keywordCnt == 3)
                    fromStr[keywordCnt] = '\0';
            }
            else if(quoteCnt == 3) //toStr
            {
                toStr[keywordCnt++] = toupper(currentChar);
                if (keywordCnt == 3)
                    toStr[keywordCnt] = '\0';
            }
        }
        if (quoteCnt == 4) //profit(third keyword)
        {
            tmpProfit[keywordCnt++] = currentChar;
        }
    }
    tmpProfit[keywordCnt] = '\0';
    *r = atoi(tmpProfit);
}

int searchID(char*& name, char**& names, const int totalNameNum)
{
    for (int i = 0; i < totalNameNum; i++)
    {
        if (names[i][0] == name[0] && names[i][1] == name[1] && names[i][2] == name[2])
            return i;
    }
    return -1;
}
char* searchName(const int idx, char**& names, const int totalNameNum)
{
    char* name = new char[NUM+1];
    name = names[idx];
    return name;
}

void swapName(char* n1, char* n2)
{
    char temp[NUM+1] = {0};
    strcpy(temp, n1);
    strcpy(n1, n2);
    strcpy(n2, temp);
}

void sortNamesAndPrint(char**& names, const int ansNum)
{
    for(int i = 0; i < ansNum; i++)
        for(int j = 0; j < ansNum - i - 1; j++)
            if(strcmp(names[j], names[j + 1]) > 0)
                swapName(names[j], names[j + 1]);
    cout << names[0];
    for(int i = 1; i < ansNum; i++)
        cout << "," << names[i];
}