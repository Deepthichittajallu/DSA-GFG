class Solution {
  public:
bool isValid(const string &s)
{
    if (s.size() > 1 && s[0] == '0')
    {
        return false;
    }

    int val = stoi(s);
    return val <= 255;
}
void generateIpRec(const string &s, int index, string curr, int cnt, vector<string> &res)
{

    if (index >= s.size())
        return;
    if (cnt == 3)
    {
        string last = s.substr(index);
        if (last.size() <= 3 && isValid(last))
            res.push_back(curr + last);
        return;
    }

    string segment = "";
    for (int i = index; i < min(index + 3, (int)s.size()); i++)
    {
        segment += s[i];

        if (isValid(segment))
        {
            generateIpRec(s, i + 1, curr + segment + ".", cnt + 1, res);
        }
    }
}

    vector<string> generateIp(string &s) {
        // code here
        vector<string> res;
    generateIpRec(s, 0, "", 0, res);
    return res;
    }
};