#include<iostream>
#include<string>

int prec(char c)
{
	switch (c)
	{
		case '+':
		case '-':
			return 1;
		case '*':
			return 2;
		case '^':
			return 3;
		default :
			return -1;
	}
	return -1;
}

bool operand(char c)
{
	if ((c >'a' && c < 'z') || c >'A' && c < 'B' || c > '0' && c < '9')
		return true;
		
	return false;

}

void convert(string str)
{
	stack<char> st;
	string result;

	for (int i = 0; i < str.length(); i++)
	{
		char c = str[i];
		if (c == '(')
		{
			st.push(c);
		} else if (operand(c) 
		{
			result += c;
		} else if ( c == ')')
		{
			while(st.top() != '(') 
			{
				result += st.top();
				st.pop();
			}
		} else if (prec(st.top()) >= prec(str[i]))
		{
			result += st.top();
			st.pop();
		}


	}
}

int main()
{
	string str="a+b*c-d"
	
	convert(str);
	return 0;
}
