class Solution {
public:
    double low_effient_pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n < 0)
            return 1.0 / pow(x, -1 * n);
        if(n == 0)
            return 1;
        if(n == 1)
            return x;
        if(n % 2 == 0)
            return pow(x, n / 2) * pow(x, n / 2);
        else
            return x * pow(x, (n - 1) / 2) * pow(x, (n - 1) / 2);
    }
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n < 0)
            return 1.0 / pow(x, -1 * n);
        if(n == 0)
            return 1;
        double *tmp_array = new double[n + 1];
        tmp_array[1] = x;
        for(int i = 2; i <= n; ++ i)
        {
            if(i % 2 == 0)
                tmp_array[i] = tmp_array[i / 2] * tmp_array[i / 2];
            else
                tmp_array[i] = tmp_array[(i - 1) / 2] * tmp_array[(i - 1) / 2] * x;
        }
        return tmp_array[n];
    }
	
    double new_pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n == 0) return 1;
        if(x == 0) return 0;
        
        int sign = 1;
        if(n < 0)
        {
            sign = -1;
            n = -n;
        }
        
        double result = 1;
        double tmp = x;
        
        while(n > 0)
        {
            if(n & 1 == 1) result *= tmp;
            
            tmp *= tmp;
            n /= 2;
        }
        
        if(sign == 1) return result;
        return 1 / result;
    }
};