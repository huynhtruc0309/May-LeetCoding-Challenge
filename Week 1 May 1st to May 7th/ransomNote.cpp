class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.size() > magazine.size())
            return false;
        if (ransomNote.size() == 0 && magazine.size() == 0)
            return true;
        
        int vocab[26] = {0};
        for (char c: magazine) 
            vocab[c-'a']++;
        
        for (char c: ransomNote) {
            if (vocab[c-'a'] == 0)
                return false;
            vocab[c-'a']--;
        }
        
        return true;
    }
};