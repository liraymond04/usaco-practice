#include <bits/stdc++.h>

using namespace std;

struct Cow {
    int x, y;
};

int main() {
    ofstream fout ("reduce.out");
    ifstream fin ("reduce.in");

    int n;
    fin >> n;

    // store all cows in Cow vector
    vector<Cow> cows(n);

    // sort X and Y values with Cow index and store as pair in separate vectors
    vector<pair<int, int> > x(n);
    vector<pair<int, int> > y(n);

    for (int i=0; i<n; i++) {
        fin >> cows[i].x >> cows[i].y;
        x[i] = {cows[i].x, i};
        y[i] = {cows[i].y, i};
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    // store current min and max values positions in sorted X and Y vectors
    int xl = 0, xr = n-1, yl = 0, yr = n-1;

    // store minimum area
    int area = INT_MAX;

    // store deleted cows
    unordered_set<int> deleted;

    // loop until 3 cows have been removed
    int cows_removed = 0;
    while (cows_removed < 3) {

        // get min and max of X and Y values from pointers
        int xmin = xl, xmax = xr, ymin = yl, ymax = yr;

        // push Cow index of min and max into set
        set<int> st;

        st.insert(x[xmin].second);
        st.insert(x[xmax].second);
        st.insert(y[ymin].second);
        st.insert(y[ymax].second);

        vector<pair<int, int> > result;

        // loop set until empty
        for (const auto &index : st) {

            xmin = xl, xmax = xr, ymin = yl, ymax = yr;

            // advance pointers with Cow index and skip when cow has already been deleted
            if (x[xl].second == index) {
                xmin++;
                while (deleted.count(x[xmin].second) > 0) {
                    xmin++;
                }
            }
            if (x[xr].second == index) {
                xmax--;
                while (deleted.count(x[xmax].second) > 0) {
                    xmax--;
                }
            }
            if (y[yl].second == index) {
                ymin++;
                while (deleted.count(y[ymin].second) > 0) {
                    ymin++;
                }
            }
            if (y[yr].second == index) {
                ymax--;
                while (deleted.count(y[ymax].second) > 0) {
                    ymax--;
                }
            }

            // calculate area from min and max values
            int cur_area = (x[xmax].first - x[xmin].first) * (y[ymax].first - y[ymin].first);

            // push result into vector
            result.push_back({cur_area, index});

            // unadvance pointers with Cow index

        // end loop
        }

        // sort vector
        sort(result.begin(), result.end());

        // update current area and get Cow index of smallest resultant area
        area = result[0].first;

        // flag cow as deleted
        deleted.insert(result[0].second);

        // advance pointers with Cow index
        if (x[xl].second == result[0].second) {
            xl++;
        }
        if (x[xr].second == result[0].second) {
            xr--;
        }
        if (y[yl].second == result[0].second) {
            yl++;
        }
        if (y[yr].second == result[0].second) {
            yr--;
        }

        // increment counter for cows removed
        cows_removed++;

    // end loop
    }

    fout << area << "\n";

    return 0;
}