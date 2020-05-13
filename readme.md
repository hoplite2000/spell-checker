Spell-Checker
	
This repository contains a spell checking tool whose main code that performs spell checking in the back end is written in c++ and the front end contains a GUI written in python-tkinter. This tool is basically a c++ code embeded inside python code.

In order to build this spell checking tool I used two fundamental concepts: the Soundex algorithm and Levenshtein Distance.
	
Soundex algorithm: Soundex is a phonetic algorithm used to index words according to the sounds used to pronounce them in English. The goal is to obtain an identical representation for homophones. As a reminder, homophones are words with the same phonetic pronunciation but can be spelled slightly differently. Soundex mainly encodes consonants. Thus, a vowel will not be encoded unless it is the first letter of the word. In concrete terms, Soundex will produce a code for a word that consists of a letter followed by three digital digits. The letter is simply the first letter of the word used at the entrance of the Soundex. The next three digits correspond to the encoding of the remaining consonants.
    
Levenshtein Distance: The Levenshtein Distance is a string metric for measuring the difference between two sequences. Informally, the Levenshtein Distance between two words is the minimum number of single-character edits (insertions, deletions or substitutions) required to change one word into the other.
    	
In this repository I created a dictionary of homophones indexed by the Soundex code of words. To do this, I made a dictionary of the most common English words. words.txt and words_alpha.txt files are used to create the dictionary. Those files contain 350K+ English words. In order to create the dictionary of homophones, I will read each line of the words_alpha.txt file and then calculate the Soundex code of the word. Then, I will add this word in a Map that can contain multiple values for each key. Then, I will search for the homophones of this word by calculating its Soundex code. Finally, to prun and obtain relevant results, I will only keep homophones with a Levenshtein Distance strictly less than 3 with our word to correct and if the word already exists in the dictionary it dispalys that the word is valid (This threshold of 3 is purely arbitrary and can be lower or higher depending on the number of results you want to obtain). Finally, for proposing better results to the user, I sort the words got by Levenshtein Distance in ascending order and diplay the output.

Requirements:
1. g++ compiler
2. python-tkinter
    	
	
	
