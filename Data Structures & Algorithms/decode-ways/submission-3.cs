public class Solution 
{
    Dictionary<int, int> dict = new();
    public int dfs(string s, int i)
    {
        if (dict.ContainsKey(i)) return dict[i];
        if (i >= s.Length) return 1;
        if (s[i] == '0') return 0;

        int result = dfs(s, i + 1);

        if (i + 1 < s.Length) 
        {
            if (s[i] == '1' || s[i] == '2' && s[i+1] < '7')
            {
                result += dfs(s, i + 2);
            }
        }

        dict.Add(i, result);
        return result;
    }

    public int NumDecodings(string s) 
    {
        return dfs(s, 0);
    }
}
