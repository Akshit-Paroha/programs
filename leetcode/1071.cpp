class Solution {
public:
    string gcdOfStrings(string str1, string str2) 
    {
        int b=0;
        string result ="";
        int A=str1.length();
        int B=str2.length();
        if(B>A)return result;
        for(int i=0;i<A;i++)
        {
            
            if(str1[i]==str2[b])
            {
                b++;
                result+=str1[i];
            }    
            if(B==b||str2[b]==str2[0])
            {
                return result;
            }
        }
        return result;
    }
};