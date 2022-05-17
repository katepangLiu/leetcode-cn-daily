class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // ��vectorת��unordered_set����߲�ѯ�ٶ�
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        // ���endWordû����wordSet���֣�ֱ�ӷ���0
        if (wordSet.find(endWord) == wordSet.end()) return 0;
        // ��¼word�Ƿ���ʹ�
        unordered_map<string, int> visitMap; // <word, ��ѯ�����word·������>
        // ��ʼ������
        queue<string> que;
        que.push(beginWord);
        // ��ʼ��visitMap
        visitMap.insert(pair<string, int>(beginWord, 1));

        while(!que.empty()) {
            string word = que.front();
            que.pop();
            int path = visitMap[word]; // ���word��·������
            for (int i = 0; i < word.size(); i++) {
                string newWord = word; // ��һ���µ����滻word����Ϊÿ���û�һ����ĸ
                for (int j = 0 ; j < 26; j++) {
                    newWord[i] = j + 'a';
                    if (newWord == endWord) return path + 1; // �ҵ���end������path+1
                    // wordSet������newWord������newWordû�б����ʹ�
                    if (wordSet.find(newWord) != wordSet.end()
                            && visitMap.find(newWord) == visitMap.end()) {
                        // ��ӷ�����Ϣ
                        visitMap.insert(pair<string, int>(newWord, path + 1));
                        que.push(newWord);
                    }
                }
            }
        }
        return 0;
    }
};