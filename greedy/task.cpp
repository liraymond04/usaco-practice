#include <iostream>
#include <vector>
#include <algorithm>
using namespace  std;

struct Task {
   Task(int s, int f) {
     start = s;
     finish = f;
   }
   int start;
   int finish;
};
bool sortByStart (Task t1, Task t2) {
  return (t1.start < t2.start);
}

bool sortByStartReverse (Task t1, Task t2) {
  return (t1.start > t2.start);
}

bool sortByFinish (Task t1, Task t2) {
  return (t1.finish < t2.finish);
}

bool sortByInterval (Task t1, Task t2) {
  return (t1.finish - t1.start) < (t2.finish - t2.start);
}


int main() {
  vector <Task> tasks;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
   Task t(0, 0);
   cin >> t.start>> t.finish;
   tasks.push_back(t);
  }

  sort(tasks.begin(), tasks.end(), sortByFinish);

  vector <Task> result;
 
  //put code here
  int prev = 0;
  for (int i=0; i<n; i++) {
      if (tasks[i].start >= prev) {
          result.push_back(tasks[i]);
          prev = tasks[i].finish;
      }
  }

  cout << "total tasks: " << result.size() << "\n";
  for (size_t i  =0; i < result.size(); i++) {
    cout << result[i].start << ", " << result[i].finish << endl;
  }

 return 0;
}
