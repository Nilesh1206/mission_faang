/*
This problem was asked by Dropbox.

Given a string s and a list of words words, where each word is the same length, find all starting indices of substrings in s that is a concatenation of every word in words exactly once.

For example, given s = "dogcatcatcodecatdog" and words = ["cat", "dog"], return [0, 13], since "dogcat" starts at index 0 and "catdog" starts at index 13.

Given s = "barfoobazbitbyte" and words = ["dog", "cat"], return [] since there are no substrings composed of "dog" and "cat" in s.

The order of the indices does not matter.
*/

#include<bits/stdc++.h>
using namespace std;


// Another Approach
vector<int> findSubstringIndices(string s, vector<string> words){ 
	int word_size = words[0].size(); 
	int word_count = words.size(); 
	int char_len = word_size*word_count; 
	vector<int> indices; 
	if (char_len>s.length()) 
		return indices; 
	unordered_map<string,int> words_map; 
	for (int i = 0; i < word_count; i++) 
		words_map[words[i]]++;	 
	for (int i=0; i<=s.size()-char_len; i++) { 
		unordered_map<string,int> temp_map(words_map); 
		int j = i, count=word_count; 
		while (j<i+char_len) { 
			string word = s.substr(j, word_size); 
			if (words_map.find(word)==words_map.end() || temp_map[word]==0) 
				break; 
			temp_map[word]--;
			count--; 
			j += word_size; 
		}
		if (count==0) 
			indices.push_back(i);
	}
	return indices; 
}
// Time Complexity:O(n^3)
// Space Complexity:O(words.size());



int main()
{
    string str;
    cin>>str;

    int n;
    cin>>n;
    vector<string>words(n);
    for(int i=0;i<n;i++) cin>>words[i];
    vector<int>ans;
    int word_size=words[0].size();
    int len=word_size*n;
    string temp="";
    for(auto it:words) temp+=it;
    sort(temp.begin(),temp.end());
    for(int i=0;i<=str.size()-len;i++)
    {
        string s=str.substr(i,len);
        // cout<<s<<endl;
        sort(s.begin(),s.end());
        if(s==temp)
        {
            ans.push_back(i);
        }
    }
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
    return 0;
}
// Time Complexity:O(n^2logn)
// Space Complexity:O(word.size()*words[0].length())