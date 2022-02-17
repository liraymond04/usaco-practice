#include <bits/stdc++.h>

using namespace std;

struct Store {
  int capacity;
  int price;
};

bool storeSort(const Store &lhs, const Store &rhs) {
  return lhs.price > rhs.price;
}

int main() {
  freopen("rental.in", "r", stdin);
  freopen("rental.out", "w", stdout);

  int n, m, r;
  cin >> n >> m >> r;

  vector<int> cows;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    cows.push_back(num);
  }

  vector<Store> stores;
  for (int i = 0; i < m; i++) {
    Store s;
    cin >> s.capacity >> s.price;
    stores.push_back(s);
  }

  vector<int> rents;
  for (int i = 0; i < r; i++) {
    int num;
    cin >> num;
    rents.push_back(num);
  }

  sort(cows.begin(), cows.end(), greater<int>());
  sort(stores.begin(), stores.end(), storeSort);
  sort(rents.begin(), rents.end(), greater<int>());

  int rindex = 0, rent_cow_index = n - 1, milk_cow_index = 0, store_index = 0;
  int ans = 0;
  while (milk_cow_index <= rent_cow_index) {
    int rent = 0, price = 0;
    if (rindex < rents.size()) {
      rent = rents[rindex];
    }

    int sindex = store_index, store_cap = 0;
    if (sindex < stores.size()) {
      int cow_amnt = cows[milk_cow_index];
      while (cow_amnt > 0) {
        if (cow_amnt < stores[sindex].capacity) {
          price += cow_amnt * stores[sindex].price;
          store_cap = stores[sindex].capacity - cow_amnt;
          cow_amnt = 0;
        } else {
          price += stores[sindex].capacity * stores[sindex].price;
          cow_amnt -= stores[sindex].capacity;
          sindex++;
        }
      }
    }

    if (rent == 0 && price == 0) {
      break;
    }

    if (rent > price) {
      ans += rent;
      rindex++;
      rent_cow_index--;
    } else {
      ans += price;
      milk_cow_index++;
      store_index = sindex;
      if (store_cap > 0) {
        stores[sindex].capacity = store_cap;
      }
    }
  }

  cout << ans;

  return 0;
}
