#include <iostream>
using namespace std;

const int ASSIGNMENT_CNT_MAX = 10;
const int GRADE_CNT_MAX = 50; 

int highGradeCnt(int, int, int []);
int mostHighGrades(int, int, int, int [][GRADE_CNT_MAX]);

int main()
{
  int assignmentCnt = 0, gradeCnt = 0, threshold = 0;
  int grades[ASSIGNMENT_CNT_MAX][GRADE_CNT_MAX] = {0};
  
  cin >> assignmentCnt >> gradeCnt >> threshold;
  for(int i = 0; i < assignmentCnt; i++)
  {
    for(int j = 0; j < gradeCnt; j++)
      cin >> grades[i][j];
  }
    
  cout << mostHighGrades(threshold, assignmentCnt, gradeCnt, grades);

  return 0;
}

int highGradeCnt(int threshold, int gradeCnt, int grades[])
{
  int hgc = 0;
  for(int i = 0; i < gradeCnt; i++)
  {
    if(grades[i] >= threshold)
      hgc++;
  }
  return hgc;
}

int mostHighGrades(int threshold, int assignmentCnt, int gradeCnt, int grades[][50])
{
  int mhg = 0;
  int mhgCnt = 0;
  
  for(int i = 0; i < assignmentCnt; i++)
  {
    int hgc = highGradeCnt(threshold, gradeCnt, grades[i]);
    if(hgc > mhgCnt)
    {
      mhgCnt = hgc;
      mhg = i + 1;
    }
  }
  return mhg;
}

