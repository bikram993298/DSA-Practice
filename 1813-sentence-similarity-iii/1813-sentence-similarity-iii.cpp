class Solution {
public:
   vector<string> getWords(string s) {

        vector<string> words;
        stringstream ss(s);
        string word;

        while(ss >> word) {
            words.push_back(word);
        }

        return words;
    }
    bool areSentencesSimilar(string sentence1, string sentence2) {
     
        vector<string> w1 = getWords(sentence1);
        vector<string> w2 = getWords(sentence2);


         if(w2.size() > w1.size())
            swap(w1, w2);
        int n=w1.size();
        int l=0;
        int r=n-1;
        int m=0;
    
      
        
// prefix match
        while(l<w1.size()&& m<w2.size()){
            if(w1[l]==w2[m]){
                l++;
                m++;

            }else{
                break;
            }
           
        }

        //siffix mathc
      
        int i = w1.size() - 1;
        int j = w2.size() - 1;
        //"My name is Haley", sentence2 = "My name name Haley"
        // m=is in name(first)
         // if you dont use i>=l thne name haley will be also mathced so wrong ,,so main target all elemnt of smaller substring is matched end to end
        while(i >= l && j >= m) {
            if(w1[i] == w2[j]) {
                i--;
                j--;
            } else {
                break;
            }
        }

        return j<m;
       
    }
};
// main idea is too mathc prefic from forwarn iff mistmacth suffis form backwaRD IF MATCH form prefix is m and mathc form suffixj if j<m then all mismatched