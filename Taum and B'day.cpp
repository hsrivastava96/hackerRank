long taumBday(int b, int w, int bc, int wc, int z) 
{
    long total=0, tempCost=0, lb=b, lw=w, lbc=bc, lwc=wc, lz=z;
    if(lbc==lwc)
        total = lbc*lb + lwc*lw;
    else if(lbc<lwc)
    {
        tempCost = lbc+lz;
        if(lwc<tempCost)
            tempCost = lwc;
        total = lbc*lb + tempCost*lw;
    }
    else
    {
        tempCost = lwc+lz;
        if(lbc<tempCost)
            tempCost = lbc;
        total = lwc*lw + tempCost*lb;
    }
    return total;
}
