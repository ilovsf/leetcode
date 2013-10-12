class Solution {
public:
    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        double result = 1.0;
        
        double precise = 1e-6;
        
		//f(x) = x^2 - a, 求解即为抛物线与x轴的交点，可利用曲线上的点的切线与x轴的交点来逼近
		//切线方程：f(x) - f(x0) = f'(x0)(x - x0)， 令f(x) = 0
		//交点为x0 - (x0^2 - a) / 2x0, 因此更新x1 = x0 - (x0^2 - a) / 2x0
		//前后差值为x1-x0 = (x0^2 - a) / 2x0
        while(abs(result / 2.0 - x / (2.0 * result)) > precise)
        {
            result =  result / 2.0 + x / (2.0 * result);
        }
        
        return (int)result;
    }
};