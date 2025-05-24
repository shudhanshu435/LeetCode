class Solution:
    def findWordsContaining(self, words: List[str], x: str) -> List[int]:
        i=0 
        lis=[]
        for w in words:
            if x in w:
                lis.append(i)
            i+=1
        return lis