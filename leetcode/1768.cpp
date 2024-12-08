class Solution
{
public:
    string merge(string word1,string word2)
    {
        string result;
        int a,b;
        while (a<word1.length()&&b<word2.length())
        {
            result+=word1[a];
            a++;
            result+=word2[b];
            b++;
        }
        while (a<word1.length())
        {
            result+=word1[a];
            a++;
        }
        while (b<word2.length())
        {
            result+=word2[b];
            b++;
        }
        return result;
    }
};