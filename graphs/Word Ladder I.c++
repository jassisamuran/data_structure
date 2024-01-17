class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        if(startWord==targetWord)return 0;
        queue<string>q;
        q.push(startWord);
        
        int time=0;
        set<string>dic;
        for(auto i:wordList)dic.insert(i);
        if(dic.find(targetWord)==dic.end())return 0; 
        
        while(!q.empty()){
             time++;
            int size=q.size();
            for(int i=0;i<size; i++){
                string top=q.front();q.pop();
                for(int j=0; j<startWord.size(); j++){
                    char temp=top[j];
                    for(char c='a'; c<='z'; c++){
                        top[j]=c;
                        if(top==targetWord)return time+1;
                        if(dic.find(top)==dic.end())continue;
                        dic.erase(top);
                        q.push(top);
                    }
                    top[j]=temp;
                }
            }
           
            
        }
        return 0; 
    }
};
