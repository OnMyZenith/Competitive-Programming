#include<iostream>
#include<string>
#include<vector>

using namespace std;

bool isAlphabet(int c){
    if(c<91&&c>64) return true;// Uppercase letters
    else if(c<123&&c>96) return true;// Lowercase letters
    else return false;
}

//Takes the string and returns an int vector where even positions represent
//beginnings and odd positions represent ends of words
vector<int> wordIndicies(string str){
    vector<int> idxs = {};
    int c, l = str.length();

    for(int i =0; i<l; i++){
        c = int(str[i]);

        if(isAlphabet(c)){
            idxs.push_back(i);
            
            while(isAlphabet(c)){
                i++;
                if(i!=l) c = int(str[i]);
                else break;
            }
            idxs.push_back(i - 1);
        }
        else continue;
    }

    printf("length of string :%d\n",l);
    for(int i = 0; i<idxs.size();i++) printf("%d\t",idxs[i]);
    return idxs;
}

int main(){
    string str = ". , zvxzzwaw";
    for(int i = 0;i<str.length();i++) printf("%c",str[i]);
    printf("\n");
    vector<int> idxs = wordIndicies(str);
    string newstring = "";
    // char *newstring = (char*) malloc((str.length() + idxs.size() + 1)*sizeof(char));              //new string will have all previous chars + 2 new chars for each word, no.of words = (size of idxs)/2

    //In case the 1st word has some non alphabet chars before it
    // for(int j = 0; j < idxs[0]; j++) newstring[j] = str[j];
    for(int j = 0; j < idxs[0]; j++) newstring = newstring + str[j];

    //Handling all words
    for(int wordCount = 0; wordCount < idxs.size()/2; wordCount++){
        
        // for(int j = idxs[2*wordCount]; j < idxs[2*wordCount+1]; j++) newstring[j + 2*wordCount] = str[j + 1];
        for(int j = idxs[2*wordCount]; j < idxs[2*wordCount+1]; j++) newstring = newstring + str[j + 1];

        // newstring[idxs[2*wordCount+1] + 2*wordCount] = str[idxs[2*wordCount]];
        newstring = newstring + str[idxs[2*wordCount]];

        // newstring[idxs[2*wordCount+1] + 2*wordCount + 1] = 'a';
        // newstring[idxs[2*wordCount+1] + 2*wordCount + 2] = 'y';
        newstring = newstring + 'a';
        newstring = newstring + 'y';

        // if(wordCount<idxs.size()/2-1) for(int j = idxs[2*wordCount+1] + 1; j < idxs[2*(wordCount+1)]; j++) newstring[j + 2*(wordCount+1)] = str[j];
        if(wordCount<idxs.size()/2-1) for(int j = idxs[2*wordCount+1] + 1; j < idxs[2*(wordCount+1)]; j++) newstring = newstring + str[j];
    }

    //In case the last word has some non alphabet chars after it
    // for(int j = idxs.back() + 1; j < str.length(); j++) newstring[j + idxs.size()] = str[j];
    for(int j = idxs.back() + 1; j < str.length(); j++) newstring = newstring + str[j];

    newstring = newstring + '\0';

    // for(int i = 0;newstring[i] != '\0'; i++) printf("%c",newstring[i]);
    printf("\n");
    cout<<newstring;
    // printf("%s\n",newstring);
    // printf("%s\n",str[0]);
    // printf("%s\n",newstring[0]);
    // delete[]newstring;
    return 0;
}
