class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int ans = 0;
        ans += (C - A) * (D - B);
        ans += (G - E) * (H - F);
        if(B >= H || F >= D || C <= E || G <= A)
            return ans;
        int xv[4] = {A, E, C, G};
        sort(xv, xv+4);
        int yv[4] = {F, B, H, D};
        sort(yv, yv+4);
        return ans - (xv[2] - xv[1]) * (yv[2] - yv[1]);
    }
};
