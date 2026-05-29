long long factorial (int n)
{
    long long resultado;
    
    if (n<0)
    {
        cout << "No existe el factorial de ese valor";
    }
    
    else
    {
        if(n == 0)
        {
            resultado = 1;
        }
        
        else
            resultado = n * factorial (n-1);
    }
    
}