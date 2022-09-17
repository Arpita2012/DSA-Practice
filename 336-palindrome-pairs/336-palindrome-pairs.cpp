/*class Solution {
public:
    
//     bool ispallindrome(string w){
        
//         int l = w.length();
        
//         for(int i=0 ; i< (l/2) ; i++){
//             if(w[i]!=w[l-i-1]){
//                 return false;
//             }
//         }
        
//         return true;
        
//     }
    
    
       bool ispallindrome(string w, int left, int right){
        
       
        
        while( left< right ){
            if(w[left]!=w[right]){
                return false;
            }
            left++;
            right--;
        }
        
        return true;
        
    }
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        
        map<string,int> M;
        
        vector<vector<int>> ANS;
        
        
        int N = words.size();
        
        for(int i=0 ; i< N ; i++){
            M[words[i]] = i;
        }
        
        unordered_map<string_view, int> reversedWordToIndex;
        vector<string> reversedWords(N);
        for (int i = 0; i < N; i++) {
            string s = words[i];
            std::reverse(s.begin(), s.end());
            reversedWords[i] = s;
            reversedWordToIndex[reversedWords[i]] = i;
        }
        

        
        
        //Empty string case
       if(M.find("")!=M.end()){
           
            int idx_empty = M[""];
            for(int i=0; i<N ; i++){
                
                if(ispallindrome(words[i],0,words[i].length()-1) and i!=idx_empty){
                    ANS.emplace_back(vector<int>{i,idx_empty});
                    ANS.emplace_back(vector<int>{idx_empty,i});   
                }
            }      
       }
        
        // reflection case
        for(int i=0; i<N ;i++){
            //string rev_word = words[i];
            //reverse(rev_word.begin(), rev_word.end());
            
            //reversedWordToIndex
            
            if((M.find(reversedWords[i])!=M.end() ) and 
              M[words[i]]!=M[reversedWords[i]]){
                 ANS.emplace_back(vector<int>{M[words[i]],M[reversedWords[i]]});
                 //;  
                
                
            }
        }
        
        
        //tricky case
        
        for(int i=0 ; i<N ; i++){
            
            string &w = words[i];
            
            if(w.length()==0){
                continue;
            }
            int len = w.length();
          
            
            for(int cut=1; cut<len; cut++){
                

                
                const string_view left(w.c_str(), cut);
                const string_view right(w.c_str() + cut);
                
                //cout<<"left : "<<left<< " | right "<<right<<endl;


                
                // if(left.length()==0 or right.length()==0){
                //     break;
                // }
                if(ispallindrome(w,0,cut-1)){ //left pallindrome

                    
                    
                    if(reversedWordToIndex.find(right)!=reversedWordToIndex.end()){
                        ANS.emplace_back(
                            vector<int>{ reversedWordToIndex[right] , M[w] });
                    }
                    
                    
                    
                    
                }
                if(ispallindrome(w,cut,len-1)){
                    

                      if(reversedWordToIndex.find(left)!=reversedWordToIndex.end()){
                        ANS.emplace_back(
                            vector<int>{ M[w], reversedWordToIndex[left]  });
                    }
                    
                }
                
                
            }
            
        }
        return ANS;
        
    }
   
};*/


class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        const int wordSize = words.size();
        vector<string> reversedWords(wordSize);
        for (int i = 0; i < wordSize; i++) {
            string s = words[i];
            std::reverse(s.begin(), s.end());
            reversedWords[i] = s;
            reversedWordToIndex[reversedWords[i]] = i;
        }
        
        // "" matches with every word if the word is palindrome
        const auto itEmpty = reversedWordToIndex.find("");
        if (itEmpty != reversedWordToIndex.end()) {
            const int emptyIndex = itEmpty->second;
            for (int i = 0; i < wordSize; i++) {
                if (i == emptyIndex) continue;
                const string &word = words[i];
                const int wordLen = word.length();
                if (!isPalindrome(word, 0, wordLen - 1)) continue;
                results.emplace_back(vector<int>{emptyIndex, i});
                results.emplace_back(vector<int>{i, emptyIndex});
            }
        }
        
        for (int i = 0; i < wordSize; i++) {
            const string &word = words[i];
            const int wordLen = word.length();
            
            // Check if substr(word, sublen) from left == reversedWord
            for (int sublen = 1; sublen < wordLen; sublen++) {
                const int matchIndex = findLeftSubstrMatchIndex(word, sublen);
                if (matchIndex < 0 || matchIndex == i) continue;
                results.emplace_back(vector<int>{i, matchIndex});
            }
            
            // Check if substr(word, sublen) from right == reversedWord
            for (int sublen = 1; sublen < wordLen; sublen++) {
                const int matchIndex = findRightSubstrMatchIndex(word, sublen);
                if (matchIndex < 0 || matchIndex == i) continue;
                results.emplace_back(vector<int>{matchIndex, i});
            }
            
            // Check if word == reversedWord
            const int matchIndex = findLeftSubstrMatchIndex(word, wordLen);
            if (matchIndex < 0 || matchIndex >= i) continue; // matchIndex >= i is to avoid duplicate pairs, matchIndex <= i would also be okay
            results.emplace_back(vector<int>{i, matchIndex});
            results.emplace_back(vector<int>{matchIndex, i});
        }
        return results;
    }
    
    // words=["batx", "tab"]
    // reversed=["xtab", "bat"]
    // substr(word="batx", sublen=3) = "bat"
    int findLeftSubstrMatchIndex(const string &word, const int sublen) {
        const string_view part(word.c_str(), sublen);
        const auto it = reversedWordToIndex.find(part);
        if (it == reversedWordToIndex.end()) return -1;
        if (isPalindrome(word, sublen, word.length() - 1)) return it->second;
        return -1;
    }
    
    // words=["tabx", "bat"]
    // reversed=["xtab", "tab"]
    // substr(word="xtab", sublen=3) = "tab"
    int findRightSubstrMatchIndex(const string &word, const int sublen) {
        const string_view part(word.c_str() + word.length() - sublen);
        const auto it = reversedWordToIndex.find(part);
        if (it == reversedWordToIndex.end()) return -1;
        if (isPalindrome(word, 0, word.length() - sublen - 1)) return it->second;
        return -1;
    }
    
    bool isPalindrome(const string &word, int left, int right) {
        while (left < right && word[left] == word[right]) {
            left++;
            right--;
        }
        return left >= right;
    }
    
    unordered_map<string_view, int> reversedWordToIndex;
    vector<vector<int>> results;
};