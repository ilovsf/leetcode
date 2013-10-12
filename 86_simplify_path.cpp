class Solution {
public:
    string simplifyPath(string path) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        deque<string> path_stack;

        int first = 0; 
        int size = path.size();
        while(first < size)
        {
            int second = first + 1;
            while(second < size && path.at(second) != '/') ++ second;
            
            if(second - first > 1)
            {
                string dir = path.substr(first+1, second - first - 1);
                if(dir == "..")
                {
                    if(!path_stack.empty()) path_stack.pop_back();
                }
                else if(dir != ".")
                {
                    path_stack.push_back(dir);
                }
            }
            
            first = second;
        }
        
        stringstream oss;
        while(!path_stack.empty())
        {
            oss << '/';
            oss << path_stack.front();
            path_stack.pop_front();
        }
        
        string result = oss.str();
        
        if(result.size() == 0) return "/";  
        return result;
    }
};