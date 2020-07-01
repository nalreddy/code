#!/usr/bin/python3.6
import json 

# {key:value mapping} 
def ad(x , y):
	a ={"name":"John", 
		"age":31, 
		"Salary":25000} 

# conversion to JSON done by dumps() function 
	b = json.dumps(a) 

# printing the output 
	return b 
