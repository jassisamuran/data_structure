#include<iostream>
using namespace std;
#include<vector>
class Node{
public:
    bool isEndOfWord;
    Node* children[26];
    Node(){
      isEndOfWord=false;
//      for(int i=0; i<26; i++){
  //       children[i]=nullptr;
    //  }
    }
};
class TrieNode{
private:
    Node* root;
public:
    TrieNode(){
        root=new Node();
    }
    void insert(string word){
      Node *current=root;
      for(char c:word){
          int index=c-'a';
          if(current->children[index]==nullptr)current->children[index]=new Node();

          current=current->children[index];
      }
      current->isEndOfWord=true;
    }
   bool search(string word){
     Node *cur=root;
     for(char c:word){
      int idx=c-'a';
      if(cur->children[idx]==NULL)return false;
      cur=cur->children[idx];
     }
    return cur->isEndOfWord;
   }
};
int main(){
TrieNode tr;
vector<string>v={"one","second","third"};
for(int i=0; i<v.size(); i++){
    tr.insert(v[i]);
}
  cout<<tr.search("one")<<endl;
}

