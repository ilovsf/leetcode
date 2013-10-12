class Solution {
public:
    string addBinary_using_bitset(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int size = a.size() > b.size() ? a.size() + 1 : b.size() + 1;
        bitset<size> a_bit(a);
        bitset<size> b_bit(b);
        bitset<size> result;
        
        bool carry = false;
        for(int i = 0; i < size; ++ i)
        {
            result[i] = a_bit[i] ^ b_bit[i] ^ carry;
            if(carry)
            {
                carry = a_bit[i] | b_bit[i];
            }
            else
            {
                carry = a_bit[i] & b_bit[i];
            }
        }
        
        return result;
    }
	
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int size;
        string longer, shorter;
        
        if(a.size() > b.size())
        {
            size = a.size() + 1;
            longer = a;
            shorter = b;
        }
        else
        {
            size = b.size() + 1;
            longer = b;
            shorter = a;
        }
        
        string result(size, '0');
        bool carry = false;
        
        size --;
        int i = longer.size() - 1, j = shorter.size() - 1;
        for(; j > -1; -- i, -- j)
        {
            bool a_bit = (longer[i] == '1');
            bool b_bit = (shorter[j] == '1');
            bool multiply = a_bit ^ b_bit ^ carry;
            
            if(multiply)
            {
                result[size] = '1';
            }
            else
            {
                result[size] = '0';
            }
            size --;
            
            if(carry)
            {
                carry = a_bit | b_bit;
            }
            else
            {
                carry = a_bit & b_bit;
            }
        }
  
        while(i > -1)
        {
            bool a_bit = (longer[i --] == '1');
            bool multiply = a_bit ^ carry;
            
            if(multiply)
            {
                result[size] = '1';
            }
            else
            {
                result[size] = '0';
            }
            size --;
            
            carry = carry & a_bit;
        }
        
        if(carry)
        {
            result[size] = '1';   
        }
        else
        {
            result[size] = '0';
        }
        
        if(result[0] == '0')
        {
            return result.substr(1);
        }
        return result;
    }
};