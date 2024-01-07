class Solution {
    public:
        bool chk(string s){
            int cnt=0;string n="";int point=0;
            for(int i=0; i<s.size(); i++){
                if(s[i]=='.'){point++;
                    if(n.size()==0)return 0; 
                    if(n.find('0')==0 && n.size()>1)
                    return false;
                    int data=stoi(n);
                    if(data>=0 and data<=255){
                        
                    }else{
                        return false;
                    }
                    n="";
                }else{
                    if((s[i]-'0')>=0 && (s[i]-'0')<=9){
                    n+=s[i];
                    }else{
                        return 0; 
                    }
                }
                
                
            }
              if(n.size()==0)return 0; 
                    if(n.find('0')==0 && n.size()>1)
                    return false;
                    int data=stoi(n);
                    if(data>=0 and data<=255){
                        
                    }else{
                        return false;
                    }
            if(point!=3)return 0; 
            return 1;
            
        }
        int isValid(string s) {
            return chk(s);
        }
};