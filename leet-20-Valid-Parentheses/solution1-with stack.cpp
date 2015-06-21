/*solution 1 solid. using match to return the function*/
class  Solution
{
public:
	char match(char c)
	{
		if(c==')') return '(';
		if(c==']') return '[';
		if(c=='}') return '{';
	}

	bool isValid(string const& s)
	{
		string<char> stk;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='(' || s[i]=='[' || s[i]=='{')
				stk.push(s[i]);
			else
			{
				if(stk.empty() || stk.top()!=match(s[i]))
					return false;
				stk.pop();
			}
		}

		if(stk.empty()) return true;
	}
};

/*solution 2 simplify the match,using string*/
class Solution {
public:
    bool isValid(string s) {
        string left="([{";
        string right=")]}";

		stack<char> stk;

		for(int i=0;i<s.size();i++)
		{
			if(left.find(s[i])!=string::npos)
				stk.push(s[i]);
			else
			{
				if(stk.empty() || stk.top()!=left[right.find(s[i])])
					return false;
				stk.pop();
			}
		}
		return stk.empty();
    }
};