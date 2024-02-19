#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace chrono;

void solve() {
  
}

int main()
{
    auto start = high_resolution_clock::now();
    
    solve();
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: " << duration.count()/1000.0 << " ms" << endl;
    /* ms: Miliseconds, 1s = 1000ms, 1ms = 1000 microseconds */
    return 0;
}
