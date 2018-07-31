1.	#include <iostream>  
2.	using namespace std;  
3.	long long fact(int n) {         //阶乘  
4.	    long long ans=1;  
5.	    if (n == 1 || n==0 ) {  
6.	        return 1;  
7.	    }  
8.	    ans = n * fact(n - 1);  
9.	    return ans;  
10.	}  
11.	long long c(int n, int m) {  
12.	    long long ans_1;  
13.	    ans_1 = (fact(n)) / (fact(n - m) * fact(m));    //组合数（非模板，本题定制）  
14.	    return ans_1;  
15.	}  
16.	  
17.	long long f[34];  
18.	int main() {  
19.	    int t;  
20.	    cin >> t ;  
21.	    f[0] = 1, f[1] = 0, f[2] = 1;  
22.	    for (int i = 3; i <= 30; ++i) {  
23.	        f[i] = (i - 1)*(f[i - 1] + f[i - 2]);   //错排打表  
24.	    }  
25.	    while (t--) {  
26.	        int n, m;  
27.	        cin >> n >> m;  
28.	        cout << "" << c(n, m)*f[m] << endl;  
29.	    }  
30.	    return 0;  
31.	}
