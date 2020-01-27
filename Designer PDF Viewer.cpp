int designerPdfViewer(vector<int> h, string word) 
{
    int sz = 0, as = 0, ht = -1, w = 0;
    for(int i = 0; word[i]!='\0'; i++)
    {
        as = word[i] - 97;
        if(h[as] > ht)
            ht = h[as];
        w++;
    }
    return ht*w;
}
