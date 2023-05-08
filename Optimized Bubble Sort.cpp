#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> A = {7,8,1,3,5,4,3,2};
    int n = A.size();
    bool swapped;
    
    do {
        swapped = false;
        for (int i = 1; i <=n; i++) {
            if (A[i - 1] > A[i]) {
                int temp = A[i];
                A[i] = A[i - 1];
                A[i - 1] = temp;
                swapped = true;
                int newLimit =A.size() -1;
                n = newLimit;
            }
        }
        printf(" ");
    } while (swapped);

    for (int j = 0; j <=n; j++) {
        cout << A[j] <<" ";
    }

    return 0;
}
