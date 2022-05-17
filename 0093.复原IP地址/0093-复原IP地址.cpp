class Solution {
private:
    vector<string> ans;
    vector<string> temp;
public:
    vector<string> restoreIpAddresses(string s) {
        dfs(s,0);
        return ans;
    }

    void dfs(string s,int start) {
        if (start == s.size() && temp.size() == 4) {//temp����4����s����
           string str = temp[0];
           for (int i = 0;i<3;++i) {
               str = str + '.' + temp[i+1];
           }
           ans.push_back(str);//ans�б���һ�ֿ��з���
           return; 
        }
        else if (start < s.size() && temp.size() == 4) {//s���ַ�û����
            return;
        }
        for (int len = 1;len <= 3;len++) {//temp��ÿһ��stringֻ�ܴ泤��1~3���ַ���
            if (start >= s.size()) //ע����>=��������s������
                return;
            if (len != 1 && s[start] == '0') //0x,00x�Ƿ�
                return;
            string str = s.substr(start,len);//�и��ַ���
            if (len == 3 && atoi(str.c_str()) > 255) //���ܴ���255
                return;
            temp.push_back(str);
            dfs(s,start+len);
            temp.pop_back();
        }
    }
};