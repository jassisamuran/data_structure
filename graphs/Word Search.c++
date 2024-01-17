class Solution {
public:
    int search(int i,int j,int len,string word,vector<vector<char>>&board){
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() ||board[i][j]=='*')return 0;
        if(board[i][j]!=word[len])return 0;
        if(len==word.size()-1)return 1;
        char tmp=board[i][j];
        board[i][j]='*';
        int a=search(i+1,j,len+1,word,board);
        int b=search(i,j+1,len+1,word,board);
        int c=search(i-1,j,len+1,word,board);
        int d=search(i,j-1,len+1,word,board);
        board[i][j]=tmp;
        return a||b||c||d;
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
       for(int i=0; i<board.size(); i++){
           for(int j=0; j<board[0].size(); j++){
               if(search(i,j,0,word,board))return 1;
           }
       }
       return 0;
    }
};
// time complexity o(n*m*4^L) n is no of rows. m is no of columns. L is length of word 
// space complexity o(1)