/*
Quy đổi các biểu thức sang dạng BigO:
    4nlogn + 2n: O(n*logn)  ||  2^10: O(1)  ||  2^logn: O(n)
    
    3n + 100logn: O(n)      ||  4n: O(n)    ||  2^n: O(n)
    
    n^2 + 10n: O(n^2)       ||  n^3: O(2^n) ||  n*logn: O(n*logn)

Theo lý thuyết, BigO tăng dần theo:
    O(1) -> O(n) -> O(n*logn) -> O(n^2) -> O(n^3) -> O(2^n)

Sắp xếp các biểu thức theo chiều tăng dần:
    O(1): 2^10
    O(n): 2^n, 2^logn, 3n + 100logn, 4n
    O(n*logn): n*logn
    O(2^n): 4nlogn + 2n, n^3
    
Sau khi sắp xếp, ta được dãy biểu thức tăng dần như sau:
    2^10; 2^n, 2^logn, 3n + 100logn, 4n; n*logn; 4nlogn + 2n, n^3.
*/