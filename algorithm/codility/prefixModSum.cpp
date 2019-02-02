//not sure if its fully tested but got 100% on codility
int solution(int A, int B, int K) {
    if(A == B) return (A % K) == 0 ? 1 : 0;
    if (B < K) return 0;
    while(A % K != 0 && A < B) {
        A++;
    }
    int diff = B-A;
    
    int r = diff / K;
    return r + 1;
}
