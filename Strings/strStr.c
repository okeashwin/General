int strStr(char* haystack, char* needle) {
    if(needle==NULL || haystack==NULL)
    {
        return 0;
    }
    
    if(strlen(needle)==0)
        return 0;
    
    int currStart = 0;
    int i=0;
    int needleIter = 0;
    bool needleProcessed = false;
    
    while(haystack[i])
    {
        if(haystack[i]==needle[needleIter])
        {
            if(needleIter==0)
                currStart = i;
            needleIter++;
            if(!needle[needleIter])
            {
                // printf("Breaking from here\n");
                needleProcessed = true;
                break;
            }
            i++;
        }
        else
        {
            // printf("here for %c\n", haystack[i]);
            i = currStart + 1;
            currStart = i;
            needleIter = 0;
        }
    }
    if(needleProcessed)
        return currStart;
    else
        return -1;
}