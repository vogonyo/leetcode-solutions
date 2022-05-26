// { Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    string Reduced_String(int k,string s){
        // Your code goes here
        if(k == 1 ) return "";
        string output ="";
        
        stack<pair<char, int>> stk;
        
        for(int i =0; i< s.length(); i++){
            if(stk.empty() == true){
                stk.push(make_pair(s[i], 1));
            }
           else{
               if(s[i] == (stk.top()).first){
                   stk.push({s[i], stk.top().second + 1 });
                   if (stk.top().second == k) {
                        int x = k;
                        while (x) {
                            stk.pop();
                            x--;
                        }
                    }
                }
                   else {

                    // if character at top of stack is not
                    // same as current character push the
                    // character along with count 1 into the
                    // top of stack
                    stk.push(make_pair(s[i], 1));
                }
            }
        }    
         // then add in front of output string
        while (!stk.empty()) {
            output += stk.top().first;
            stk.pop();
        }
        reverse(output.begin(), output.end());
        return output;
    }
               };
          

// { Driver Code Starts.

int main() {
    
    
    int t;cin>>t;
    while(t--)
    {
        int k;
        cin>>k;
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.Reduced_String(k,s)<<"\n";
        
    }
    
	return 0;
}  // } Driver Code Ends