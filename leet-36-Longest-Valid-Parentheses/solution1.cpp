/*misunderstanding about the problem*/

/*class Solution {
public:
    int longestValidParentheses(string s) {
        int manx_len=0;
		stack<char> left;

		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='(') 
			{
				left.push(s[i]);
			}
			else
			{
				if(s[i]==')' && !left.empty())
				{
					left.pop();
					manx_len+=2;
				}
			}
		}
		return manx_len;
        
    }
};*/

class Solution {
public:
    int longestValidParentheses(string s) {
    	int max_len=0,last=-1;
    	stack<int> left;

    	for(int i=0;i<s.size();i++)
    	{
    		if(s[i]=='(')
    		{
    			left.push(i);
    		}
    		else
    		{
    			if(left.empty())
    			{
    				last=i;
    			}
    			else
    			{
    				left.pop(); //弹出
    				if(left.empty())
    					max_len=max(max_len,i-last);
    				else
    					max_len=max(max_len,i-left.top());
    			}
    		}
    	}
    	return max_len;
        
    }
};